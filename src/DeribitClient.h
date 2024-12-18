#include<string>
#include <curl/curl.h>



class DeribitClient{
    private:
        std::string client_id;
        std::string url;
        std::string client_secret; 
        std::string sendRequest(std::string url, std::string methods, std::string paylod);
    public:
        DeribitClient(std::string client_id, std::string url, std::string client_secret);

};