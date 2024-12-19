#include "DeribitClient.h"

int main(int arc, char** arv){

    // if (arc != 3){
    //     write(2,"to myn args!!\n",15);
    //     return 2;
    // }
    try
    {
        std::string client_sec = "nH2e4jvj7yYBKRUgy2CWBnzk7r-aq92fWORwZcc31y4";
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