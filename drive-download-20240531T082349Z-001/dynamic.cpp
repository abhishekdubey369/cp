#include<iostream>
#include<stdio.h>

using namespace std;
int main(void){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int *p;
    p = (int *) malloc(10*sizeof(a));
    p = a;
    int s =0;
    for(int i=0;i<10;i++){
        s+=*(p+i);
    }
    cout<<s;
    free(p);
    return 0;
}