/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-27
 */
#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapUp(int index) {
        if (index && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapUp(parent(index));
        }
    }

    void heapDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapDown(largest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

public:
    void insert(int key) {
        heap.push_back(key);
        heapUp(heap.size() - 1);
    }

    void extractMax() {
        if (heap.size() == 0) {
            cout << "Heap is empty\n";
            return;
        }
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapDown(0);
    }

    int getMax() {
        if (heap.size() == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap.front();
    }

    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;

    pq.insert(3);
    pq.insert(2);
    pq.insert(15);
    pq.insert(5);
    pq.insert(4);
    pq.insert(45);

    cout << "Max-Heap array: ";
    pq.printHeap();

    cout << "Extracting max: ";
    pq.extractMax();
    pq.printHeap();

    cout << "Current max: " << pq.getMax() << endl;

    return 0;
}
