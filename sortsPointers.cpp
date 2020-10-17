#include "sortsPointers.h"

template <typename Type>
void swapCustom(Type &a, Type &b) {
    Type t = b;
    b = a;
    a = t;
}

template<typename Type, typename Compare>
void insertionSortWithPointers(Type *first, Type *last, Compare comp) {
    Type *i = first + 1;
    while (i < last + 1) {
        Type *j = i;
        while (j > first) {
            if (comp(*j, *(j - 1))) {
                swapCustom(*j, *(j - 1));
            }
            j--;
        }
        i++;
    }
}

template<typename Type, typename Compare>
void findMedianAndSwapWithPointers(Type &left, Type &middle, Type &right, Compare comp) {
    if (comp(left, middle)) {
        if (comp(right, left))
            return;
        else if (comp(middle, right)) {
            swapCustom(left, middle);
        }
        else {
            swapCustom(left, right);
        }
    } else {
        if (comp(left, right))
            return;
        else if (comp(right, middle)) {
            swapCustom(left, middle);
        }
        else {
            swapCustom(left, right);
        }
    }
}

template<typename Type, typename Compare>
Type * partitionWithPointers(Type *leftPointer, Type *rightPointer, Compare comp) {
    Type *x = leftPointer;
    Type *lessThanXMaxPointer = leftPointer;
    for (Type *moreThanXMaxPointer = leftPointer + 1; moreThanXMaxPointer <= rightPointer; moreThanXMaxPointer++) {
        if (comp(*moreThanXMaxPointer, *x)) {
            lessThanXMaxPointer++;
            swapCustom(*moreThanXMaxPointer, *lessThanXMaxPointer);
        }
    }
    swapCustom(*leftPointer, *lessThanXMaxPointer);
    return lessThanXMaxPointer;
}

template<typename Type, typename Compare>
void quickSortWithPointers(Type *leftPointer, Type *rightPointer, Compare comp) {
    quickSortStart:

    if (leftPointer >= rightPointer)
        return;

    // third optimization: insertion sort for short intervals
    if (rightPointer - leftPointer < 15) {
        insertionSortWithPointers(leftPointer, rightPointer, comp);
        return;
    }

    // first optimization: choose pivot as median of left border, right border and middle
    int shiftToMiddle = (rightPointer - leftPointer) / 2;
    Type *middle = leftPointer + shiftToMiddle;
    findMedianAndSwapWithPointers(*leftPointer, *middle, *rightPointer, comp);

    // second optimization: tail call elimination
    Type *mPointer = partitionWithPointers(leftPointer, rightPointer, comp);
    if (mPointer - leftPointer > rightPointer - mPointer) {
        quickSortWithPointers(mPointer + 1, rightPointer, comp);
        // iterative sort of (leftPointer, mPointer - 1);
        rightPointer = mPointer - 1;
        goto quickSortStart;
    } else {
        quickSortWithPointers(leftPointer, mPointer - 1, comp);
        // iterative sort of (mPointer + 1, rightPointer);
        leftPointer = mPointer + 1;
        goto quickSortStart;
    }
}
