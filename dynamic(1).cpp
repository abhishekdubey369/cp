#include<iostream>
#include<stdio.h>

using namespace std;
int main(void){
    int *p[6];
    p[0]=new int(0);
    p[1]=new int(1);
    p[2]=new int(2);
    p[3]=new int(3);
    p[4]=new int(4);
    p[5]=new int(5);
    int s =0;
    for(int i=0;i<6;i++){
        s+=**(p+i);
    }
    cout<<s;
    return 0;
}