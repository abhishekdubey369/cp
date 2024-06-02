/*
 * Created by: Abhishek Dubey
 * Created on: 2024-06-02
 */
#include <iostream>

using namespace std;

int head(int n){
    int sum = 0;
    if(n==0){
        return sum;
    }else{
        sum = n + head(n-1);
        return sum;
    }
    
}

int main() {
    /* code */
    cout<<head(10);
    return 0;
}