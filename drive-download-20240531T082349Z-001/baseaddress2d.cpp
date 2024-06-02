#include <iostream>
using namespace std;

int main() {
    int baseAddress = 100;
    int row = 8;
    int column = 6;
    int numberOfRows = 10;
    int sizeOfElement = 1;
    
    int address = baseAddress + ((column - 1) * numberOfRows + (row - 1)) * sizeOfElement;
    
    cout << "Address of arr[8][6]: " << address << endl;
    
    return 0;
}
