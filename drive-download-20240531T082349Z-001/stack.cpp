/*
 * Created by: Abhishek Dubey
 * Created on: 2023-12-02
 */
#include <iostream>
#include <cstdio>

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
    void peek() const;
    ~stack();
};

stack::stack() : top(nullptr) {}


stack::~stack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void stack::push(int data) {
    Node* newNode = new (std::nothrow) Node(data);
    if (newNode == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        return;
    }
    newNode->next = top;
    top = newNode;
}


void stack::pop() {
    if (top == nullptr) {
        printf("underflow\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    printf("%c", temp->data);
    delete temp;
}

void stack::peek() const {
    if (top == nullptr) {
        printf("underflow\n");
    }
    printf("%c\n", top->data);
}


int main() {
    // Create a stack object
    stack myStack;

    // Push some elements onto the stack
    char A[10] = "Tutedude";

    int i=0;
    while(A[i]!='\0'){
        myStack.push(A[i]);
        i++;
    }
    while(i!=0){
        myStack.pop();
        i--;
    }

    return 0;
}
