#include <iostream>

using namespace std;

//void sort(Type *first, Type *last) {
//
//}

template <typename Type>
void swapCustom(Type &a, Type &b) {
    Type t = b;
    b = a;
    a = t;
}

template <typename Type>
void insertionSort(Type array[], int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        // инвариант: sorted(array, 0, i - 1)
        // && perm(a, old_a)
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                swapCustom(array[j], array[j - 1]);
            }
            // ивариант: sorted(array, j, i)
            // && array[i] <= array[j, i] - текущий элемент <= всех элементов в правой (сдвинутой) части
            // && o <= j <= i <= arraySize - 1
        }
    }
}

template <typename Type>
void insertionSortWithPointers(Type *first, Type *last) {
    Type *i = first + 1;
    while (i < last + 1) {
        Type *j = i;
        while (j > first) {
            if (*j < *(j - 1)) {
                swapCustom(*j, *(j - 1));
            }
            j--;
        }
        i++;
    }
}

template <typename Type>
int partition(Type array[], int leftIndex, int rightIndex) {
    Type x = array[leftIndex];
    int lessThanXMaxIndex = leftIndex;
    for (int moreThanXMaxIndex = leftIndex + 1; moreThanXMaxIndex <= rightIndex; moreThanXMaxIndex++) {
        // ивариант: array[k] <= x для всех leftIndex + 1 <= k <= j
        // && array[k] > x для всех j + 1 <= k <= moreThanXMaxIndex
        if (array[moreThanXMaxIndex] <= x) {
            lessThanXMaxIndex++;
            swapCustom(array[moreThanXMaxIndex], array[lessThanXMaxIndex]);
        }
    }
    swapCustom(array[leftIndex], array[lessThanXMaxIndex]);
    return lessThanXMaxIndex;
}

template <typename Type>
Type findMedian(Type left, Type middle, Type right) {
    if (left <= middle) {
        if (right <= left)
            return left;
        else if (middle <= right)
            return middle;
        else
            return right;
    } else {
        if (left <= right)
            return left;
        else if (right <= middle)
            return middle;
        else
            return right;
    }
}

template <typename Type>
void findMedianAndSwap(Type &left, Type &middle, Type &right) {
    if (left <= middle) {
        if (right <= left)
            return;
        else if (middle <= right) {
            swapCustom(left, middle);
        }
        else {
            swapCustom(left, right);
        }
    } else {
        if (left <= right)
            return;
        else if (right <= middle) {
            swapCustom(left, middle);
        }
        else {
            swapCustom(left, right);
        }
    }
}

template <typename Type>
void quickSort(Type array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)
        return;
    int middle = (rightIndex - leftIndex) / 2;
    findMedianAndSwap(array[leftIndex], array[middle], array[rightIndex]);
    int mIndex = partition(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, mIndex - 1);
    quickSort(array, mIndex + 1, rightIndex);
}

template <typename Type>
void findMedianAndSwapWithPointers(Type &left, Type &middle, Type &right) {
    if (left <= middle) {
        if (right <= left)
            return;
        else if (middle <= right) {
            swapCustom(left, middle);
        }
        else {
            swapCustom(left, right);
        }
    } else {
        if (left <= right)
            return;
        else if (right <= middle) {
            swapCustom(left, middle);
        }
        else {
            swapCustom(left, right);
        }
    }
}

template <typename Type>
Type * partitionWithPointers(Type *leftPointer, Type *rightPointer) {
    Type *x = leftPointer;
    Type *lessThanXMaxPointer = leftPointer;
    for (Type *moreThanXMaxPointer = leftPointer + 1; moreThanXMaxPointer <= rightPointer; moreThanXMaxPointer++) {
        if (*moreThanXMaxPointer <= *x) {
            lessThanXMaxPointer++;
            swapCustom(*moreThanXMaxPointer, *lessThanXMaxPointer);
        }
    }
    swapCustom(*leftPointer, *lessThanXMaxPointer);
    return lessThanXMaxPointer;
}

template <typename Type>
void quickSortWithPointers(Type *leftPointer, Type *rightPointer) {
    if (leftPointer >= rightPointer)
        return;
    int shiftToMiddle = (rightPointer - leftPointer) / 2;
    Type *middle = leftPointer + shiftToMiddle;
    findMedianAndSwapWithPointers(*leftPointer, *middle, *rightPointer);
    Type *mPointer = partitionWithPointers(leftPointer, rightPointer);
    quickSortWithPointers(leftPointer, mPointer - 1);
    quickSortWithPointers(mPointer + 1, rightPointer);
}

int main() {
//    const int arraySize = 7;
//    int unsortedArray[arraySize] = {4, 3, 12, 7, 8, 1, 0};

//    const int arraySize = 8;
//    int unsortedArray[arraySize] = {2, 1, 8, 6, 4, 3, 9, 7};
    const int arraySize = 8;
    float unsortedArray[arraySize] = {2.0, 2.0, 8.0, 6.5, 4.0, 3.0, 9.2, 7.1};

//    insertionSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1]);
    quickSortWithPointers(&unsortedArray[0], &unsortedArray[arraySize - 1]);

    //insertionSort(unsortedArray, arraySize);
//    quickSort(unsortedArray, 0, arraySize - 1);

    for (int i = 0; i < arraySize; i ++) {
        cout << unsortedArray[i] << " ";
    }

    return 0;
}
