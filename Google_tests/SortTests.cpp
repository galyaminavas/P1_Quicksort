#include "gtest/gtest.h"
#include "sortsPointers.h"
#include <vector>

// Tests sort on array of one element.
TEST(testSort, singleInt) {
    int arrayInit[] = {4};
    int arrayCheck[] = {4};
    sort(&arrayInit[0], &arrayInit[0], [](int a, int b) { return a <= b; });
    ASSERT_EQ(*arrayInit, *arrayCheck);
}

TEST(testSort, singleVector) {
    std::vector<int> vectorInit(1, 15);
    std::vector<int> vectorCheck(1, 15);
    sort(&vectorInit[0], &vectorInit[0], [](int a, int b) { return a <= b; });
    ASSERT_EQ(vectorInit, vectorCheck);
}

// Tests sort on array of multiple equal elements.
TEST(testSort, equalInts) {
    int arraySize = 9;
    int arrayInit[] = {42, 42, 42, 42, 42, 42, 42, 42, 42};
    int arrayCheck[] = {42, 42, 42, 42, 42, 42, 42, 42, 42};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

TEST(testSort, equalVector) {
    std::vector<int> vectorInit(10, 35);
    std::vector<int> vectorCheck(10, 35);
    sort(&vectorInit[0], &vectorInit[0], [](int a, int b) { return a <= b; });
    ASSERT_EQ(vectorInit, vectorCheck);
}

//Tests sort on a sorted array.
TEST(testSort, sortedInt) {
    int arraySize = 9;
    int arrayInit[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrayCheck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Tests sort on a reverse order sorted array.
TEST(testSort, sortedReverse) {
    int arraySize = 9;
    int arrayInit[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrayCheck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Test with duplicated values.
TEST(testSort, duplicatesInt) {
    int arraySize = 8;
    int arrayInit[] = {8, 3, 7, 9, 6, 1, 9, 10 };
    int arrayCheck[] = {1, 3, 6, 7, 8, 9, 9, 10};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

TEST(testSort, duplicatesInt2) {
    int arraySize = 17;
    int arrayInit[] = {9, 03, 83, 9, 2, 0, 1, 65, 2, 822, 9, 11, 22, 3, 3, 3, 47 };
    int arrayCheck[] = {0, 1, 2, 2, 3, 3, 3, 3, 9, 9, 9, 11, 22, 47, 65, 83, 822};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Test with big values.
TEST(testSort, bigInt) {
    int arraySize = 7;
    int arrayInit[] = {8, 2, 78, 89289000, 11, 0, 340};
    int arrayCheck[] = {0, 2, 8, 11, 78, 340, 89289000};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Test with negative value.
TEST(testSort, negativeInt) {
    int arraySize = 8;
    int arrayInit[] = {9, 0, 1, 17, 91, 0, 178, -6};
    int arrayCheck[] = {-6, 0, 0, 1, 9, 17, 91, 178};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Test with all negative values.
TEST(testSort, negatives) {
    int arraySize = 8;
    int arrayInit[] = {-3, -2, -1, -9, -5, -1, -19, -33};
    int arrayCheck[] = {-33, -19, -9, -5, -3, -2, -1, -1};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Test with negatives, zeros, and positives.
TEST(testSort, negativesZerosPositives) {
    int arraySize = 11;
    int arrayInit[] = {-5, -6, -7, 0, 0, 0, 0, -8, 1, 2, 3};
    int arrayCheck[] = {-8, -7, -6, -5, 0, 0, 0, 0, 1, 2, 3};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a <= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

//Test with negatives, zeros, and positives with reverse compare function
TEST(testSort, negativesZerosPositivesReverse) {
    int arraySize = 11;
    int arrayInit[] = {-5, -6, -7, 0, 0, 0, 0, -8, 1, 2, 3};
    int arrayCheck[] = {3, 2, 1, 0, 0, 0, 0, -5, -6, -7, -8};
    sort(&arrayInit[0], &arrayInit[arraySize - 1], [](int a, int b) { return a >= b; });
    for (int i = 0; i < arraySize; i++) {
        ASSERT_EQ(arrayInit[i], arrayCheck[i]);
    }
}

// Test sort for custom class
TEST(testSort, sortForClass) {
    class Key {
    public:
        int key;
        char value;

        Key() {
            key = 0;
            value = '0';
        }

        Key(int key_, char value_) {
            key = key_;
            value = value_;
        }
    };

    Key keysInit[6];
    Key keysCheck[6];

    keysCheck[0] = Key(1, 'a');
    keysCheck[1] = Key(2, 'b');
    keysCheck[2] = Key(3, 'c');
    keysCheck[3] = Key(4, 'd');
    keysCheck[4] = Key(5, 'e');
    keysCheck[5] = Key(6, 'f');

    keysInit[0] = Key(6, 'f');
    keysInit[1] = Key(4, 'd');
    keysInit[2] = Key(5, 'e');
    keysInit[3] = Key(2, 'b');
    keysInit[4] = Key(1, 'a');
    keysInit[5] = Key(3, 'c');

//    for (int i = 0; i < 6; i++) {
//        std::cout << keysInit[i].key << " " << keysInit[i].value << "\n";
//    }
//
//    std::cout << std::endl;

    sort(&keysInit[0], &keysInit[5], [](Key a, Key b) { return a.key <= b.key; });

//    for (int i = 0; i < 6; i++) {
//        std::cout << keysInit[i].key << " " << keysInit[i].value << "\n";
//    }

    for (int i = 0; i < 6; i++) {
        ASSERT_EQ(keysInit[i].key, keysCheck[i].key);
        ASSERT_EQ(keysInit[i].value, keysCheck[i].value);
    }
}
