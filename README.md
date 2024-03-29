# P1_Quicksort

## Sorting results (average time in seconds) for rand int vector with srand(1) on each test

**first best**, *second best*
elements in vector | number of tests | without insertion sort optimization | with insertion sort on length <= 30 | length <= 25 | length <= 20 | length <= 15   | length <= 10 
------------------ | --------------- | ----------------------------------- | ----------------------------------- | ------------ | ------------ |  -----------   | ------------ 
1_000              | 100             | 0.00013                             | 0.00015                             | *0.00012*    | **0.0001**   | 0.00014        | 0.00013
1_000              | 1_000           | 0.000124                            | 0.000125                            | 0.000119     | **0.000102** | *0.000105*     | 0.000112
1_000              | 10_000          | 0.000102299                         | 0.000122                            | 0.000102799  | 0.000101999  |**0.0000958991**| *0.0000989991*
10_000             | 100             | *0.00148*                           | 0.00157                             | 0.00163      | 0.00155      | **0.00144**    | 0.00152
10_000             | 1_000           | 0.001534                            | 0.00162099                          | 0.00156199   | *0.001447*   | 0.001456       | **0.001391**
10_000             | 10_000          | 0.00134738                          | 0.00146796                          | 0.00141696   | 0.00134397   | *0.00133987*   | **0.00132247**
100_000            | 100             | *0.01747*                           | 0.02088                             | 0.01981      | 0.01865      | 0.01772        | **0.01715**
100_000            | 1_000           | *0.0178539*                         | 0.0204871                           | 0.019568     | 0.0184909    | 0.017933       | **0.0168931**
100_000            | 10_000          | *0.0174573*                         | 0.020543                            | 0.0195173    | 0.0185271    | 0.0176006      | **0.016937**
1_000_000          | 100             | 0.25174                             | **0.24184**                         | 0.24569      | *0.24309*    | 0.247          | 0.24901
1_000_000          | 1_000           | 0.255549                            | **0.241809**                        | 0.246845     | *0.244891*   | 0.247419       | 0.251162
10_000_000         | 10              | *12.2589*                           | 12.2863                             | **12.2499**  | 12.2879      | 12.2813        | 12.4645



## Sorting results (average time in seconds) for rand int vector with srand(time(NULL)) on each test

**first best**, *second best*
elements in vector | number of tests | without insertion sort optimization | with insertion sort on length <= 30 | length <= 25 | length <= 20 | length <= 15     | length <= 10 
------------------ | --------------- | ----------------------------------- | ----------------------------------- | ------------ | ------------ |  -----------     | ------------ 
1_000              | 100             | 0.00015                             | 0.00017                             | **0.00012**  | 0.00016      | *0.00014*        | **0.00012**
1_000              | 1_000           | 0.000112                            | 0.00014                             | 0.000116     | 0.000104     | *0.000098*       | **0.000093**
1_000              | 10_000          | *0.000100099*                       | 0.0001174                           | 0.0001097    | 0.000103299  | **0.0000977991** | 0.000105999
10_000             | 100             | 0.001542                            | 0.00181                             | 0.00171      | 0.00158      | *0.00153*        | **0.0014**
10_000             | 1_000           | *0.001476*                          | 0.00161499                          | 0.001557     | 0.001454     | 0.001452         | **0.001364**
10_000             | 10_000          | 0.00142935                          | 0.00149196                          | 0.00145946   | 0.00139867   | *0.00132627*    |**0.00131568**
100_000            | 100             | 0.01842                             | 0.02092                             | 0.02113      | 0.01943      | *0.01813*        | **0.01746**
100_000            | 1_000           | 0.0183919                           | 0.020851                            | 0.0200521    | 0.019455     | *0.018333*       | **0.017225**
100_000            | 10_000          | 0.0183383                           | 0.0208316                           | 0.0198215    | 0.0189095    | *0.0177873*      |**0.0170924**
1_000_000          | 100             | 0.25552                             | **0.24402**                         | *0.2441*     | 0.24751      | 0.24884          | 0.25356
1_000_000          | 1_000           | 0.255528                            | **0.244241**                        | *0.24599*    | 0.247032     | 0.253222         | 0.257065
10_000_000         | 10              | **12.2244**                         | *12.3925*                           | 12.7364      | 12.592       | 12.7043          | 12.7608
