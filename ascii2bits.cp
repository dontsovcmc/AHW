//
//  main.cpp
//  img
//
//  Created by Dontsov Evgeny on 15.12.13.
//  Copyright (c) 2013 Dontsov Evgeny. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <fstream>

#define SIG ' '

int main(int argc, const char * argv[])
{
    using namespace std;
    // insert code here...
    cout << "Hello, World!\n";
    
    ifstream f;
    f.open("/Users/dontsov/Documents/Arduino/input.txt");
    
    string line;
    string outStr;
    ofstream outStream;
    outStream.open("/Users/dontsov/Documents/Arduino/output.txt");
    
    
    while (getline (f,line))
    {
        unsigned char buf = '\0';
        char buf2[10];
        int b=0;
        for (int i=0; i < line.length();i++)
        {
            if (b < 8)
            {
                if (line[i] == SIG)
                    buf |= (1 << (7-b));
                b++;
            }
            else
            {
                snprintf(buf2,9,"%X",buf);
                outStream << "0x" << buf2 << ", ";
                buf = '\0';
                b=0;
            }
        }
        if (b != 8 && b != 0)
        {
            snprintf(buf2,9,"%X",buf);
            outStream << "0x" << buf2 << ", ";
            buf = '\0';
            b=0;
        }
        
        outStream << "\n";
    }
    
    return 0;
}

