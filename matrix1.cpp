/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-23
 */
#include <iostream>
#include <vector>
using namespace std;
bool isToeplitz(vector<vector<int>> matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] != matrix[i - 1][j - 1]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  if (isToeplitz(matrix)) {
    cout << "The matrix is Toeplitz" << endl;
  } else {
    cout << "The matrix is not Toeplitz" << endl;
  }
  return 0;
}
