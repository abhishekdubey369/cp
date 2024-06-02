#include<iostream>

using namespace std;
class tmatrix{
    private:
        int **A;
        int row,col;
    public:
        tmatrix(int x,int y);
        int get(int row, int col);
        void set(int row,int col, int data);
        void display();
        void istmatrix();
        ~tmatrix(){
            delete A;
        }
};
tmatrix::tmatrix(int x, int y)
{
    row=x;
    col=y;
    A = new int *[row];
    for(int i=0;i<row;i++){A[i] = new int [col];}
    }
int tmatrix::get(int row,int col){
    return A[row][col];
}

void tmatrix::set(int row,int col,int data){
    A[row][col]=data;
}
void tmatrix::display(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void tmatrix::istmatrix(){
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(A[i][j]!=A[i-1][j-1]){
                cout<<"not a toeplitz"<<endl;
                return;
            }
        }
    }
    cout<<"toeplitz"<<endl;
}

int main(void){
    tmatrix A(3,4);
    //  (1 2 3 4),(5 1 2 3),(9 5 1 2)
    A.set(0,0,1);
    A.set(0,1,2);
    A.set(0,2,3);
    A.set(0,3,4);
    A.set(1,0,5);
    A.set(1,1,1);
    A.set(1,2,2);
    A.set(1,3,3);
    A.set(2,0,9);
    A.set(2,1,5);
    A.set(2,2,1);
    A.set(2,3,2);

    A.display();
    A.istmatrix();
    return 0;
}