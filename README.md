# My Leetcode Playgrounds in C++
![Leetcode Stats](https://leetcode.card.workers.dev/?username=hankchen1728&theme=nord)

## How to Run
- Compiler: `Clang++`

Run the command `make <Problem ID>` to compile the .cpp file.

For example, for the problem [**0002_add_two_numbers**](./src/0002_add_two_numbers), run
```shell
# Run the following command to create the problem folder with template
$ make problem 2. Add Two Numbers
cp -r ./src/Template ./src/0002_add_two_numbers

# Compiling the source code and generating binary file
$ make 0002
Compiling binary file: bin/0002_add_two_numbers

# Then running the compilied binary file to see the result of test cases
$ ./bin/0002_add_two_numbers

# Clean all compilied files under ./bin/
$ make clean
rm -rf ./bin/*
```

## Problems
| # | Title | Solution | Difficulty | Tags |
|:-:| ----- | -------- | ---------- | ---- |
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
| 0019 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [C++](./src/0019_remove_nth_node_from_end_of_list/main.cpp) | Medium | `Linked List`,`Two Pointers` |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | [C++](./src/0020_Valid_Parentheses/main.cpp) | Easy | `String`,`Stack` |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | [C++](./src/0021_merge_two_sorted_lists/main.cpp) | Easy | `Linked List`,`Recursion` |
| 0023 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | [C++](./src/0023_Merge_k_Sorted_Lists/main.cpp) | Hard | `Linked List`,`Divide and Conquer`,`Heap (Priority Queue)`,`Merge Sort` |
| 0024 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | [C++](./src/0024_Swap_Nodes_in_Pairs/main.cpp) | Medium | `Linked List`,`Recursion` |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | [C++](./src/0031_Next_Permutation/main.cpp) | Medium | `Array`,`Two Pointers` |
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [C++](./src/0033_search_in_rotated_sorted_array/main.cpp) | Medium | `Array`, `Binary Search` |
| 0034 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [C++](./src/0034_find_first_and_last_position_of_element_in_sorted_array/) | Medium | `Array`,`Binary Search` |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C++](./src/0035_search_insert_position/main.cpp) | Easy | `Array`,`Binary Search` |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | [C++](./src/0039_Combination_Sum/main.cpp) | Medium | `Array`,`Backtracking` |
| 0043 | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | [C++](./src/0043_multiply_strings/main.cpp) | Medium | `Math`,`String`,`Simulation` |
| 0046 | [Permutations](https://leetcode.com/problems/permutations/) | [C++](./src/0046_permutations/main.cpp) | Medium | `Array`,`Backtracking` |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | [C++](./src/0053_maximum_subarray/main.cpp) | Easy | `Array`,`Divide and Conquer`,`Dynamic Programming` |
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | [C++](./src/0054_spiral_matrix/main.cpp) | Medium | `Array`,`Matrix`,`Simulation` |
| 0061 | [Rotate List](https://leetcode.com/problems/rotate-list/) | [C++](./src/0061_Rotate_List/main.cpp) | Medium | `Linked List`,`Two Pointers` |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | [C++](./src/0062_unique_paths/main.cpp) | Medium | `Math`,`Dynamic Programming`,`Combinations` |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | [C++](./src/0063_unique_paths_ii/main.cpp) | Medium | `Array`,`Dynamic Programming`,`Matrix` |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | [C++](./src/0077_combinations/main.cpp) | Easy | `Math`,`Dynamic Programming`,`Memoization` |
| 0071 | [Simplify Path](https://leetcode.com/problems/simplify-path/) | [C++](./src/0071_Simplify_Path/main.cpp) | Medium | `String`,`Stack` |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) | [C++](./src/0074_search_a_2d_matrix/main.cpp) | Medium | `Array`,`Binary Search`,`Matrix` |
| 0077 | [Combinations](https://leetcode.com/problems/combinations/) | [C++](./src/0077_combinations/main.cpp) | Medium | `Array`,`Backtracking` |
| 0078 | [Subsets](https://leetcode.com/problems/subsets/) | [C++](./src/0078_Subsets/main.cpp) | Medium | `Array`,`Backtracking`,`Bit Manipulation` |
| 0080 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [C++](./src/0080_Remove_Duplicates_from_Sorted_Array_II/main.cpp) | Medium | `Array`,`Two Pointers` |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | [C++](./src/0088_merge_sorted_array/main.cpp) | Easy | `Array`,`Two Pointers`,`Sorting` |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/) | [C++](./src/0096_unique_binary_search_trees/main.cpp) | Medium | `Math`,`Dynamic Programming`,`Tree`,`Binary Search Tree`,`Binary Tree` |
| 0115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) | [C++](./src/0115_distinct_subsequences/main.cpp) | Hard | `String`,`Dynamic Programming` |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) | [C++](./src/0116_populating_next_right_pointers_in_each_node/main.cpp) | Medium | `Tree`,`Depth-First Search`,`Breadth-first Search`,`Binary Tree` |
| 0118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | [C++](./src/0118_pascals_triangle/main.cpp) | Easy | `Array`,`Dynamic Programming` |
| 0120 | [Triangle](https://leetcode.com/problems/triangle/) | [C++](./src/0120_triangle/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](./src/0121_best_time_to_buy_and_sell_stock/main.cpp) | Easy | `Array`,`Dynamic Programming` |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | [C++](./src/0122_best_time_to_buy_and_sell_stock_ii/main.cpp) | Medium | `Array`,`Dynamic Programming`,`Greedy` |
| 0136 | [Single Number](https://leetcode.com/problems/single-number/) | [C++](./src/0136_single_number/main.cpp) | Easy | `Array`,`Bit Manipulation` |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii/) | [C++](./src/0137_single_number_ii/main.cpp) | Medium | `Array`,`Bit Manipulation` |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | [C++](./src/0141_Linked_List_Cycle/main.cpp) | Easy | `Hash Table`,`Linked List`,`Two Pointers` |
| 0147 | [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/) | [C++](./src/0147_Insertion_Sort_List/main.cpp) | Medium | `Linked List`,`Sorting` |
| 0152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | [C++](./src/0152_Maximum_Product_Subarray/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [C++](./src/0153_find_minimum_in_rotated_sorted_array/main.cpp) | Medium | `Array`,`Binary Search` |
| 0162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/) | [C++](./src/0162_find_peak_element/main.cpp) | Medium | `Array`,`Binary Search` |
| 0165 | [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/) | [C++](./src/0165_Compare_Version_Numbers/main.cpp) | Medium | `Two Pointers`,`String` |
| 0167 | [Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [C++](./src/0167_two_sum_ii_-_input_array_is_sorted/main.cpp) | Easy | `Array`,`Two Pointers`,`Binary Search` |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element/) | [C++](./src/0169_Majority_Element/main.cpp) | Easy | `Array`,`Hash Table`,`Divide and Conquer`,`Sorting`,`Counting` |
| 0171 | [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | [C++](./src/0171_Excel_Sheet_Column_Number/main.cpp) | Easy | `Math`,`String` |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | [C++](./src/0189_rotate_array/main.cpp) | Medium | `Array`,`Math`,`Two Pointers` |
| 0190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | [C++](./src/0190_reverse_bits/main.cpp) | Easy | `Divide and Conquer`,`Bit Manipulation` |
| 0191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | [C++](./src/0191_number_of_1_bits/main.cpp) | Easy | `Bit Manipulation` |
| 0198 | [House Robber](https://leetcode.com/problems/house-robber/) | [C++](./src/0198_house_robber/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) | [C++](./src/0203_remove_linked_list_elements/main.cpp) | Easy | `Linked List`,`Recursion` |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | [C++](./src/0206_reverse_linked_list/main.cpp) | Medium | `Linked List`,`Recursion` |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | [C++](./src/0213_House_Robber_II/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | [C++](./src/0215_Kth_Largest_Element_in_an_Array/main.cpp) | Medium | `Array`,`Divide and Conquer`,`Sorting`,`Heap (Priority Queue)`,`Quickselect` |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | [C++](./src/0217_contains_duplicate/main.cpp) | Easy | `Array`,`Hash Table`,`Sorting` |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | [C++](./src/0231_power_of_two/main.cpp) | Easy | `Math`,`Bit Manipulation`,`Recursion` |
| 0238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | [C++](./src/0238_Product_of_Array_Except_Self/main.cpp) | Medium | `Array`,`Prefix Sum` |
| 0258 | [Add Digits](https://leetcode.com/problems/add-digits/) | [C++](./src/0258_Add_Digits/main.cpp) | Easy | `Math`,`Simulation`,`Number Theory` |
| 0260 | [Single Number III](https://leetcode.com/problems/single-number-iii/) | [C++](./src/0260_single_number_iii/main.cpp) | Medium | `Array`,`Bit Manipulation` |
| 0278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | [C++](./src/0278_first_bad_version/main.cpp) | Easy | `Binary Search`,`Interactive`
| 0282 | [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | [C++](./src/0282_expression_add_operators/main.cpp) | Hard | `Math`,`String`,`Backtracking` |
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | [C++](./src/0283_move_zeroes/main.cpp) | Easy | `Array`,`Two Pointers` |
| 0328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | [C++](./src/0328_Odd_Even_Linked_List/main.cpp) | Medium | `Linked List` |
| 0331 | [Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/) | [C++](./src/0331_verify_preorder_serialization_of_a_binary_tree/main.cpp) | Medium | `String`,`Stack`,`Tree`,`Binary Tree` |
| 0338 | [Counting Bits](https://leetcode.com/problems/counting-bits/) | [C++](./src/0338_Counting_Bits/main.cpp) | Easy | `Dynamic Programming`,`Bit Manipulation` |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string/) | [C++](./src/0344_reverse_string/main.cpp) | Easy | `Two Pointers`,`String`,`Recursion` |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | [C++](./src/0347_Top_K_Frequent_Elements/main.cpp) | Medium | `Array`,`Hash Table`,`Divide and Conquer`,`Sorting`,`Heap (Priority Queue)`,`Bucket Sort`,`Counting`,`Quickselect` |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | [C++](./src/0350_intersection_of_two_arrays_ii/main.cpp) | Easy | `Array`,`Hash Table`,`Two Pointers`,`Binary Search`,`Sorting` |
| 0368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/) | [C++](./src/0368_largest_divisible_subset/main.cpp) | Medium | `Array`,`Math`,`Dynamic Programming`,`Sorting` |
| 0374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | [C++](./src/0374_Guess_Number_Higher_or_Lower/main.cpp) | Easy | `Binary Search`,`Interactive` |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | [C++](./src/0378_Kth_Smallest_Element_in_a_Sorted_Matrix/main.cpp) | Medium | `Array`,`Binary Search`,`Sorting`,`Heap (Priority Queue)`,`Matrix` |
| 0389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/) | [C++](./src/0389_Find_the_Difference/main.cpp) | Easy | `Hash Table`,`String`,`Bit Manipulation`,`Sorting` |
| 0413 | [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) | [C++](./src/0413_arithmetic_slices/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | [C++](./src/0416_Partition_Equal_Subset_Sum/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0438 | [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | [C++](./src/0438_Find_All_Anagrams_in_a_String/main.cpp) | Medium | `Hash Table`,`String`,`Sliding Window` |
| 0441 | [Arranging Coins](https://leetcode.com/problems/arranging-coins/) | [C++](./src/0441_arranging_coins/main.cpp) | Medium | `Math`,`Binary Search` |
| 0442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | [C++](./src/0442_Find_All_Duplicates_in_an_Array/main.cpp) | Medium | `Array`,`Hash Table` |
| 0448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | [C++](./src/0448_find_all_numbers_disappeared_in_an_array/main.cpp) | Easy | `Array`,`Hash Table` |
| 0454 | [4Sum II](https://leetcode.com/problems/4sum-ii/) | [C++](./src/0454_4Sum_II/main.cpp) | Medium | `Array`,`Hash Table` |
| 0461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | [C++](./src/0461_Hamming_Distance/main.cpp) | Easy | `Bit Manipulation` |
| 0485 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) | [C++](./src/0485_max_consecutive_ones/main.cpp) | Easy | `Array` |
| 0525 | [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | [C++](./src/0525_Contiguous_Array/main.cpp) | Medium | `Array`,`Hash Table`,`Prefix Sum` |
| 0532 | [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | [C++](./src/0532_K-diff_Pairs_in_an_Array/main.cpp) | Medium | `Array`,`Hash Table`,`Two Pointers`,`Binary Search`,`Sorting` |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/) | [C++](./src/0540_Single_Element_in_a_Sorted_Array/main.cpp) | Medium | `Array`,`Binary Search` |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix/) | [C++](./src/0542_01_matrix/main.cpp) | Medium | `Array`,`Dynamic Programming`,`Breadth-first Search`,`Matrix` |
| 0557 | [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/) | [C++](./src/0557_reverse_words_in_a_string_iii/main.cpp) | Easy | `Two Pointers`,`String` |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | [C++](./src/0560_subarray_sum_equals_K/main.cpp) | Medium | `Hash Table`,`Prefix Sum`|
| 0566 | [Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/) | [C++](./src/0566_reshape_the_matrix/main.cpp) | Easy | `Array`,`Matrix`,`Simulation` |
| 0567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | [C++](./src/0567_permutation_in_string/main.cpp) | Medium | `Hash Table`,`Two Pointers`,`String`,`Sliding Window`|
| 0668 | [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) | [C++](./src/0668_kth_smallest_number_in_multiplication_table/main.cpp) | Hard | `Binary Search` |
| 0680 | [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) | [C++](./src/0680_Valid_Palindrome_II/main.cpp) | Easy | `Two Pointers`,`String`,`Greedy` |
| 0695 | [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | [C++](./src/0695_max_area_of_island/main.cpp) | Medium | `Array`,`Depth-First Search`,`Breadth-first Search`,`Union Find`,`Matix` |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | [C++](./src/0703_Kth_Largest_Element_in_a_Stream/main.cpp) | Easy | `Tree`,`Design`,`Binary Search Tree`,`Heap (Priority Queue)`,`Binary Tree`,`Data Stream`|
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search/) | [C++](./src/0704_binary_search/main.cpp) | Easy | `Array`,`Binary Search` |
| 0733 | [Flood Fill](https://leetcode.com/problems/flood-fill/) | [C++](./src/0733_flood_fill/main.cpp) | Easy | `Array`,`Depth-First Search`,`Breadth-first Search`,`Matrix` |
| 0739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) | [C++](./src/0739_daily_temperatures/main.cpp) | Medium | `Array`,`Stack`,`Monotonic Stack` |
| 0740 | [Delete and Earn](https://leetcode.com/problems/delete-and-earn/) | [C++](./src/0740_Delete_and_Earn/main.cpp) | Medium | `Array`,`Hash Table`,`Dynamic Programming` |
| 0764 | [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/) | [C++](./src/0764_largest_plus_sign/main.cpp) | Medium | `Array`,`Dynamic Programming` |
| 0784 | [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | [C++](./src/0784_letter_case_permutation/main.cpp) | Medium | `String`,`Backtracking`,`Bit Manipulation` |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/) | [C++](./src/0797_All_Paths_From_Source_to_Target/main.cpp) | Medium | `Backtracking`,`Depth-First Search`,`Breadth-First Search`,`Graph` |
| 0799 | [Champagne Tower](https://leetcode.com/problems/champagne-tower/) | [C++](./src/0799_Champagne_Tower/main.cpp) | Medium | `Dynamic Programming` |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | [C++](./src/0876_middle_of_the_linked_list/main.cpp) | Easy | `Linked List`,`Two Pointers` |
| 0878 | [Nth Magical Number](https://leetcode.com/problems/nth-magical-number/) | [C++](./src/0878_Nth_Magical_Number/main.cpp) | `Hard` | `Math`,`Binary Search` |
| 0917 | [Reverse Only Letters](https://leetcode.com/problems/reverse-only-letters/) | [C++](./src/0917_reverse_only_letters/main.cpp) | Easy | `Two Pointers`,`String` |
| 0923 | [3Sum With Multiplicity](https://leetcode.com/problems/3sum-with-multiplicity/) | [C++](./src/0923_3Sum_With_Multiplicity/main.cpp) | Medium | `Array`,`Hash Table`,`Two Pointers`,`Sorting`,`Counting` |
| 0940 | [Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/) | [C++](./src/0940_distinct_subsequences_ii/main.cpp) | Hard | `String`, `Dynamic Programming` |
| 0976 | [Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/) | [C++](./src/0976_Largest_Perimeter_Triangle/main.cpp) | Easy | `Array`,`Math`,`Greedy`,`Sorting` |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | [C++](./src/0977_squares_of_a_sorted_array/main.cpp) | Easy | `Array`,`Two Pointers`,`Sorting`|
| 0978 | [Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray/) | [C++](./src/0978_longest_turbulent_subarray/main.cpp) | Medium | `Array`,`Dynamic Programming`,`Sliding Window` |
| 0980 | [Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) | [C++](./src/0980_Unique_Paths_III/main.cpp) | Hard | `Array`,`Backtracking`,`Bit Manipulation`,`Matrix` |
| 0986 | [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | [C++](./src/0986_Interval_List_Intersections/main.cpp) | Medium | `Array`,`Two Pointers` |
| 0994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | [C++](./src/0994_rotting_oranges/main.cpp) | Medium | `Array`,`Breadth-first Search`,`Matrix` |
| 1046 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) | [C++](./src/1046_Last_Stone_Weight/main.cpp) | Easy | `Array`,`Heap (Priority Queue)` |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | [C++](./src/1137_n-th_tribonacci_number/main.cpp) | Easy | `Math`,`Dynamic Programming`,`Memoization` |
| 1189 | [Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/) | [C++](./src/1189_maximum_number_of_balloons/main.cpp) | Easy | `Hash Table`,`String`,`Counting` |
| 1217 | [Minimum Cost to Move Chips to The Same Position](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/) | [C++](./src/1217_Minimum_Cost_to_Move_Chips_to_The_Same_Position/main.cpp) | Easy | `Array`,`Math`,`Greedy` |
| 1275 | [Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/) | [C++](./src/1275_find_winner_on_a_tic_tac_toe_game/main.cpp) | Easy | `Array`,`Hash Table`,`Matrix`,`Simulation` |
| 1281 | [Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) | | [C++](./src/1281_Subtract_the_Product_and_Sum_of_Digits_of_an_Integer/main.cpp) | Easy | `Math` |
| 1288 | [Remove Covered Intervals](https://leetcode.com/problems/remove-covered-intervals/) | [C++](./src/1288_Remove_Covered_Intervals/main.cpp) | Medium | `Array`,`Sorting` |
| 1290 | [Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/) | [C++](./src/1290_Convert_Binary_Number_in_a_Linked_List_to_Integer/main.cpp) | Easy | `Linked List`,`Math` |
| 1293 | [Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) | [C++](./src/1293_shortest_path_in_a_grid_with_obstacles_elimination/main.cpp) | Hard | `Array`,`Breadth-first Search`,`Matrix` |
| 1306 | [Jump Game III](https://leetcode.com/problems/jump-game-iii/) | [C++](./src/1306_Jump_Game_III/main.cpp) | Medium | `Array`,`Depth-First Search`,`Breadth-First Search` |
| 1328 | [Break a Palindrome](https://leetcode.com/problems/break-a-palindrome/) | [C++](./src/1328_break_a_palindrome/main.cpp) | Medium | `String`,`Greedy` |
| 1359 | [Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/) | [C++](./src/1359_Count_All_Valid_Pickup_and_Delivery_Options/main.cpp) | Hard | `Math`,`Dynamic Programming`,`combinations` |
| 1413 | [Minimum Value to Get Positive Step by Step Sum](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/) | [C++](./src/1413_minimum_value_to_get_positive_step_by_step_sum/main.cpp) | Easy | `Array`,`Prefix Sum` |
| 1446 | [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/) | [C++](./src/1446_Consecutive_Characters/main.cpp) | Easy | `String` |
| 1491 | [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/) | [C++](./src/1491_Average_Salary_Excluding_the_Minimum_and_Maximum_Salary/main.cpp) | Easy | `Array`,`Sorting` |
| 1523 | [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/) | [C++](./src/1523_Count_Odd_Numbers_in_an_Interval_Range/main.cpp) | Easy | `Math` |
| 1672 | [Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/) | [C++](./src/1672_Richest_Customer_Wealth/main.cpp) | Easy | `Array`, `Matrix` |
| 1679 | [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/) | [C++](./src/1679_max_mumber_of_K-sum_pairs/main.cpp) | Medium | `Array`,`Hash Table`,`Two Pointers`,`Sorting`|
| 1711 | [Count Good Meals](https://leetcode.com/problems/count-good-meals/) | [C++](./src/1711_count_good_meals/main.cpp) | Medium | `Array`, `Hash Table` |
| 1721 | [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) | [C++](./src/1721_Swapping_Nodes_in_a_Linked_List/main.cpp) | Medium | `Linked List`,`Two Pointers` |
| 1987 | [Number of Unique Good Subsequences](https://leetcode.com/problems/number-of-unique-good-subsequences/) | [C++](./src/1987_number_of_unique_good_subsequences/main.cpp) | Hard | `String`,`Dynamic Programming` |

## References
1. [What are the environments for the programming languages?](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)

<!-- <style> -->
<!-- red    { color: rgb(255,55,95) } -->
<!-- yellow { color: rgb(255,192,30) } -->
<!-- olive  { color: rgb(0,184,163) } -->
<!-- </style> -->
