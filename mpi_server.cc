//
// Created by tangwei12 on 2018/4/2.
//


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
            class MPIServerImpl final : public mpis::MPIService {
                Status ISendRequest(::grpc::ClientContext *context, const ::mpis::RequestContext &request,
                                    ::mpis::ReplyContext *response) override {
                    std::cout << "tag: " << request.tag() << " src: " << request.src();
                    response->set_msg("OK");
                    response->set_ready(0);

                    return Status::OK;
                }
            };

            void RunServer() {
                std::string server_address("0.0.0.0:50051");
                GreeterServiceImpl service;

                ServerBuilder builder;
                // Listen on the given address without any authentication mechanism.
                builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
                // Register "service" as the instance through which we'll communicate with
                // clients. In this case it corresponds to an *synchronous* service.
                builder.RegisterService(&service);
                // Finally assemble the server.
                std::unique_ptr <Server> server(builder.BuildAndStart());
                std::cout << "Server listening on " << server_address << std::endl;

                // Wait for the server to shutdown. Note that some other thread must be
                // responsible for shutting down the server for this call to ever return.
                server->Wait();
            }
        }
    }
}
