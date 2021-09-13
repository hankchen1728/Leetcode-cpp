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
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [C++](./src/0004_median_of_two_sorted_arrays/main.cpp) | Hard | `Array`,`Binary Search`,`Divide and Conquer` |
| 0005 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [C++](./src/0005_longest_palindromic_substring/main.cpp) | Medium | `Dynamic Programming` |
| 0006 | [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) | [C++](./src/0006_zigzag_conversion/main.cpp) | Medium | `String` |
| 0007 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | [C++](./src/0007_reverse_integer/main.cpp) | Easy | `Math` |
| 0008 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | [C++](./src/0008_string_to_integer_atoi/main.cpp) | Medium| `String` |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | [C++](./src/0009_palindrome_number/main.cpp) | Easy | `Math` |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | [C++](./src/0011_container_with_most_water/main.cpp) | Medium | `Array`,`Two Pointers`,`Greedy` |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C++](./src/0035_search_insert_position/main.cpp) | Easy | `Array`,`Binary Search` |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | [C++](./src/0053_maximum_subarray/main.cpp) | Easy | `Array`,`Divide and Conquer`,`Dynamic Programming` |
| 0167 | [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [C++](./src/0167_two_sum_ii_-_input_array_is_sorted/main.cpp) | Easy | `Array`,`Two Pointers`,`Binary Search` |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | [C++](./src/0189_rotate_array/main.cpp) | Medium | `Array`,`Math`,`Two Pointers` |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | [C++](./src/0206_reverse_linked_list/main.cpp) | Medium | `Linked List`,`Recursion` |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | [C++](./src/0217_contains_duplicate/main.cpp) | Easy | `Array`,`Hash Table`,`Sorting` |
| 0278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | [C++](./src/0278_first_bad_version/main.cpp) | Easy | `Binary Search`,`Interactive`
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | [C++](./src/0283_move_zeroes/main.cpp) | Easy | `Array`,`Two Pointers` |
| 0331 | [Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/) | [C++](./src/0331_verify_preorder_serialization_of_a_binary_tree/main.cpp) | Medium | `String`,`Stack`,`Tree`,`Binary Tree` |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string/) | [C++](./src/0344_reverse_string/main.cpp) | Easy | `Two Pointers`,`String`,`Recursion` |
| 0413 | [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) | [C++](./src/0413_arithmetic_slices/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0557 | [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/) | [C++](./src/0557_reverse_words_in_a_string_iii/main.cpp) | Easy | `Two Pointers`,`String` |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | [C++](./src/0560_subarray_sum_equals_K/main.cpp) | Medium | `Hash Table`,`Prefix Sum`|
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search/) | [C++](./src/0704_binary_search/main.cpp) | Easy | `Array`,`Binary Search` |
| 0764 | [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/) | [C++](./src/0764_largest_plus_sign/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | [C++](./src/0977_squares_of_a_sorted_array/main.cpp) | Easy | `Array`,`Two Pointers`,`Sorting`|
| 1679 | [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/) | [C++](./src/1679_max_mumber_of_K-sum_pairs/main.cpp) | Medium | `Array`,`Hash Table`,`Two Pointers`,`Sorting`|
| 1711 | [Count Good Meals](https://leetcode.com/problems/count-good-meals/) | [C++](./src/1711_count_good_meals/main.cpp) | Medium | `Array`, `Hash Table` |

## References
1. [What are the environments for the programming languages?](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)

<!-- <style> -->
<!-- red    { color: rgb(255,55,95) } -->
<!-- yellow { color: rgb(255,192,30) } -->
<!-- olive  { color: rgb(0,184,163) } -->
<!-- </style> -->
