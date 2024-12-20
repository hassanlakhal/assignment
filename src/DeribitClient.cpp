#include "../include/DeribitClient.h"

DeribitClient::DeribitClient(std::string client_id, std::string url, std::string client_secret)
: url(url), client_id(client_id), client_secret(client_secret) {
    std::string access_token = "";

}

size_t DeribitClient::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){

    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::string DeribitClient::sendRequest(std::string& url, const std::string& method, std::string& payload){
    std::string response;
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        std::cout << "urls " << payload << std::endl;
        curl_easy_setopt(curl, CURLOPT_URL, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "CURL request failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return response;

}

void DeribitClient::authenticate() {
    // Construct the base URL
    std::string url_base = url + "public/auth";

    // Create JSON payload
    Json::Value data;
    data["grant_type"] = "client_credentials";
    data["client_id"] = client_id;
    data["client_secret"] = client_secret;

    // Convert JSON payload to string
    Json::StreamWriterBuilder writer;
    std::string payload = Json::writeString(writer, data);

    // Build the URL with query parameters
    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errors;

    // Use a stream for parsing JSON
    std::istringstream jsonStream(payload);
    if (!Json::parseFromStream(readerBuilder, jsonStream, &root, &errors)) {
        std::cerr << "Failed to parse JSON: " << errors << std::endl;
        return;
    }

    // Construct the URL endpoint with query parameters
    std::ostringstream urlEndpoint;
    urlEndpoint << url_base << "?";

    for (const auto& key : root.getMemberNames()) {
        urlEndpoint << key << "=" << root[key].asString() << "&";
    }

    // Remove trailing '&' from the URL
    std::string endpoint = urlEndpoint.str();
    if (!endpoint.empty() && endpoint.back() == '&') {
        endpoint.pop_back();
    }

    // Print the payload and endpoint
    std::cout << "Payload: " << payload << std::endl;
    std::cout << "Endpoint: " << endpoint << std::endl;

    // Send request
    std::string response = sendRequest(url_base, "GET", endpoint);
    std::cout << "Response: " << response << std::endl;

    // Parse the response
    Json::CharReaderBuilder responseReader;
    Json::Value jsonResponse;
    std::istringstream responseStream(response);
    if (Json::parseFromStream(responseReader, responseStream, &jsonResponse, &errors)) {
        if (jsonResponse["result"].isMember("access_token")) {
            access_token = jsonResponse["result"]["access_token"].asString();
            std::cout << "login " <<  access_token << std::endl;
        } else {
            throw std::runtime_error("Authentication failed: " + response);
        }
    } else {
        throw std::runtime_error("Failed to parse authentication response: " + errors);
    }
}

 bool DeribitClient::placeOrder(const std::string& instrument, double price, double quantity, const std::string& orderType) {
    return false;
 }


bool DeribitClient::cancelOrder(const std::string& order_id){


    return false;
    
}


bool DeribitClient::modifyOrder(const std::string& orderId, double newPrice, double newQuantity) {
    return false;
}

bool DeribitClient::getOrderbook(int depth, const std::string& instrument_name){
    return false;
} 