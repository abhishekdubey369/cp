/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-27
 */
#include <iostream>
#include <unordered_set>
using namespace std;

void findPairWithSum(int arr[], int n, int sum) {
    unordered_set<int> hashSet;
    for (int i = 0; i < n; i++) {
        int complement = sum - arr[i];
        if (hashSet.find(complement) != hashSet.end()) {
            cout << "Pair found: (" << arr[i] << ", " << complement << ")\n";
            return;
        }
        hashSet.insert(arr[i]);
    }
    cout << "No pair found with the given sum.\n";
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 16;

    findPairWithSum(arr, n, sum);

    return 0;
}
