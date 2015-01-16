//
//  main.cpp
//  Clang Format To Uncrustify
//
//  Created by Pranav Prakash on 1/6/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

ifstream clangIn("clang.in");
ofstream uncrustifyOut("uncrustify.out");

/**
 * 0 = boolean
 * 1 = integer
 * 2 = string
 */
unordered_map<string, int> tokenTypeMap;
unordered_map<string, string> tokenMap;

void updateTokenTypes()
{
    ifstream typesIn("tokenTypes.txt");
    while (!typesIn.eof())
    {
        string token;
        typesIn >> token;

        int type;
        typesIn >> type;

        tokenTypeMap[token] = type;
    }
}


void updateTokens()
{
    ifstream types("conversion.txt");
    while (!types.eof())
    {
        string token;
        types >> token;
        
        string type;
        types >> type;
        
        tokenMap[token] = type;
    }
}
void processIntToken(string &token)
{
    uncrustifyOut << tokenMap[token] << '\n';
}

void processBoolToken(string &token)
{
    uncrustifyOut << tokenMap[token] << '\n';
}

void processStringToken(string &token)
{
    uncrustifyOut << tokenMap[token] << '\n';
}

void processToken(string &token)
{
    int tokenType = tokenTypeMap[token];
    switch (tokenType)
    {
        case 0:
            processBoolToken(token);
            break;

        case 1:
            processIntToken(token);
            break;

        case 2:
            processStringToken(token);
            break;

        default:
            break;
    }
}

int main(int argc, const char *argv[])
{
    updateTokenTypes();
    updateTokens();
    
    while (!clangIn.eof())
    {
        string token;
        clangIn >> token;

        processToken(token);
    }
    return 0;
}