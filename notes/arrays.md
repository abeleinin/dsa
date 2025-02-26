# Arrays

- [Advantages](#advantages)
- [Disadvantages](#disadvantages)
- [Questions](#mindful-during-interview)
- [Corner Cases](#corner-cases)
- [Techniques](#techniques)
- [Neetcode 150 Questions](#neetcode-150-questions)

## Advantages 

- Store multiple elements of the same type 
- Accessing an element is fast if you have the index

## Disadvantages

- Fixed size
- Arrays are static structures. Meaning the size is always fixed, so we cannot increase or decrease memory allocation

## Time complexity 

Operation | Big-O | Note
------|-----|------
Access | O(1) | Index access 
Search | O(n) | Linear scan
Search (sorted array) | O(log(n)) | Binary search
Insert | O(n) | Insertion requires shifting subsequent elements by one position to the right
Insert (at the end) | O(1) | Append to the end of an array doesn't shift any elements 
Remove | O(n) | Removal would require shifting subsequent elements by one position to the left
Remove (at the end) | O(1) | Drop element doesn't require shifting any elements 

## Questions

- Duplicate values in the array. 
- Bounds checking (Off-by-one errors)

## Corner Cases

- Empty array
- Array with 1 or 2 elements 
- Array with repeated elements
- Duplicated values in array
- Negative values

## Techniques 

### Sliding window

The sliding window technique involves maintaining a window of elements within the array and moving it systematically to solve a problem. It's often used for problems involving subarrays or subsequences with specific characteristics. By adjusting the window's size or position based on certain conditions, you can efficiently solve problems like finding the maximum sum of a subarray, finding the smallest subarray with a given sum, or counting distinct elements in a window.

Questions: 

- Maximum Subarray 
- Longest Substring Without Repeating Characters 
- Minimum Size Subarray Sum 
- Longest Repeating Character Replacement 
- Sliding Window Maximum 

### Two pointer 

The two-pointer technique involves using two pointers that traverse the array from different ends or starting positions. It's commonly used for problems involving searching, sorting, or finding subarrays with specific properties. By manipulating the pointers based on certain conditions, you can efficiently solve problems like finding a pair with a given sum, removing duplicates, or finding a subarray with a target sum.

Questions:

- Two Sum 
- Container With Most Water 
- Reverse String 
- Remove Duplicates from Sorted Array 
- 3Sum 

### Traversing from the right

This technique involves starting the traversal of the array from the rightmost element and moving towards the left. It's useful when the solution or the desired result depends on the elements towards the right side of the current position. For example, you might need to calculate running sums or compute some result based on future elements in the array.

Questions:

- Product of Array Except Self 
- Trapping Rain Water 
- Next Permutation 
- Jump Game II 
- Palindrome Partitioning II 

### Sorting the array

Sorting the array can help in solving various array problems. It allows you to rearrange the elements in a specific order, making it easier to search, find patterns, or solve specific tasks. Sorting algorithms like quicksort, mergesort, or heapsort are commonly used. Sorting can help in finding duplicates, identifying the largest or smallest elements, or solving problems that require comparing elements in a specific order.

Questions:

- Merge Intervals 
- Meeting Rooms I
- Valid Anagram 
- Largest Number 
- Wiggle Sort II

### Precomputation

Precomputation involves calculating and storing intermediate results or summaries before solving a problem. By precomputing certain values or aggregating information from the array, you can optimize the solution and avoid redundant computations. This technique is often used in problems that involve repetitive queries or require quick lookups based on specific conditions.

Questions: 

- Range Sum Query 
- Maximum Subarray 
- Count of Smaller Numbers After Self 
- Product of Array Except Self 
- Subarray Sum Equals K 

### Index as a hash key

In some cases, you can use the array indices as hash keys to store or access information efficiently. This technique is applicable when the array values are limited or have a specific range. By using the array indices as keys in a hash table or hash map, you can associate additional information or perform operations with a time complexity of O(1). This can be helpful for solving problems that require frequency counting, tracking occurrences, or mapping values to indices.

Questions:

- Two Sum 
- Contains Duplicate 
- Contains Duplicate II 
- First Missing Positive 
- Single Number 

### Traveling the array more than once

Some problems might require iterating over the array multiple times to solve the task. This approach involves designing a solution that makes multiple passes over the array, each time performing a different operation or considering a different aspect of the problem. By carefully structuring the iterations and considering the dependencies between different passes, you can solve problems that require complex calculations or multiple steps.

Questions:

- Rotate Array 
- Next Permutation 
- Jump Game 
- Sort Colors 
- Game of Life 

## Neetcode 150 Questions

- [Two Sum](https://leetcode.com/problems/two-sum/)
- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
- [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
- [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [3Sum](https://leetcode.com/problems/3sum/)
- [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

