#ifndef P1_QUICKSORT_SORTSPOINTERS_H
#define P1_QUICKSORT_SORTSPOINTERS_H

template <typename Type>
void swapCustom(Type &a, Type &b);

template <typename Type, typename Compare>
void insertionSortWithPointers(Type *first, Type *last, Compare comp);

template <typename Type, typename Compare>
void findMedianAndSwapWithPointers(Type &left, Type &middle, Type &right, Compare comp);

template <typename Type, typename Compare>
Type * partitionWithPointers(Type *leftPointer, Type *rightPointer, Compare comp);

/// Quick sort function with optimizations
/// \tparam Type
/// \tparam Compare
/// \param leftPointer - pointer to the left element of the (sub)array
/// \param rightPointer - pointer to the right element of the (sub)array
/// \param comp - function defining the order of elements of type Type
template <typename Type, typename Compare>
void sort(Type *leftPointer, Type *rightPointer, Compare comp);

#endif //P1_QUICKSORT_SORTSPOINTERS_H
