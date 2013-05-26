// Copyright (c) 2013, The Toft Authors.
// All rights reserved.
//
// Author: CHEN Feng <chen3feng@gmail.com>

#ifndef TOFT_NET_HTTP_HTTP_CONNECTION_H
#define TOFT_NET_HTTP_HTTP_CONNECTION_H
#pragma once

#include <list>
#include <string>
#include <vector>
#include "toft/base/string/string_piece.h"
#include "toft/system/event_dispatcher/event_dispatcher.h"
#include "toft/system/net/socket.h"

namespace toft {

class HttpConnection {
    TOFT_DECLARE_UNCOPYABLE(HttpConnection);

public:
    HttpConnection(EventDispatcher* dispatcher, int fd);
    void Send(const StringPiece& data);
    void Close();

private:
    void OnIoEvents(int events);
    void OnError();
    void OnReadable();
    void OnClosed();
    void OnWriteable();

private:
    StreamSocket m_socket;
    IoEventWatcher m_watcher;
    std::vector<char> m_receive_buffer;
    size_t m_received_size;
    std::list<std::string> m_send_queue;
    size_t m_sent_size;
};

} // namespace toft

#endif // TOFT_NET_HTTP_HTTP_CONNECTION_H
