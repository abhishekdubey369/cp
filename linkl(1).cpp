// #include <corecrt_malloc.h>
#include<iostream>

using namespace std;


class LL
{
    private:
        struct node 
        {
            int value;
            node* next;
            node(int v_) :value(v_), next(nullptr) {};
        };
        node* head;

    public:
        LL() 
        {
            head = nullptr;
        }
        void print() 
        {
            node* temp = head;
            while (temp) 
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }
        void insert_sorted_order(int v_) 
        {
            if (!head)
                head = new node(v_);
            else
            {
                node* insert = new node(v_);
                node** temp = &head;
                while ((*temp) && insert->value > (*temp)->value)
                    temp = &(*temp)->next;
                insert->next = (*temp);
                (*temp) = insert;
            }
        }

        void remove(int v_)
        {
            node** temp = &head;
            while ((*temp)->value != v_)
                temp = &(*temp)->next;
            node* d = (*temp);
            (*temp) = (*temp)->next;
            delete d;
        }

        void insertPos(int v_,int n)//single pointer
        {
            if (head==nullptr || n==0)
                head = new node(v_);
            else
            {
                node* temp = head;
                while (n!=0) {
                    if(temp->next!=nullptr){
                        temp = temp->next;
                    }else{
                        temp->next = new node(-1);
                    }
            n--;
        }
        temp->next = new node(v_);
            }
        }
};


int main(void){
    int n;
    LL linkL;
    int data1 = 100;
    int data2 = 20;
    int data3 = 30;

    linkL.insertPos(data1,0);
    linkL.insertPos(data2,1);
    linkL.insertPos(data3,3);
    linkL.insertPos(10,9);
    linkL.print();

    return 0;
}