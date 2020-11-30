#ifndef P1_QUICKSORT_SORTSREGULAR_H
#define P1_QUICKSORT_SORTSREGULAR_H

template <typename Type>
void swapCustom(Type &a, Type &b);

template <typename Type>
void insertionSort(Type array[], int arraySize);

template <typename Type>
int partition(Type array[], int leftIndex, int rightIndex);

template <typename Type>
Type findMedian(Type left, Type middle, Type right);

template <typename Type>
void findMedianAndSwap(Type &left, Type &middle, Type &right);

template <typename Type>
void quickSort(Type array[], int leftIndex, int rightIndex);

#endif //P1_QUICKSORT_SORTSREGULAR_H
