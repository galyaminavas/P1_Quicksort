# P1_Quicksort

sorting results for rand int vector without insertion sort optimization with srand(1) on each test
elements in vector | number of tests | average time in seconds
------------------ | --------------- | -----------------------
1_000              | 100             | 0.00013
1_000              | 1_000           | 0.000124
1_000              | 10_000          | 0.000102299
10_000             | 100             | 0.00148
10_000             | 1_000           | 0.001534
10_000             | 10_000          | 0.00134738
100_000            | 100             | 0.01747
100_000            | 1_000           | 0.0178539
100_000            | 10_000          | 0.0174573
1_000_000          | 100             | 0.25174
1_000_000          | 1_000           | 0.255549

sorting results for rand int vector without insertion sort optimization with srand(time(NULL)) on each test
elements in vector | number of tests | average time in seconds
------------------ | --------------- | -----------------------
1_000              | 100             | 0.00015
1_000              | 1_000           | 0.000112
1_000              | 10_000          | 0.000100099
10_000             | 100             | 0.001542
10_000             | 1_000           | 0.001476
10_000             | 10_000          | 0.00142935
100_000            | 100             | 0.01842
100_000            | 1_000           | 0.0183919
100_000            | 10_000          | 0.0183383
1_000_000          | 100             | 0.25552
1_000_000          | 1_000           | 0.255528
