#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include "sortsPointers.h"
#include "sortsPointers.cpp"

using namespace std;

template<typename Type>
bool compare(const Type &a, const Type &b) {
    return a <= b;
}

void calcTime() {
    const int numElements = 10000;
    vector<int> unsortedVector(numElements);
    const int numTests = 10000;
    float timeResults[numTests];
    for (int i = 1; i <= numTests; i++) {
        srand(1);
//        srand(time(NULL));
        generate(unsortedVector.begin(), unsortedVector.end(), rand);
        cout << "Test #" << i << endl;

        clock_t tStart = clock();
        quickSortWithPointers(&unsortedVector[0], &unsortedVector[numElements - 1], compare<int>);
        clock_t tStop = clock();

        double seconds = (float(tStop) - tStart) / CLOCKS_PER_SEC;
        timeResults[i - 1] = seconds;

    }

    cout << "Elements in vector: " << numElements << endl;
    cout << "Tests number: " << numTests << endl;
    float avgTime = 0.0;
    for (int i = 0; i < numTests; i++) {
        avgTime += timeResults[i];
    }
    avgTime = avgTime / numTests;
    cout << "Average time on all tests: " << avgTime << endl;
}

int main() {
//    const int arraySize = 7;
//    int unsortedArray[arraySize] = {4, 3, 12, 7, 8, 1, 0};
//    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], compare<int>);

//    const int arraySize = 8;
//    int unsortedArray[arraySize] = {2, 1, 8, 6, 4, 3, 9, 7};
//    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], compare<int>);

//    const int arraySize = 8;
//    float unsortedArray[arraySize] = {2.0, 2.0, 8.0, 6.5, 4.0, 3.0, 9.2, 7.1};
//    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], [](float a, float b) { return a <= b; });
////    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1], compare<float>);

    const int arraySize = 17;
    char unsortedArray[arraySize] = "defnoijklmcpabgh";

    for (int i = 0; i < arraySize; i++) {
        cout << unsortedArray[i] << " ";
    }
    cout << endl;

    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 2], compare<char>);

    for (int i = 0; i < arraySize; i++) {
        cout << unsortedArray[i] << " ";
    }

    return 0;
}
