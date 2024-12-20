#include "DeribitClient.h"

int main(int arc, char** arv){

    // if (arc != 3){
    //     write(2,"to myn args!!\n",15);
    //     return 2;
    // }
    try
    {
        std::string client_sec = "rS_Cs1nX9NSQS8n4u4z3yWfvBX5d84yP3QU76SoVYb0";
        std::string client_id = "BaGiJcZX";
        std::string url = "https://test.deribit.com/api/v2/";
        DeribitClient clinet(client_id,url,client_sec);
        clinet.authenticate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}