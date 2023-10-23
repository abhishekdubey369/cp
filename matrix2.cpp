/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-23
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
  // Define a 2D matrix
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // Find the transpose of the matrix
  vector<vector<int>> transpose;
  for (int i = 0; i < matrix[0].size(); i++) {
    vector<int> row;
    for (int j = 0; j < matrix.size(); j++) {
      row.push_back(matrix[j][i]);
    }
    transpose.push_back(row);
  }
  // Print the transpose matrix
  for (int i = 0; i < transpose.size(); i++) {
    for (int j = 0; j < transpose[0].size(); j++) {
      cout << transpose[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
