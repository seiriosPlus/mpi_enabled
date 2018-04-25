//
// Created by tangwei12 on 2018/4/19.
//

#include <iostream>
#include <sstream>
#include <thread>
#include <grpc++/grpc++.h>
#include <mpi.h>

#include "mpi.grpc.pb.h"
#include "mpi_client.h"
#include "var.h"

using grpc::Status;
using grpc::ServerContext;
using grpc::ClientContext;

using mpis::RequestContext;
using mpis::ReplyContext;
using mpis::MPIService;


/*************************************** CLIENT *******************************************/

Var geneVar(std::string grpc, std::string name, std::string content, int tag) {
    content = content + std::to_string(tag);
    name = name + std::to_string(tag);

    Var var;
    var.grpc = grpc;
    var.value = content;
    var.length = content.length();
    var.tag = tag;
    var.name = name;

    return var;
}

void MPIAsyncSendVars(std::shared_ptr<grpc::Channel> channel, int src, const Var &var) {
    std::cout << "[MPIClient " << src << "]: async sending " << var.name << std::endl;
    MPIClient mpiClient(channel, src);
    mpiClient.SendRequest(var);
}

void RunClient(const int src, const std::string grpc) {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("0.0.0.0:50051", grpc::InsecureChannelCredentials());

    int tag_base = 100;
    std::string name = "batch_norm@GREND_tag_";
    std::string content = "1:2:3:4:5:5::_tag_";

    for (int i = 1; i < 100; ++i) {
        int tag = tag_base + i;
        Var var = geneVar(grpc, name, content, tag);
        std::thread mpi_send_trhead(MPIAsyncSendVars, channel, src, var);
        mpi_send_trhead.detach();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::cout << "[MPIClient " << src << "]: send over" << std::endl;
}

/*************************************** SERVER *******************************************/

void MPIIrecvProcess(void *buf, int count, int source, int tag) {
    MPI_Request request;
    MPI_Status status;

    MPI_Irecv(buf, count, MPI_CHAR, source, tag, MPI_COMM_WORLD, &request);
    MPI_Wait(&request, &status);
}

void MPIAsyncRecvVars(const RequestContext &request, const ReplyContext &response) {
    std::stringstream id;
    id << std::this_thread::get_id();
    std::string header = "[MPIReceiveVars " + id.str() + "] ";

    std::cout << header << "source: " << request.src() << " tag: " << request.tag() << " var: " << request.var_name()
              << std::endl;

    char bus[request.length()];
    std::cout << header << "receive mpi data ing" << std::endl;
    MPIIrecvProcess(&bus, request.length(), request.src(), request.tag());
    std::cout << header << "receive mpi data is: " << bus << std::endl;
}

class MPIServiceImpl final : public mpis::MPIService::Service {
public:
    MPIServiceImpl(int dst) {
        this->dst = dst;
    }

    Status ISendRequest(::grpc::ServerContext *context, const ::mpis::RequestContext *request,
                        ::mpis::ReplyContext *response) override {

        std::cout << "[MPIServer " << this->dst << "]: receive: "
                  << " src : " << request->src() << " name: " << request->var_name() << std::endl;

        std::thread mpi_receive_thread(MPIAsyncRecvVars, *request, *response);
        mpi_receive_thread.detach();

        response->set_dst(this->dst);
        return Status::OK;
    };

private:
    int dst;
};

void RunServer(int dst) {
    std::string server_address("0.0.0.0:50051");
    MPIServiceImpl service(dst);

    grpc::ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "[MPIServer " << dst << "]: " << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}


/*************************************** MAIN *******************************************/
int main(int argc, char **argv) {
    int flag = 0;
    int rank = -1;
    int size = 1;
    int provided;

    MPI_Initialized(&flag);

    if (!flag) {
        MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
    }

    std::cout << "MPI: " << "RANK: " << rank << " SIZE: " << size << std::endl;

    if (rank == 0) {
        std::cout << "rank 0: RunServer" << rank << std::endl;
        RunServer(rank);
    } else if (rank == 1) {
        std::cout << "rank 1: RunClient" << rank << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RunClient(rank, "0.0.0.0:50051");
    } else {
        std::cout << "rank error: " << rank << std::endl;
    }

    MPI_Finalize();

    return 0;
}