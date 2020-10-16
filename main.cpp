#include <iostream>
#include "sortsPointers.h"
#include "sortsPointers.cpp"

using namespace std;

template<typename T>
bool compare(const T &a, const T &b) {
    return a <= b;
}

int main() {
//    const int arraySize = 7;
//    int unsortedArray[arraySize] = {4, 3, 12, 7, 8, 1, 0};

//    const int arraySize = 8;
//    int unsortedArray[arraySize] = {2, 1, 8, 6, 4, 3, 9, 7};

    const int arraySize = 8;
    float unsortedArray[arraySize] = {2.0, 2.0, 8.0, 6.5, 4.0, 3.0, 9.2, 7.1};

//    insertionSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], [](float a, float b) { return a <= b; });
//    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], [](float a, float b) { return a <= b; });
    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], compare<float>);
    for (int i = 0; i < arraySize; i ++) {
        cout << unsortedArray[i] << " ";
    }

    return 0;
}
