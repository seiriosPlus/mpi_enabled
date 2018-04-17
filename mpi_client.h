//
// Created by tangwei12 on 2018/4/2.
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
            class MPIClient {
            public:
                MPIClient(std::shared_ptr <Channel> channel) : stub_(Greeter::NewStub(channel)) {}

                ReplyContext SendGRPCRequest(const RequestContext &req);

                void SendRequest();

                void SendMPIRequest(const char *buf, int count, int dst, int tag);

                bool IsFinished();

            private:
                std::unique_ptr <MPIService::Stub> stub_;
                int ready;
                int done;
            };
        }
    }
}