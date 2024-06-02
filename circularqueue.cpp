/*
 * Created by: Abhishek Dubey
 * Created on: 2024-01-23
 */
#include <iostream>
using namespace std;

const int MAX_SIZE = 5; 

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int FRONT, REAR;

public:
    CircularQueue() : FRONT(-1), REAR(-1) {}

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        // Increment REAR and insert the element
        REAR = (REAR + 1) % MAX_SIZE;
        arr[REAR] = value;

        // If it's the first element, also set FRONT to 0
        if (FRONT == -1) {
            FRONT = 0;
        }

        cout << "Enqueued: " << value << " ";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // If it's the last element, reset FRONT and REAR
        if (FRONT == REAR) {
            FRONT = REAR = -1;
        } else {
            // Increment FRONT to dequeue
            FRONT = (FRONT + 1) % MAX_SIZE;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Assuming -1 is an invalid value
        }

        return arr[FRONT];
    }

    bool isEmpty() {
        return FRONT == -1;
    }

    bool isFull() {
        return (REAR + 1) % MAX_SIZE == FRONT;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    cout << "Front: " << cq.front() << " ";

    cq.dequeue();
    cq.dequeue();

    cout << "Front: " << cq.front() << " ";

    cq.enqueue(4);
    cq.enqueue(5);

    cq.enqueue(6);

    return 0;
}
