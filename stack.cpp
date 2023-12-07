/*
 * Created by: Abhishek Dubey
 * Created on: 2023-12-02
 */
#include <iostream>


class Node{
    public:
        int data;
        Node* next;
        Node(int x): data(x), next(nullptr){}
};

class stack
{
private:
    Node* top;
public:
    stack();
    void push(int data);
    void pop();
    void peek();
    ~stack();
};

stack::stack()
{
    top->next = nullptr;
}

stack::~stack()
{
    delete top;
}

void stack::push(int data){
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

void stack::pop(){
    if(isEmpty()){

    }
}

int main() {
    // code
    return 0;
}