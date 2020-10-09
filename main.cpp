#include <iostream>

using namespace std;

//template <typename T>
//void sort(T *first, T *last) {
//
//}

void swap(int &a, int &b) {
    int t = b;
    b = a;
    a = t;
}

void insertionSort(int array[], int arraySize) {
    for (int i = 1; i < arraySize; i++) {
        // инвариант: sorted(array, 0, i - 1)
        // && perm(a, old_a)
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
            // ивариант: sorted(array, j, i)
            // && array[i] <= array[j, i] - текущий элемент <= всех элементов в правой (сдвинутой) части
            // && o <= j <= i <= arraySize - 1
        }
    }
}

int partition(int array[], int left, int right) {
    int x = array[left];
    int lessThanXBorder = left;
    for (int moreThanXBorder = left + 1; moreThanXBorder <= right; moreThanXBorder++) {
        // ивариант: array[k] <= x для всех left + 1 <= k <= j
        // && array[k] > x для всех j + 1 <= k <= moreThanXBorder
        if (array[moreThanXBorder] <= x) {
            lessThanXBorder++;
            swap(array[moreThanXBorder], array[lessThanXBorder]);
        }
    }
    swap(array[left], array[lessThanXBorder]);
    return lessThanXBorder;
}

int findMedian(int left, int middle, int right) {
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

void findMedianAndSwap(int &left, int &middle, int &right) {
    if (left <= middle) {
        if (right <= left)
            return;
        else if (middle <= right) {
            swap(left, middle);
        }
        else {
            swap(left, right);
        }
    } else {
        if (left <= right)
            return;
        else if (right <= middle) {
            swap(left, middle);
        }
        else {
            swap(left, right);
        }
    }
}

void quickSort(int array[], int left, int right) {
    if (left >= right)
        return;
    int middle = (right - left) / 2;
    findMedianAndSwap(array[left], array[middle], array[right]);
    int m = partition(array, left, right);
    quickSort(array, left, m - 1);
    quickSort(array, m + 1, right);
}

int main() {
    //const int arraySize = 7;
    //int unsortedArray[arraySize] = {4, 3, 12, 7, 8, 1, 0};

    const int arraySize = 8;
    int unsortedArray[arraySize] = {2, 1, 8, 6, 4, 3, 9, 7};

    //insertionSort(unsortedArray, arraySize);
    quickSort(unsortedArray, 0, arraySize - 1);

    for (int i = 0; i < arraySize; i ++) {
        cout << unsortedArray[i] << " ";
    }

    return 0;
}
