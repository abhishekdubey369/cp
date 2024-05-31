#include<iostream>

using namespace std;
int sum(int a){

    if(a>0){
        return a+sum(a-1);
    }else{
        return 0;
    }

}

int main(void){
    int a;
    cin>>a;
    cout<<sum(a);
    return 0;

}