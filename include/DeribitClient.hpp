#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <unistd.h>
#include <iostream>
#include <sstream>

class DeribitClient{
    private:
        std::string client_id;
        std::string url;
        std::string client_secret;
        std::string access_token; 
        std::string sendRequest(std::string& url, const std::string& method, std::string& payload);
    public:
        void authenticate();
        DeribitClient(std::string client_id, std::string url, std::string client_secret);
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
        bool placeOrder(const std::string& instrument, double price, double quantity, const std::string& orderType);
        bool cancelOrder(const std::string& order_id); 
        bool modifyOrder(const std::string& orderId, double newPrice, double newQuantity);
        bool getOrderbook(int depth, const std::string& instrument_name);


};