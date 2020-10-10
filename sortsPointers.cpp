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
    quickSortStart:

    if (leftPointer >= rightPointer)
        return;

    // first optimization: choose pivot as median of left border, right border and median
    int shiftToMiddle = (rightPointer - leftPointer) / 2;
    Type *middle = leftPointer + shiftToMiddle;
    findMedianAndSwapWithPointers(*leftPointer, *middle, *rightPointer);

    // second optimization: tail call elimination
    Type *mPointer = partitionWithPointers(leftPointer, rightPointer);
    if (mPointer - leftPointer > rightPointer - mPointer) {
        quickSortWithPointers(mPointer + 1, rightPointer);
        // iterative sort of (leftPointer, mPointer - 1);
        rightPointer = mPointer - 1;
        goto quickSortStart;
    } else {
        quickSortWithPointers(leftPointer, mPointer - 1);
        // iterative sort of (mPointer + 1, rightPointer);
        leftPointer = mPointer + 1;
        goto quickSortStart;
    }
}
