//
//  main.cpp
//  鲷鱼
//
//  Created by s20181102933 on 2019/6/13.
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
    
        for(i=0;i<10;i++){
            int s;
            int j;
            for(j=1;j<10;j++){
                if(a[j]<a[j-1]){
                    s=a[j];
                    a[j]=a[j-1];
                    a[j-1]=s;
                }
            }
        }
        sort(a,a+10);
        for(i=0;i<10;i++){
            cout<<a[i]<<endl;
            }
}
