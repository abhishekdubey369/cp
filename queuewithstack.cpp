/*
 * Created by: Abhishek Dubey
 * Created on: 2024-01-23
 */
#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> enqueueStack;
    std::stack<int> dequeueStack;

public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }

    int dequeue() {
        if (dequeueStack.empty()) {
            // Transfer elements from enqueue stack to dequeue stack
            while (!enqueueStack.empty()) {
                int element = enqueueStack.top();
                enqueueStack.pop();
                dequeueStack.push(element);
            }
        }

        if (dequeueStack.empty()) {
            // The queue is empty
            std::cerr << "Queue is empty." << std::endl;
            return -1; // Assuming -1 is an invalid value for the queue
        }

        int frontElement = dequeueStack.top();
        dequeueStack.pop();
        return frontElement;
    }
};

int main() {
    QueueUsingStacks myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;

    myQueue.enqueue(4);

    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;

    return 0;
}
