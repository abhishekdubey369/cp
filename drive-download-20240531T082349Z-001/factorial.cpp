#include<iostream>

using namespace std;
int fact(int a){

    if(a>0){
        return a*fact(a-1);
    }else{
        return 1;
    }

}

int main(void){
    int a;
    cin>>a;
    cout<<fact(a);
    return 0;

}