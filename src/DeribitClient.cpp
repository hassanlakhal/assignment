#include "../include/DeribitClient.h"

DeribitClient::DeribitClient(std::string client_id, std::string url, std::string client_secret)
: url(url), client_id(client_id), client_secret(client_secret) {

}

size_t DeribitClient::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){

    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::string DeribitClient::sendRequest(const std::string& url, const std::string& method, const std::string& payload){
    std::string response;
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
            struct curl_slist* headers = NULL;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            if (method == "POST") {
                curl_easy_setopt(curl, CURLOPT_POST, 1L);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
                headers = curl_slist_append(headers, "Content-Type: application/json");
            }

            if (!access_token.empty()) {
                std::string auth_header = "Authorization: Bearer " + access_token;
                headers = curl_slist_append(headers, auth_header.c_str());
            }

            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }

            curl_easy_cleanup(curl);
            if (headers) curl_slist_free_all(headers);
        }

    return response;

}