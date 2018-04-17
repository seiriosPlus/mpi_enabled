//
// Created by tangwei12 on 2018/4/17.
//

#pragma once

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include "mpi.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using mpis::MPIService;
using mpis::RequestContext;
using mpis::ReplyContext;

namespace paddle {
    namespace operators {
        namespace detail {
            class MPIServerImpl final : public MPIService::Service {
                Status ISendRequest(::grpc::ClientContext *context, const ::mpis::RequestContext &request,
                                    ::mpis::ReplyContext *response);
            };
        }
    }
}
