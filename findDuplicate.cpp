/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-27
 */
#include <iostream>
#include <unordered_set>
using namespace std;

void findDuplicates(int arr[], int n) {
    unordered_set<int> hashSet;
    bool foundDuplicate = false;

    for (int i = 0; i < n; i++) {
        if (hashSet.find(arr[i]) != hashSet.end()) {
            cout << "Duplicate found: " << arr[i] << endl;
            foundDuplicate = true;
        } else {
            hashSet.insert(arr[i]);
        }
    }

    if (!foundDuplicate) {
        cout << "No duplicates found.\n";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, n);

    return 0;
}
