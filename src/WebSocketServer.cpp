#include "WebSocketServer.hpp"


WebSocketServer::WebSocketServer() {
        server.init_asio();
        server.set_open_handler(std::bind(&WebSocketServer::on_open, this, std::placeholders::_1));
        server.set_close_handler(std::bind(&WebSocketServer::on_close, this, std::placeholders::_1));
        server.set_message_handler(std::bind(&WebSocketServer::on_message, this, std::placeholders::_1, std::placeholders::_2));
    }


void WebSocketServer::startServer(int port) {
        server.listen(port);
        server.start_accept();
        std::cout << "WebSocket server started on port " << port << "\n";
        server.run();
    }


void WebSocketServer::broadcast(const std::string& symbol, const std::string& message) {
    std::lock_guard<std::mutex> lock(subscriptionsMutex);

    // Send updates to all clients subscribed to this symbol
    if (subscriptions.find(symbol) != subscriptions.end()) {
        for (const auto& hdl : subscriptions[symbol]) {
            server.send(hdl, message, ws::frame::opcode::text);
        }
    }
}


void WebSocketServer::on_open(ConnectionHandle hdl) {
        std::cout << "Client connected\n";
    }

void WebSocketServer::on_close(ConnectionHandle hdl) {
    std::lock_guard<std::mutex> lock(subscriptionsMutex);

    // Remove client from all subscriptions
    for (auto& [symbol, clients] : subscriptions) {
        clients.erase(hdl);
    }

    std::cout << "Client disconnected\n";
}

void WebSocketServer::on_message(ConnectionHandle hdl, Server::message_ptr msg) {
    std::string symbol = msg->get_payload();

    // Add client to the subscription list for this symbol
    {
        std::lock_guard<std::mutex> lock(subscriptionsMutex);
        subscriptions[symbol].insert(hdl);
    }

    std::cout << "Client subscribed to: " << symbol << "\n";
}

WebSocketServer::~WebSocketServer()
{

}