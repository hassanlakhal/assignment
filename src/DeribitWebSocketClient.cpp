#include "DeribitWebSocketClient.hpp"
#include <iostream>
#include <memory>

// Constructor
DeribitWebSocketClient::DeribitWebSocketClient(const std::string& url) : serverUrl(url) {
    wsClient.init_asio();
    wsClient.set_tls_init_handler(std::bind(&DeribitWebSocketClient::on_tls_init, this, std::placeholders::_1));

    wsClient.set_message_handler(std::bind(&DeribitWebSocketClient::on_message, this, std::placeholders::_1, std::placeholders::_2));
    wsClient.set_open_handler(std::bind(&DeribitWebSocketClient::on_open, this, std::placeholders::_1));
    wsClient.set_close_handler(std::bind(&DeribitWebSocketClient::on_close, this, std::placeholders::_1));
    wsClient.set_fail_handler(std::bind(&DeribitWebSocketClient::on_fail, this, std::placeholders::_1));
}

// TLS Initialization
std::shared_ptr<boost::asio::ssl::context> DeribitWebSocketClient::on_tls_init(websocketpp::connection_hdl hdl) {
    auto ctx = std::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv12);

    try {
        ctx->set_options(boost::asio::ssl::context::default_workarounds |
                         boost::asio::ssl::context::no_sslv2 |
                         boost::asio::ssl::context::no_sslv3 |
                         boost::asio::ssl::context::single_dh_use);

        // Disable SSL certificate verification (for testing)
        ctx->set_verify_mode(boost::asio::ssl::verify_none);
    } catch (const std::exception& e) {
        std::cerr << "Error in on_tls_init: " << e.what() << std::endl;
    }

    return ctx;
}

void DeribitWebSocketClient::run(){
    wsClient.run();

}

// Connect to the WebSocket server
void DeribitWebSocketClient::connect() {
    websocketpp::lib::error_code ec;
    WebSocketClient::connection_ptr con = wsClient.get_connection(serverUrl, ec);

    if (ec) {
        std::cerr << "Connection error: " << ec.message() << std::endl;
        return;
    }
    wsClient.connect(con);
}

// Event Handlers
void DeribitWebSocketClient::on_open(websocketpp::connection_hdl hdl) {
    std::cout << "Connection opened to: " << serverUrl << std::endl;
    currentHdl = hdl;
    subscribe("deribit_price_index.btc_usd","public/subscribe",4235);

}

void DeribitWebSocketClient::on_message(websocketpp::connection_hdl hdl, WebSocketClient::message_ptr msg) {
    std::string payload = msg->get_payload();
    std::cout << "Message received: " << payload << std::endl;

    // Assuming the message contains JSON data
    Json::CharReaderBuilder reader;
    Json::Value jsonResponse;
    std::string errors;
    std::istringstream stream(payload);

    if (Json::parseFromStream(reader, stream, &jsonResponse, &errors)) {
        if (jsonResponse.isMember("method") && jsonResponse["method"].asString() == "orderbook.update") {
            std::cout << "Received order book update:" << std::endl;
            std::cout << jsonResponse.toStyledString() << std::endl;
        }
    } else {
        std::cerr << "Failed to parse JSON: " << errors << std::endl;
    }
}


void DeribitWebSocketClient::on_close(websocketpp::connection_hdl hdl) {
    std::cout << "Connection closed." << std::endl;
}

void DeribitWebSocketClient::on_fail(websocketpp::connection_hdl hdl) {
    WebSocketClient::connection_ptr con = wsClient.get_con_from_hdl(hdl);
    std::cerr << "Connection failed: " << con->get_ec().message() << std::endl;
}


void DeribitWebSocketClient::subscribe(const std::string& channel, const std::string& method, int id) {
    // Construct the subscription request in JSON format
    Json::Value subscriptionRequest;
    subscriptionRequest["jsonrpc"] = "2.0";
    subscriptionRequest["method"] = method;
    subscriptionRequest["id"] = id; // Unique ID for the request
    subscriptionRequest["params"]["channels"][0] = channel;

    // Serialize the JSON object to a string
    Json::StreamWriterBuilder writer;
    std::string requestPayload = Json::writeString(writer, subscriptionRequest);

    // Check if currentHdl is valid
    std::cout << channel << std::endl;
    if (currentHdl.lock() == nullptr) {
        std::cerr << "No active WebSocket connection. Cannot subscribe." << std::endl;
        return;
    }

    // Send the subscription request
    websocketpp::lib::error_code ec;
    wsClient.send(currentHdl, requestPayload, websocketpp::frame::opcode::text, ec);

    if (ec) {
    

        std::cerr << "Error sending subscription request: " << ec.message() << std::endl;
    } else {
        
        std::cout << "Subscription request sent for channel: " << channel << std::endl;
    }
    
}

