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
#include <sstream>
using namespace std;

template <class Type>
Type stringToNum(const string& str)
{
    istringstream iss(str);
    Type num;
    iss>>num;
    return num;
}//参考CSDN 将string转化为int类

struct Student {
    string number1;
    string name1;
    string sexual;
    string college;
    double average;
}Student_a[7];

struct Judge{
    string number2;
    string name2;
    string sexual;
    string score[7];
    string judge_college;
}Judge_a[7];

int main(void)
{
    ifstream student_info("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/学生信息.txt");
    ifstream judge_info("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/裁判信息.txt");
    ofstream score_out("/Users/s20181102933/Desktop/project/Project/Project/鲷鱼/1/1/成绩.txt");
    int i;
    cout<<"       The competition is begining          "<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"Ask the player to the enter:"<<endl;
    cout<<endl;
    for(i=0;i<7;i++){
        student_info>>Student_a[i].number1>>Student_a[i].name1>>Student_a[i].sexual>>Student_a[i].college;
    }
    for(i=0;i<7;i++){
        cout<<"    "<<Student_a[i].number1<<" "<<Student_a[i].name1<<" "<<Student_a[i].sexual<<" "<<Student_a[i].college<<endl;
    }
    cout<<endl;
    cout<<"                 裁判名单                  "<<endl;
    cout<<"*******************************************"<<endl;
    for(i=0;i<7;i++){
        judge_info>>Judge_a[i].number2>>Judge_a[i].name2>>Judge_a[i].sexual>>Judge_a[i].judge_college;
        for(int j=0;j<7;j++){
            judge_info>>Judge_a[i].score[j];
        }
    }
    for(i=0;i<7;i++){
        cout<<Judge_a[i].number2<<" "<<Judge_a[i].name2<<" "<<Judge_a[i].sexual<<" "<<Judge_a[i].judge_college;
        cout<<endl;
    }
    cout<<endl;
    cout<<"    <-Player score->"<<endl;
    cout<<endl;
    for(int i=0;i<7;i++){
        cout<<Student_a[i].name1<<"  "<<Student_a[i].sexual<<"   ";
        for(int j=0;j<7;j++){
            cout<<Judge_a[i].score[j]<<" ";
        }
        cout<<Student_a[i].college;
        cout<<endl;
    }
    cout<<endl;
    cout<<"       比赛结束      "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"    裁判打分并统计成绩    "<<endl;
    cout<<"最终成绩:"<<endl;
    int sum=0;
    int new_a[7];
    int median;
    for(int i=0;i<7;i++){
        sum=0;
        for(int j=0;j<7;j++){
            new_a[j]=stringToNum<int>(Judge_a[i].score[j]);
        }//字符串传化为整形的实现。
        for(int h=0;h<7;h++){
            for(int g=1;g<7;g++){
                if(new_a[g]<new_a[g-1]){
                    median=new_a[g];
                    new_a[g]=new_a[g-1];
                    new_a[g-1]=median;
                }
            }
        }
        for(int y=1;y<6;y++){
            sum+=new_a[y];
        }
        Student_a[i].average=sum*1.0/5;
    }
    
    for(int i=0;i<7;i++){
        Student variable;
        for(int j=1;j<7;j++){
            if(Student_a[j].average>Student_a[j-1].average){
                variable=Student_a[j];
                Student_a[j]=Student_a[j-1];
                Student_a[j-1]=variable;
            }
        }
    }
    for(int i=0;i<7;i++){
        cout<<"第"<<i+1<<"名"<<" "<<Student_a[i].number1<<"  "<<Student_a[i].name1<<" "<<Student_a[i].sexual<<"  "<<Student_a[i].college<<"     "<<Student_a[i].average<<endl;
    }
    score_out<<"最终结果 :"<<endl;
    for(int i=0;i<7;i++){
        score_out<<endl<<"第"<<i+1<<"名"<<" "<<"编号:"<<Student_a[i].number1<<"  "<<Student_a[i].name1<<" "<<Student_a[i].sexual<<"  "<<Student_a[i].college<<"    "<<Student_a[i].average<<endl;
    }
    cout<<endl;
    cout<<"一等奖 : "<<Student_a[0].name1<<" "<<Student_a[0].average<<" "<<Student_a[0].college<<endl;
    cout<<"二等奖 : "<<Student_a[1].name1<<" "<<Student_a[1].average<<" "<<Student_a[1].college<<endl;
    cout<<"三等奖 : "<<Student_a[2].name1<<" "<<Student_a[2].average<<" "<<Student_a[2].college<<endl;
    cout<<endl;
    cout<<"     *结束*"<<endl;
    cout<<"<<<<<<<<>>>>>>>>>"<<endl;
    return 0;
}
