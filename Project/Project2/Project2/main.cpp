//
//  main.cpp
//  Project2
//
//  Created by s20181102933 on 2019/6/13.
//  Copyright © 2019 s20181102933. All rights reserved.
//

#include <iostream>
using namespace std;
class A{
private:
    int i=1;
public:
    void display(){
        if(i==1){
            cout<<"C++"<<endl;
        }
    }
};
int main(){
    A a;
    a.display();
    return 0;
}
