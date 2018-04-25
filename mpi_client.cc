//
// Created by tangwei12 on 2018/4/2.
//

#include <iostream>
#include <mpi.h>

#include "mpi_client.h"


MPIClient::MPIClient(std::shared_ptr<Channel> channel, int src) : stub_(MPIService::NewStub(channel)) {
    this->src = src;
    this->grpc = 0;
    this->mpi = 0;
}

void MPIClient::SendGRPCRequest(const RequestContext &request, ReplyContext *reply) {
    ClientContext context;
    Status status = stub_->ISendRequest(&context, request, reply);
    this->grpc = status.ok() ? 1 : 0;
}

void MPIClient::SendRequest(const Var &var) {

    RequestContext request;
    request.set_src(this->src);
    request.set_tag(var.tag);
    request.set_length(var.length);
    request.set_var_name(var.name);

    ReplyContext reply;

    SendGRPCRequest(request, &reply);
    std::cout << "[MPIClient " << this->src << "]: " << " get SendGRPC status: " << this->grpc << " dst: "
              << reply.dst()
              << std::endl;

    SendMPIRequest(var.value.c_str(), var.length, reply.dst(), var.tag);
    std::cout << "[MPIClient " << this->src << "]: " << " SendMPIRequest to: dst: " << reply.dst() << " finished"
              << std::endl;
}

void MPIClient::SendMPIRequest(const char *buf, int length, int dst, int tag) {
    MPI_Request request;

    MPI_Isend(buf, length, MPI_CHAR, dst, tag, MPI_COMM_WORLD, &request);
    std::cout << "[MPIClient " << this->src << "]: " << " MPI_Isend send data to destination, waiting " << std::endl;

    MPI_Status status;
    MPI_Wait(&request, &status);
    this->mpi = 1;
    std::cout << "[MPIClient " << this->src << "]: " << " MPI_Isend send data to destination, exit" << std::endl;
}

bool MPIClient::IsFinished() {
    return this->mpi == 1;
}