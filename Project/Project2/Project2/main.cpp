//
//  main.cpp
//  Project2
//
//  Created by s20181102933 on 2019/6/13.
//  Copyright © 2019 s20181102933. All rights reserved.
//

#include <iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
struct StudentInfo{
    string name;
    string gebder;//性别
    string acade;//学院
    string num;//编号
    string program;
    double average;
}student[7];
struct JudgeInfo{
    string name;
    string debder;
    string acade;
    string num;
}judge[7];
//===============================
template<class Type>
Type stringToNum(const string & str)
{
    istringstream iss(str);
    Type num;
    iss>>num;
    return num;
}
//从网上找的将string转化成int的方法
void sorts(StudentInfo a[])
{
    StudentInfo temp;
    for(int i=0;i<7;++i){
        for(int j=1;j<7;++j){
            if(a[j].average<a[j-1].average){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ifstream jude_info("/Users/s20181102928/Desktop/judge information.txt");
    for(int i=0;i<7;++i){
        jude_info>>judge[i].name>>judge[i].debder>>judge[i].acade>>judge[i].num;
    }//裁判信息录入，judge[0] 录入列名
    ifstream stud_info("/Users/s20181102928/Desktop/学生信息.txt");
    for(int i=0;i<7;++i){
        stud_info>>student[i].name>>student[i].gebder>>student[i].acade>>student[i].num>>student[i].program;
    }//选手信息录入,studen[0] 录入列名
    ifstream game_rules("/Users/s20181102928/Desktop/rules of game.txt");
    string rules;
    game_rules>>rules;//比赛规则录入
    cout<<"          Welcome to this art competition!        "<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"          Welcome to the referee !"<<endl;
    cout<<"   ===================================="<<endl;
    for(int i=0;i<7;++i){
        cout<<"   =";
        cout<<"       "<<judge[i].name<<"  "<<judge[i].debder<<" "<<judge[i].acade<<"     "<<judge[i].num;
        if(i!=0)
            cout<<"  ";
        cout<<"   =";
        cout<<endl;
    }
    cout<<"   ===================================="<<endl;//显示裁判员信息
    cout<<endl;
    cout<<"本次比赛规则如下：";
    cout<<rules;
    cout<<endl<<endl;
    cout<<"Now ,the game begins!"<<endl;
    ifstream InScore("/Users/s20181102928/Desktop/评委打分.txt");
    string scores[6][7];
    for(int i=0;i<6;++i){
        for(int j=0;j<7;++j){
            InScore>>scores[i][j];
        }
    }
    for(int i=0;i<7;++i){
        cout<<"现在欢迎第"<<i+1<<"位选手"<<endl;
        cout<<student[i].name<<"  "<<student[i].gebder<<"  "<<student[i].acade<<"  "<<student[i].num<<" "<<student[i].program<<endl;
        cout<<"选手表演完毕，请各位评委老师打分:"<<endl;
        int s[7];
        double averages=0;
        for(int j=0;j<7;++j){
            s[j]=stringToNum<int>(scores[i][j]);
        }
        sort(s,s+7);
        for(int k=1;k<=5;k++)
            averages+=s[k];
        averages=averages*1.0/5;
        student[i].average=averages;
        cout<<averages<<" ";
    }
    sorts(student);
    
    return 0;
}
