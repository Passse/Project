//
//  main.cpp
//  project
//
//  Created by s20181102933 on 2019/6/12.
//  Copyright © 2019 s20181102933. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include <cmath>
using namespace std;
int main(){
    int i;
    int a[10];
    for(i=0;i<10;i++){
        cin>>a[i];
    }
    sort(a,a+10);
    for(i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
    return 0;

}
