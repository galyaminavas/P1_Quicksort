#include "sortsPointers.h"

template <typename Type>
void swapCustom(Type &a, Type &b) {
    Type t = b;
    b = a;
    a = t;
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
