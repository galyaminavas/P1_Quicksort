#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include "Sorts/sortsPointers.h"

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
        sort(&unsortedVector[0], &unsortedVector[numElements - 1], compare<int>);
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
    const int arraySize1 = 7;
    int unsortedArray1[arraySize1] = {4, 3, 12, 7, 8, 1, 0};
    for (int i = 0; i < arraySize1; i++) {
        cout << unsortedArray1[i] << " ";
    }
    cout << endl;
    sort(&unsortedArray1[0], &unsortedArray1[arraySize1 - 1], compare<int>);
    for (int i = 0; i < arraySize1; i++) {
        cout << unsortedArray1[i] << " ";
    }
    cout << endl << endl;

    const int arraySize2 = 8;
    int unsortedArray2[arraySize2] = {2, 1, 8, 6, 4, 3, 9, 7};
    for (int i = 0; i < arraySize2; i++) {
        cout << unsortedArray2[i] << " ";
    }
    cout << endl;
    sort(&unsortedArray2[0], &unsortedArray2[arraySize2 - 1], compare<int>);
    for (int i = 0; i < arraySize2; i++) {
        cout << unsortedArray2[i] << " ";
    }
    cout << endl << endl;

    const int arraySize3 = 8;
    float unsortedArray3[arraySize3] = {2.0, 2.0, 8.0, 6.5, 4.0, 3.0, 9.2, 7.1};
    for (int i = 0; i < arraySize3; i++) {
        cout << unsortedArray3[i] << " ";
    }
    cout << endl;
    sort(&unsortedArray3[0], &unsortedArray3[arraySize3 - 1], [](float a, float b) { return a <= b; });
    for (int i = 0; i < arraySize3; i++) {
        cout << unsortedArray3[i] << " ";
    }
    cout << endl << endl;

    const int arraySize4 = 8;
    float unsortedArray4[arraySize4] = {2.0, 2.0, 8.0, 6.5, 4.0, 3.0, -9.2, 0.0};
    for (int i = 0; i < arraySize4; i++) {
        cout << unsortedArray4[i] << " ";
    }
    cout << endl;
    sort(&unsortedArray4[0], &unsortedArray4[arraySize4 - 1], compare<float>);
    for (int i = 0; i < arraySize4; i++) {
        cout << unsortedArray4[i] << " ";
    }
    cout << endl << endl;

    const int arraySize5 = 17;
    char unsortedArray5[arraySize5] = "defnoijklmcpabgh";
    for (int i = 0; i < arraySize5; i++) {
        cout << unsortedArray5[i] << " ";
    }
    cout << endl;
    sort(&unsortedArray5[0], &unsortedArray5[arraySize5 - 2], compare<char>);
    for (int i = 0; i < arraySize5; i++) {
        cout << unsortedArray5[i] << " ";
    }

    return 0;
}
