#include <iostream>
using namespace std;

int main() {
    int baseAddress = 1020;
    int lowerBound = 1300;
    int sizeOfElement = 2;
    int index = 1700;
    
    int address = baseAddress + (index - lowerBound) * sizeOfElement;
    
    cout << "Address of A[1700]: " << address << endl;
    
    return 0;
}
