//
// Created by tangwei12 on 2018/4/2.
//

#include "mpi_client.h"

paddle::operators::detail::MPIClient::MPIClient(std::shared_ptr <Channel> channel) {

}

ReplyContext paddle::operators::detail::MPIClient::SendGRPCRequest(const RequestContext &req) {
    ReplyContext reply;
    ClientContext context;
    Status status = stub_->ISendRequest(&context, req, &reply);

    if (reply.status() == status::ok()) {
        return reply;
    }

    return nullptr;
}

void paddle::operators::detail::MPIClient::SendRequest(int device,
                                                       int src,
                                                       const char *content,
                                                       const char *dest_grpc) {

    int size = sizeof(content);
    int tag = 100;

    RequestContext req;
    req.set_device(device);
    req.set_src(src);
    req.set_buffer_size(size);
    req.set_tag(tag);

    ReplyContext reply = SendGRPCRequest(req);

    if (reply == nullptr) {
        this->done = -1;
        return;
    }

    SendMPIRequest(&content, size, reply.dst(), tag);
}

void paddle::operators::detail::MPIClient::SendMPIRequest(const char *buf, int count, int dst, int tag) {
    MPI_Send(&buf, count, MPI_CHAR, dst, tag, MPI_COMM_WORLD);
    this->done = 0;
}

bool paddle::operators::detail::MPIClient::IsFinished() {
    return this->done == 1;
}
