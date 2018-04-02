//
// Created by tangwei12 on 2018/4/2.
//

#include "mpi_client.h"

paddle::operators::detail::MPIClient::MPIClient(std::shared_ptr <Channel> channel) {

}

void paddle::operators::detail::MPIClient::SendGRPCRequest(const RequestContext &req) {
    ReplyContext reply;
    ClientContext context;
    Status status = stub_->ISendRequest(&context, req, &reply);
    this->ready = status.ok() && reply.ready() == 0 ? 0 : 1;
}

void paddle::operators::detail::MPIClient::SendRequest(const RequestContext &req) {

    SendGRPCRequest(req);
    if (this->ready != 0) {
        return;
    }
    SendMPIRequest(req);
}

void paddle::operators::detail::MPIClient::SendMPIRequest(const char *buf, int count, int dst, int tag) {
    MPI_Send(&buf, count, MPI_CHAR, dst, tag, MPI_COMM_WORLD);
    this->done = 0;
}
