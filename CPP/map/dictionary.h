#ifndef __HEADER_H__
#define __HEADER_H__

#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>


int getInteger(const char* prompt);
std::string getSTring(const char* prompt);


class Dictionary{
    private:
        std::map<std::string, std::string> words;
    public: 
        void insertWord(const std::string& word, const std::string& mean);
        bool exists(const std::string& word);
        std::string getMean(const std::string& word);
};


#endif