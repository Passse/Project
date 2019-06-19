//
//  main.cpp
//  1
//
//  Created by s20181102933 on 2019/6/19.
//  Copyright © 2019 s20181102933. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream ef1("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/裁判信息.txt");
    ofstream ef2("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/学生信息.txt");
    int i,j;
    string name,xb,yuanxi;
    int bh;
    int a[7];
    int b[10];
    for(i=0;i<6;i++){
        ef1<<a[i];
    }
    for(j=0;j<9;j++){
        ef2<<b[j];
    }
    
    return 0;
}



