/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <thrift/lib/cpp/transport/TSSLServerSocket.h>
#include <thrift/lib/cpp/transport/TSSLSocket.h>

namespace apache { namespace thrift { namespace transport {

using namespace boost;

/**
 * SSL server socket implementation.
 */
TSSLServerSocket::TSSLServerSocket(int port,
                                   std::shared_ptr<TSSLSocketFactory> factory):
                                   TServerSocket(port), factory_(factory) {
  factory_->server(true);
}

TSSLServerSocket::TSSLServerSocket(int port, int sendTimeout, int recvTimeout,
                                   std::shared_ptr<TSSLSocketFactory> factory):
                                   TServerSocket(port, sendTimeout, recvTimeout),
                                   factory_(factory) {
  factory_->server(true);
}

std::shared_ptr<TSocket> TSSLServerSocket::createSocket(int client) {
  return factory_->createSocket(client);
}

}}}
