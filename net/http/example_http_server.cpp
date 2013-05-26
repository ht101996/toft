// Copyright (c) 2013, The Toft Authors.
// All rights reserved.
//
// Author: CHEN Feng <chen3feng@gmail.com>

#include "toft/net/http/http_server.h"

#include "thirdparty/gflags/gflags.h"
#include "thirdparty/glog/logging.h"

int main(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);

    using namespace toft;
    HttpServer server;
    server.Bind(SocketAddressInet4("127.0.0.1", 8080));
    server.Start();
    server.Run();
}
