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

struct Student {
    int num1;
    string name1;
    string xb;
    string xy;
};
struct CP {
    string num2;
    string name2;
    string c1;
};
int main(void)
{
    ifstream ef1("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/学生信息.txt");
    ifstream ef2("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/裁判信息.txt");
    int i,j;
    struct Student s1[7];
    struct CP s2[7];
    for(i=1;i<=7;i++){
        ef1>>s1[i].num1>>s1[i].name1>>s1[i].xb>>s1[i].xy;
    }
    
    for(j=1;j<=7;j++){
        ef2>>s2[i].num2>>s2[i].name2>>s2[i].c1;
    }
    for(j=1;j<=7;j++){
        cout<<s2[i].num2<<" "<<s2[i].name2<<" "<<s2[i].c1<<endl;
    }
    
    
    return 0;
}



