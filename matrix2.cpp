/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-23
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> transpose;
  cout<<"original matrix"<<endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < matrix[0].size(); i++) {
    vector<int> row;
    for (int j = 0; j < matrix.size(); j++) {
      row.push_back(matrix[j][i]);
    }
    transpose.push_back(row);
  }
  cout<<"transpose matrix"<<endl;
  for (int i = 0; i < transpose.size(); i++) {
    for (int j = 0; j < transpose[0].size(); j++) {
      cout << transpose[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
