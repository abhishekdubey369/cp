/*
 * Created by: Abhishek Dubey
 * Created on: 2024-01-23
 */
#include <iostream>
#include <string>

using namespace std;
class Node {
public:
    std::string data;
    Node* next;
    Node(const std::string& x, Node* y) : data(x), next(y) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(const std::string& value);
    void dequeue();
};

void Queue::enqueue(const std::string& value) {
        Node* newNode = new Node(value, nullptr);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

void Queue::dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            Node* temp = front;
            front = front->next;
            cout<< temp->data <<endl;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

int main() {
    // Code
    Queue myQueue;

    myQueue.enqueue("hello");
    myQueue.enqueue("world");

    myQueue.dequeue();
    myQueue.dequeue();
    return 0;
}
