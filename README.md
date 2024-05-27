# EMPIRICAL STUDY

This report analyzes the performance of various sorting algorithms on arrays of different sizes
that varying as 100, 1000, 10000, and 100000. The algorithm measures the execution times in
microseconds (μs). The sorting algorithms are Bubble Sort, Improved Bubble Sort, Quick Sort,
Improved Quick Sort, Merge Sort, and Selection Sort. The following excel sheet and chart
represents the comparison of the execution times of those algorithms.

## 1. Bubble Sort

It is a simple sorting algorithm which repeatedly swaps adjacent elements if they are in wrong
order. It traverses the array from left to right by comparing elements. If the higher element is on
the left, it swaps it. The process is repeated until the entire array is sorted.

## 1.1. Practical Usage

In computer graphics, it can detect tiny errors, like swapping two elements, in almost-sorted
arrays and fix them with linear complexity. It is a straightforward sorting algorithm and it is not
suitable for large data sets because of low efficiency.

## 1.2. Complexity

The time complexity of bubble sort is 𝜃(𝑛!). This algorithm is slow for large data sets and it can
also be optimized.

## 2. Improved Bubble Sort

It is the optimized version of bubble sort algorithm. If there is no swap occurred during each pass,
the algorithm terminates early. Again, it traverses the array from left to right by comparing
adjacent elements and swaps the higher element on the left. It also keeps track of whether any
swaps occurred during a pass. If no swaps occurred, it breaks the loop early.

## 2.1. Practical Usage

This version of the bubble sort is often used in educational purposes like the original bubble sort
algorithm. It helps students to understand sorting algorithms and their optimizations. For very
small data sets which means efficiency is not critical, this is also straightforward.

## 2.2. Complexity

The time complexity remains same as bubble sort algorithm as 𝑂(𝑛!) in the worst case, but it
performs better on nearly sorted data. The space complexity also remains same as bubble sort
as 𝑂( 1 ) which means no additional memory required.


## 3. Quick Sort

It is a powerful sorting algorithm based on the strategy called **Divide and Conquer**. It efficiently
rearranges elements in an array by selecting a **pivot** and partitioning the array into two
subarrays.

### 3.1. Algorithm Overview

The algorithm in this study chooses a pivot element first. There are various strategies for choosing
the pivot element. The pivot element is the last element in the array for this study. It rearranges
the array so that all elements less than or equal to the pivot are on its left, and all elements
greater than the pivot are on its right. Then it recursively applies quicksort to left and right
subarrays. At the end, it combines the sorted subarrays to obtain the final sorted array.

### 3.2. Partitioning

This is the key step in this sorting algorithm. Partitioning ensures that the pivot is placed in its
correct position. The process rearranges elements such that the pivot is in its final sorted position,
and all elements to its left are smaller, while all elements to its right are greater.

One subarray containes element less than or equal to the pivot, and the other subarray (second
one) containing elements greater than the pivot.

### 3.3. Practical Usage

This is widely used for sorting large data sets efficiently. Quick sort is commonly used in scientific
research and numerical computations. It is also suitable for information sorting since it is the
fastest sorting algorithm. Variants of this sorting algorithm can find the Kth smallest or largest
elements. Quick sort exhibits good locality of reference so that it is cache-friendly. It is popular
for various scenarios.

### 3.4. Complexity

The average time complexity is the best among comparison-based sorting algorithms which is
𝑂(𝑛log𝑛). The space complexity is 𝑂(log𝑛) for the recursive call stack.

## 4. Improved Quick Sort

It includes a modification that combines the efficiency of Quick Sort with the simplicity of
Selection Sort for small arrays.


### 4.1. Algorithm Overview

The algorithm aims to strike a balance between the strengths of Quick Sort and Selection Sort. It
uses Quick Sort for larger arrays and switches to Selection Sort when the array size falls below a
certain threshold (20 elements in this study). It optimizes performance for both large and small
data sets. The pivot selection and partitioning are similar to the standard Quick Sort.

### 4.2. Practical Usage

Selection Sort is more efficient in small sized arrays due to its simplicity and fewer comparisons.
This algorithm ensures that small arrays are sorted quickly. It uses Quick Sort for larger data sets
since Quick Sort excels in sorting large arrays. As a result, the algorithm maintains good
performance overall. It minimizes cache misses during sorting and it is also cache-friendly like
Quick Sort algorithm.

### 4.3. Complexity

The time complexity varies in this algorithm. Time complexity is 𝑂(𝑛!) for very small arrays which
are less than 20 elements due to Selection Sort. The time complexity changes to 𝑂(𝑛log𝑛) for
larger arrays due to Quick Sort. Space complexity remains same as Quick Sort which is 𝑂(log𝑛)
due to the recursive call stack.

The modified algorithm adjusts the array indices directly instead of making additional recursive
calls when switching from Quick Sort to Selection Sort. It is a valuable sorting algorithm since it is
a clever compromise between efficiency and simplicity.

## 5. Merge Sort

It is a popular sorting algorithm known for its efficiency and stability. It follows the **Divide and
Conquer** approach to sort a given array of elements.

### 5.1. Algorithm Overview

The input array is recursively divided into two halves until it can no longer be split. Then each
subarray is sorted individually using the algorithm. The sorted subarrays are then merged back
together in sorted order. This process continues until all elements from both subarrays have been
merged.

### 5.2. Practical Usage

Merge Sort can be parallelized effectively. It is suitable for parallel computing environments.
When dealing with extensive lists or arrays, merge sort outperforms simpler algorithms like
bubble sort or insertion sort. Merge Sort is a stable sorting algorithm. It maintains the relative
order of equal elements. In scenarios where stability matters, merge sort ensures that equal
elements remain in their original order.


### 5.3. Complexity

It is efficient for large data sets due to its consistent performance. It has time complexity of
𝑂(𝑛log𝑛) in both average and worst cases.

## 6. Selection Sort

It is a simple and efficient sorting algorithm that works by repeatedly finding the smallest (or
largest) element from the unsorted portion of the list and moving it to the sorted portion. The
algorithm maintains two subarrays within the original array. The first one is the **sorted subarray**
which is initially empty. The second one is the **unsorted subarray** which is initially contains the
entire array. It selects the smallest element from the unsorted subarray and swaps it with the
first element of the unsorted part in each iteration. This process continues until the entire list is
sorted.

### 6.1. Practical Usage

This algorithm is suitable for some specific conditions. It is suitable when dealing with small lists,
where the overhead of more complex algorithms (like Merge Sort or Quick Sort) is unnecessary.
It is also suitable only a limited number of swaps can be made or are required like 𝑂(𝑛).
Additionally, it is suitable in scenarios where memory write operations are costly, selection sort
minimizes the number of swaps.

### 6.2. Complexity

Its time complexity is 𝑂(𝑛!). It becomes inefficient for large lists. Selection Sort operates **in-
place**. It sorts the elements within the original array without requiring additional memory for
auxiliary data structures. It does not create any new arrays or data structures to store
intermediate results so space complexity is 𝑂( 1 ).

## Analysis

The following table represents the comparison of the algorithms. It uses the same random
created array for all algorithms during run. The algorithms taking the random array on each
sorting function call. Meaning that algorithms take random array for 10 times and calculating
average execution time of it.

![Empirical Study first case](https://github.com/ahmetksrts/Empirical-Study/blob/main/screenshots/first%20case.png)


The improved bubble sort algorithm in this study breaks loop early if the array is already sorted.
As a result, it is pretty same as Bubble Sort algorithm compare to execution time since the
algorithm takes random array (firstly given input) at each run. Likely, Improved Quick Sort
algorithm and Quick Sort algorithm are similar in terms of execution times. Because in the
Improved Quick Sort algorithm, the algorithm uses Selection Sort if the input size is less than a
threshold value of 20.




In this scenario, Merge Sort have a better sustainability among others. Bubble Sort and Improved
Bubble Sort algorithms are similar and non-efficient ones. Selection Sort is an inefficient
algorithm compare to remaining four (instead of Bubble Sort and Improved Bubble Sort)
algorithms too. It is impractical for large datasets due to their inefficiency.

In conclusion, Improved Quick Sort and Merge Sort algorithms are giving better results for large
datasets compare to others and they are also more efficient in specific input sizes. Other
algorithms can be used for smaller datasets or specific scenarios.

In the second specific case of the study, instead of giving the randomized (first generated) array
to Improved Bubble Sort algorithm as an input, the randomly created array (one variable only) is
given as an input. That enables Improved Bubble Sort algorithm to early exit during run in case
of sorted array. It decreases the consumed time from 42.2 microseconds to 4.6 microseconds
which effects positively by approximately 89.1%.

The following table and chart represent second case.

![Empirical Study second case](https://github.com/ahmetksrts/Empirical-Study/blob/main/screenshots/second%20case.png)

When we consider this chart, we can say that again in this scenario, Merge Sort gives the best
efficiency. Improved Bubble Sort algorithm seems more efficient compare to Bubble Sort
algorithm for larger data sets (input size greater than 100).

In conclusion, **Merge Sort** algorithm gives better performance for educational purposes
especially for large data sets.

## Practical Limits

**What is the biggest problem size you can run in two seconds?**
Based on the data from first case, the following discussions can be made about the largest
problem sizes that can be sorted within two seconds:

- **Bubble Sort** : It sorts 10,000 size random array within approximately 454.361 milliseconds.
    Nearly 2 seconds.
- **Improved Bubble Sort** : It sorts 10,000 size random array within approximately 464.
    milliseconds. It is similar to Bubble Sort.
- **Quick Sort** : It sorts 100,000 size random array within approximately 341.207 milliseconds.
    It can sort more than 100,000 size random array within 2 seconds.
- **Improved Quick Sort** : It can sort 100,000 sized random arrays within 341.
    milliseconds. Similar with the Quick Sort.

- **Merge Sort** : It can sort 100,000 sized random arrays within 95.1421 milliseconds. It can
    sort more than 100,000 size arrays within 2 seconds.
- **Selection Sort** : It can sort 100,000 sized random arrays within 25966.8 milliseconds which
    is 25 seconds approximately. I can also sort 10,000 sized arrays in approximately 184.
    milliseconds. So, it can sort an array size between 10,000 and 100,000 within 2 seconds.

**YouTube link**: https://youtu.be/wYMT3WVI1bc

