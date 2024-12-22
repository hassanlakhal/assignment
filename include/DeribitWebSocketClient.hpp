#include <websocketpp/config/asio_client.hpp>
#include <boost/asio/ssl/context.hpp>
#include <websocketpp/client.hpp>
#include "WebSocketServer.hpp"
#include <json/json.h>
#include <iostream>

#include <string>
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <boost/asio/ssl/context.hpp>

typedef websocketpp::client<websocketpp::config::asio_tls_client> WebSocketClient;

class DeribitWebSocketClient {
public:
    DeribitWebSocketClient(const std::string& url); // Constructor to initialize server URL
    void connect();
    void subscribe(const std::string& channel, const std::string& method, int id);
    void run();

private:
    std::string serverUrl; // WebSocket server URL
    WebSocketClient wsClient; // WebSocket client instance
    websocketpp::connection_hdl currentHdl;

    std::shared_ptr<boost::asio::ssl::context> on_tls_init(websocketpp::connection_hdl hdl);
    void on_open(websocketpp::connection_hdl hdl);
    void on_message(websocketpp::connection_hdl hdl, WebSocketClient::message_ptr msg);
    void on_close(websocketpp::connection_hdl hdl);
    void on_fail(websocketpp::connection_hdl hdl);
};
