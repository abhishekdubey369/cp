#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}
int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    auto start = high_resolution_clock::now();
    int linearResult = linearSearch(arr, key);
    if (linearResult != -1) {
        cout << "Linear Search: Element found at index " << linearResult << endl;
    } else {
        cout << "Linear Search: Element not found" << endl;
    }
    auto end = high_resolution_clock::now();
    // Calculate the duration
    duration<double> duration1 = end - start;
    cout << "Elapsed time: " << duration1.count() << " seconds" << endl;
    auto binStart = high_resolution_clock::now();
    int binaryResult = binarySearch(arr, key);
    if (binaryResult != -1) {
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    } else {
        cout << "Binary Search: Element not found" << endl;
    }
    auto binEnd = high_resolution_clock::now();
    // Calculate the duration
    duration<double> duration2 = binEnd - binStart;
    cout << "Elapsed time: " << duration2.count() << " seconds" << endl;
    return 0;
}
