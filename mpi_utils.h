//
// Created by tangwei12 on 2018/4/2.
//

#pragma once

#include <mpi.h>
#include <map>
#include <string>
#include <vector>

namespace paddle {
    namespace operators {
        namespace detail {
            class MPIUtils {
            public:
                MPIUtils(const std::string &worker_name);

                const int GetRankID(const std::string &task_id);

            private:
                void InitMPI();

                std::map<std::string, int> name_id_map;
            };

            class Meta {
            public:
                int src;
                int dst;
                MPI_Datatype datatype;
                char *request;
                int count;
                int tag;
                int device;
            };

            class MPISend {
            public:
                MPISend(const Meta &meta);

                bool IsFinished();

                bool IsReady();

                void Send();

                ~MPISend();

            private:
                int done1_;
                int done2_;
                Meta *meta;
            };

            class MPIRecv {
            public:
                MPIRecv(const Meta &meta);

                bool IsReady();

                bool IsFinished();

                void Recv();

                ~MPIRecv();

            private:
                int done1_;
                int done2_;
                Meta *meta;
            };

        }  // namespace detail
    }  // namespace operators
}  // namespace paddle