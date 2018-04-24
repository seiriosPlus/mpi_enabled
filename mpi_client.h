//
// Created by tangwei12 on 2018/4/2.
//

#pragma once

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "mpi.grpc.pb.h"
#include "var.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using mpis::MPIService;
using mpis::RequestContext;
using mpis::ReplyContext;


class MPIClient {
public:
    MPIClient(std::shared_ptr<Channel> channel, int src);

    void SendGRPCRequest(const RequestContext &request, ReplyContext *reply);

    void SendRequest(const Var &var);

    void SendMPIRequest(const char *buf, int length, int dst, int tag);

    bool IsFinished();

private:
    std::unique_ptr<MPIService::Stub> stub_;
    int src;
    int grpc;
    int mpi;
};
