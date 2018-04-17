//
// Created by tangwei12 on 2018/4/2.
//


#include "mpi_server.h"


Status paddle::operators::detail::MPIServerImpl::ISendRequest(::grpc::ClientContext *context,
                                                              const ::mpis::RequestContext &request,
                                                              ::mpis::ReplyContext *response) override {
    std::cout << "tag: " << request.tag() << " src: " << request.src();
    response->set_dst(2);
    return Status::OK;
};