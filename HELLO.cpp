/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-14
 */
#include <iostream>
using namespace std;

int isprime(int n){
    int i=2;
    while(i!=n){
        if(n%i==0){
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    /* code */
    int n;
    cout<<"enter number";
    cin>>n;
    if(isprime(10)){
        cout<<"prime hai";
    }else{
        cout<<"nahi hai";
    }
    return 0;
}