#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <unistd.h>

class DeribitClient{
    private:
        std::string client_id;
        std::string url;
        std::string client_secret;
        std::string access_token; 
        std::string sendRequest(const std::string& url, const std::string& method, const std::string& payload = "");
    public:
        DeribitClient(std::string client_id, std::string url, std::string client_secret);
        size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

};