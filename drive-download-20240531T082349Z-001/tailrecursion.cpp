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
    cout<<n<<endl;
    head(n-1);
}

int main() {
    /* code */
    head(10);
    return 0;
}