#include<iostream>

using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void sortornot(struct Array *array){
    int sn=0;
    cout<<"with out sorted ";
    for(int i=0;i<array->size;i++){
        cout<<array->A[i]<<" ";
        if(array->A[i]>array->A[i+1]){
            sn=1;
        }
    }
    cout<<endl;
    if(sn==1){
        for(int i=0;i<array->size;i++){
            int t=0;
            for(int j=0;j<array->size-1;j++){
                if(array->A[i]<array->A[j]){
                    t= array->A[i];
                    array->A[i]=array->A[j];
                    array->A[j]=t;
                }
            }
        }
    }
    cout<<"after sorting ";
    for(int i=0;i<array->size;i++){
        cout<<array->A[i]<<" ";
    }
    cout<<endl;
}

int main(void){

    struct Array arr1 = {{10,9,18,16,15},5,10};
    sortornot(&arr1);
    return 0;
}