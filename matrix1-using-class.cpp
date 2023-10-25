/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-23
 */
#include <iostream>

class Matrix{
    private:
        int size;
        int *M;
    public:
        Matrix(int size){
            this.size =size;
            M = new int[size];
        }
        void set(int i, int j, int x);
        void get(int i,int j);
        void display();
        void transpose(int *m);
        ~Matrix(){
            delete []M;
        };
};

int main() {
    // code
    return 0;
}