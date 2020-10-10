#ifndef P1_QUICKSORT_SORTSPOINTERS_H
#define P1_QUICKSORT_SORTSPOINTERS_H

template <typename Type>
void swapCustom(Type &a, Type &b);

template <typename Type>
void insertionSortWithPointers(Type *first, Type *last);

template <typename Type>
void findMedianAndSwapWithPointers(Type &left, Type &middle, Type &right);

template <typename Type>
Type * partitionWithPointers(Type *leftPointer, Type *rightPointer);

template <typename Type>
void quickSortWithPointers(Type *leftPointer, Type *rightPointer);

#endif //P1_QUICKSORT_SORTSPOINTERS_H
