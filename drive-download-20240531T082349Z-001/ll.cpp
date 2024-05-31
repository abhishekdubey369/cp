/*
 * Created by: Abhishek Dubey
 * Created on: 2023-11-30
 */
#include <iostream>

class node {
public:
    int* data;
    node* next;

public:
    node(int* data, node* next);
    ~node();
};

node::node(int* data, node* next) {
    this->data = data;
    this->next = next;
}

node::~node() {
    delete[] data;
    // Note: Avoid deleting 'next' here; it could lead to undefined behavior.
}

class llinked {
private:
    node* Head;

public:
    llinked();
    node* insert(int* data);
    void insertp(int* data,int position);
    void display();
    ~llinked();
    void deleteLinkedList();
    // Add other methods to manipulate the linked list if needed.
};

void llinked::insertp(int* data , int position){
    node* newNode = new node(data,nullptr);
    if(Head== nullptr and position!=0){
        printf("possible nhi hai bhai");
    } else {
        node* previous = nullptr;
        node* slider = Head;

        int i = 0;
        while (slider != nullptr && i < position) {
            previous = slider;
            slider = slider->next;
            i++;
        }

        if (i >= position) {
            newNode->next = slider;
            if (previous == nullptr) {
                // Insert at the beginning of the list
                Head = newNode;
            } else {
                previous->next = newNode;
            }
        } else{
            printf("position available nahi hai bhai node chota hai");
        }
    }
}

node* llinked::insert(int* data) {
    // Creating a new node
    node* newNode = new node(data, nullptr);

    // If the linked list is empty, make Head point to the new node
    if (Head == nullptr) {
        Head = newNode;
    } else {
        node* slider = Head;
        while (slider->next != nullptr) {
            slider = slider->next;
        }
        slider->next = newNode;
    }
    // Return the pointer to the new node
    return newNode;
}

void llinked::display() {
    node* slider = Head;
    if (slider == nullptr) {
        std::cout << "list is empty" << std::endl;
    } else {
        while (slider->next != nullptr) {
            std::cout << *slider->data << std::endl;
            slider = slider->next;
        }
        std::cout << *slider->data << std::endl;
    }
}

llinked::llinked() {
    Head = nullptr; // Initialize Head to nullptr.
}

llinked::~llinked() {
    // Destructor: You might want to implement a method to delete the entire linked list.
    deleteLinkedList();
}

void llinked::deleteLinkedList() {
    // Delete the entire linked list
    node* current = Head;
    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    // Test Case 1: Create a linked list and insert nodes
    llinked myList;

    // Insert nodes with integer data
    int data1[] = {100, 200, 300};
    int data2 = 20;
    int data3 = 30;

    node* node1 = myList.insert(data1);
    node* node2 = myList.insert(&data2);
    node* node3 = myList.insert(&data3);

    myList.display();
    myList.insertp(&data3,2);
    myList.display();

    std::cout << "success" << std::endl;

    return 0;
}
