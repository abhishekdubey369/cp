/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-23
 */
#include <iostream>

class matrix{
    matrix(int *m);
    void transpose(int *m);
    ~matrix(){
        delete *m;
    };
};

matrix::matrix(int *m){

}

void matrix::transpose(){

}

int main() {
    // code
    return 0;
}