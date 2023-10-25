/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-14
 */

#include <iostream>
#include <vector>

void zeroMatrix(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Arrays to keep track of rows and columns that contain zeros
    std::vector<bool> zeroRows(rows, false);
    std::vector<bool> zeroCols(cols, false);

    // Identify rows and columns containing zeros
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // Set elements in identified rows to zero
    for (int i = 0; i < rows; ++i) {
        if (zeroRows[i]) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set elements in identified columns to zero
    for (int j = 0; j < cols; ++j) {
        if (zeroCols[j]) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    std::cout << "Original Matrix:\n";
    printMatrix(matrix);

    zeroMatrix(matrix);

    std::cout << "\nZeroed Matrix:\n";
    printMatrix(matrix);

    return 0;
}

