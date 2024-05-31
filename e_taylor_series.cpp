#include<iostream>

using namespace std;
double e_taylor(int a,int b){
    static double s=1;
    if(b==0){
        return s;
    }else{
        s=1+a*s/b;
        return e_taylor(a,b-1);
        
    }

}

int main(void){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<e_taylor(a,b);
    return 0;

}