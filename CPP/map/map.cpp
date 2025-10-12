#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

int main(){

    std::map<std::string, std::string> capitals;

    capitals["korea"] = "seoul";
    capitals["usa"] = "washington";
    //capitals.erase("korea");
    capitals.count("korea");

    for(auto it=capitals.begin(); it != capitals.end(); it++){
        printf("capitals[%s] = %s\n", it->first.c_str(), it->second.c_str());
    }
    return 0;
}