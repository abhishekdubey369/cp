/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-31
 */
#include <iostream>

using namespace std;

int isPrime(int x) {
    if (x <= 1) return 0; 
    if (x <= 3) return 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    /* code */
    int a;
    cin>>a;
    if(isPrime(a)){
        cout<<"IsPrime";
    }else{
        cout<<"IsNotPrime";
    }
    return 0;
}