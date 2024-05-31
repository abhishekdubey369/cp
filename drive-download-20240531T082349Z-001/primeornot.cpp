#include<iostream>

//time complexity is O(n)
using namespace std;

void prornot(int a){
    static int c; //1
    for(int i=2;i<a;i++){//a
        if(a%i==0){
            c=1;
        }
    }
    if(c==1){
        cout<<"prime";
    }else{
        cout<<"not a prime";
    }
}

int main(void){
    int a;
    cin>>a;
    prornot(a);
    return 0;

}