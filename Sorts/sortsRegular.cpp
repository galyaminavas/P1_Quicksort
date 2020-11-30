#include "sortsRegular.h"

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
