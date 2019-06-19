//
//  main.cpp
//  1
//
//  Created by s20181102933 on 2019/6/19.
//  Copyright © 2019 s20181102933. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ef("/Users/project/Project/Project/ef.txt");
    if (ef.is_open())
    {
            ef <<"This is a line.\n";
            ef <<"This is another line.\n";
            ef.close();
    }
    return 0;
}



