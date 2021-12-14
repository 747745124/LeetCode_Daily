### Background

A modern CPU, single core and single threaded, without SIMD(vectorization), usually has a computing power of ==2Ghz==( i.e. $$2 * 10^9$$  of ops )

### Overhead:

memory access/branching makes it even slower

### Large constant factor:

unordered_set O(1)  can be even slower than set O(logn) when n is 128, as the constant factor of O(1) often holds at 100 or larger

### Rough estimation:

$$10^6 -10^7$$ ops/sec



### 1. inputSize = 10~20

Combination$$(O(2^n))$$

Permutation$$(O(n!))$$

#### Search Algorithm

### 2.inputSize = 10~50

$$O(n^4)$$

### 3.inputSize = 100~200

$$O(n^3)$$

### 4.inputSize = 100~1000

$O(n^2)$

### 

### 2.3.4 : DP, shortest graph, dense graph



### 5.inputSize = 1000~10^6

$O(nlogn)$

1.heap 2.divide and conquer 3.queue



### 6.inputSize = 10^7

$$O(n)$$ 

DP, graph traversal, tree traversal



### 7.inputSize = 10^9

$O(sqrt(n))$

prime, square sum



### 8.inputSize = 10^9

$O(logn)$

binary search



### 9.inputSize = 10^9

$O(1)$

Math Induction



![IMG_8BE664F77AB3-1](/Users/naoyuki/Downloads/IMG_8BE664F77AB3-1.jpeg)