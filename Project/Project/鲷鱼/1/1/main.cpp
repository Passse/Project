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
    int number1;
    string name1;
    string sexual;
    string college;
}a[7];

struct Referee{
    string number2;
    string name2;
    string sexual;
    string score[7];
}b[7];

int main(void)
{
    ifstream ef1("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/学生信息.txt");
    ifstream ef2("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/裁判信息.txt");
    int i;
    cout<<"       The competition is begining          "<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"Ask the player to the enter:"<<endl;
    for(i=0;i<7;i++){
        ef1>>a[i].number1>>a[i].name1>>a[i].sexual>>a[i].college;
    }
    for(i=0;i<7;i++){
        cout<<"    "<<a[i].number1<<" "<<a[i].name1<<" "<<a[i].sexual<<" "<<a[i].college<<endl;
    }
    cout<<endl;
    cout<<"          This is the Referee                  "<<endl;
    cout<<"*******************************************"<<endl;
    for(i=0;i<7;i++){
        ef2>>b[i].number2>>b[i].name2>>b[i].sexual;
        for(int j=0;j<7;j++){
            ef2>>b[i].score[j];
        }
    }
    for(i=0;i<7;i++){
        cout<<b[i].number2<<" "<<b[i].name2<<" "<<b[i].sexual<<" ";
        /*for(int j=0;j<7;j++){
            cout<<b[i].score[j]<<" "  ;
        }*/
        cout<<endl;
    }
    cout<<endl;
    cout<<"->Player score:"<<endl;
    for(int i=0;i<7;i++){
        //out<<"Num."<<i+1<<" ";
        cout<<a[i].name1<<" ";
        for(int j=0;j<7;j++){
            cout<<b[i].score[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"最终成绩:"<<endl;
    
    return 0;
}
