# My Leetcode Playgrounds in C++

## How to Run
- Compiler: `Clang++`

Run the command `make <Problem ID>` to compile the .cpp file.

For example, for the problem [**0002_add_two_numbers**](./src/0002_add_two_numbers), run
```sh
$ make 0002
Compiling binary file: bin/0002_add_two_numbers

# Then running the compilied binary file to see the result of test cases
$ ./bin/0002_add_two_numbers

# Clean all compilied files under ./bin/
$ make clean
```

## Problems
| # | Title | Solution | Difficulty | Tags |
| :-:| ----- | -------- | ---------- | ----|
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | [C++](./src/0001_Two_Sum/main.cpp) | Easy | `Array`,`Hash Table` |
| 0002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | [C++](./src/0002_add_two_numbers/main.cpp) | Medium | `Linked List`,`Recursion` |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](./src/0003_longest_substring_without_repeating_characters/main.cpp) | Medium | `Hash Table`,`Sliding Window` |
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [C++](./src/0004_median_of_two_sorted_arrays) | Hard | `Array`,`Binary Search`,`Divide and Conquer` |
| 0005 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [C++](./src/0005_longest_palindromic_substring/main.cpp) | Medium | `Dynamic Programming` |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | [C++](./src/0206_reverse_linked_list) | Medium | `Linked List`,`Recursion` |
| 0331 | [Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/) | [C++](./src/0331_verify_preorder_serialization_of_a_binary_tree) | Medium | `String`,`Stack`,`Tree`,`Binary Tree` |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | [C++](./src/0560_subarray_sum_equals_K/main.cpp) | Medium | `Hash Table`,`Prefix Sum`|
| 0764 | [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/) | [C++](./src/0764_largest_plus_sign/) | Medium | `Array`,`Dynamic Programming` |
| 1679 | [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/) | [C++](./src/1679_max_mumber_of_K-sum_pairs) | Medium | `Array`,`Hash Table`,`Two Pointers`,`Sorting`|
| 1711 | [Count Good Meals](https://leetcode.com/problems/count-good-meals/) | [C++](./src/1711_count_good_meals) | Medium | `Array`, `Hash Table` |

## References
1. [What are the environments for the programming languages?](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)

<!-- <style> -->
<!-- red    { color: rgb(255,55,95) } -->
<!-- yellow { color: rgb(255,192,30) } -->
<!-- olive  { color: rgb(0,184,163) } -->
<!-- </style> -->
