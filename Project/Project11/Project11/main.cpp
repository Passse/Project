//
//  main.cpp
//  Project11
//
//  Created by s20181102933 on 2019/6/13.
//  Copyright © 2019 s20181102933. All rights reserved.
//

#include<iostream>
#include<cmath>
using namespace std;
class Complex{
private:
    int x,y;
public:
    Complex(int a,int b){
        x=a;
        y=b;
    }
    double operator - (const Complex &c1) ;
};

double Complex::operator -(const Complex &c1) {
    double r;
    r=sqrt(pow((x-c1.x),2)+pow((y-c1.y),2));
    return r;
}


template<class T>
double dist(T a,T b){
    return abs(b-a);
}


int main()
{
    int ty;
    cin>>ty;
    while(ty>0){
        if(ty==1){
            int a,b;
            cin>>a>>b;
            cout<<dist<int>(a,b)<<endl;
        }
        if(ty==2){
            double a,b;
            cin>>a>>b;
            cout<<dist<double>(a,b)<<endl;
        }
        if(ty==3){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<dist<Complex>(Complex(x1,y1),Complex(x2,y2))<<endl;
        }
        cin>>ty;
    }
    return 0;
}
