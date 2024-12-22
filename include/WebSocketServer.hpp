#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <unordered_map>
#include <set>
#include <string>
#include <mutex>
#include <iostream>

namespace ws = websocketpp;

// Alias for convenience
typedef ws::server<ws::config::asio> Server;
typedef ws::connection_hdl ConnectionHandle;

class WebSocketServer {
public:
    WebSocketServer();
    ~WebSocketServer();
    void startServer(int port);
    void broadcast(const std::string& symbol, const std::string& message);

private:
    Server server;
    std::unordered_map<std::string, std::set<ConnectionHandle, std::owner_less<ConnectionHandle>>> subscriptions;
    std::mutex subscriptionsMutex;

    void on_open(ConnectionHandle hdl);

    void on_close(ConnectionHandle hdl);

    void on_message(ConnectionHandle hdl, Server::message_ptr msg);
};
