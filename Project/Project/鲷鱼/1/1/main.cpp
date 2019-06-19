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
    ofstream ef("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/data.txt");
    ifstream ief("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/data.txt");
    //cout<<"c ="<<a+b<<endl;
    if(ef.is_open())
    {
        ef<<"xing"<<endl;
    }
    return 0;
}



