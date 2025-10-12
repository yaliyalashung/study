#ifndef __HEADER_H__
#define __HEADER_H__

#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>

int getInteger(const char* prompt){
    
    printf(prompt);
    int input;
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);
    return input;
}

std::string getString(const char* prompt){
    printf(prompt);
    char str[100];
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]", str);    
    return str;
}

#endif