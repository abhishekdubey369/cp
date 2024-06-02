/*
 * Created by: Abhishek Dubey
 * Created on: 2024-06-02
 */
#include <iostream>

using namespace std;

void head(int n){
    if(n==0){
        return;
    }
    head(n-1);
    cout<<n<<endl;
}

int main() {
    /* code */
    head(10);
    return 0;
}