# 4. Median of Two Sorted Arrays
- Link: [https://leetcode.com/problems/median-of-two-sorted-arrays/](https://leetcode.com/problems/median-of-two-sorted-arrays/)

## Idea
#### a. Binary Search
Finding the median is equal to finding a **cut position**, where the array is *equally* split into **lower** and **upper half**.<br/>
Therefore here we need to find the **cut position** `mid1` and `mid2` for `num1` and `num2` respectively. <br/>
Suppose that `L1` is the number at the *left* side of `mid1`, and `R1` is that at *right* side of `mid1`, and `L2` and `R2` with the similar definition for `mid2`.

If both `R1` and `R2` are larger than `L1` and `L2`, then `mid1` and `mid2` are the correct cut positions.
```cpp
min(R1, R2) >= max(L1, L2)
// or
R1 >= L2 && R2 => L1
```
Otherwise, if `R1` is smaller than `L2`, i.e. `R1` is too small, then we need to move `mid1` to the **right** and move `mid2` to **left**.

- Reference: [Very concise O(log(min(M,N))) iterative solution with detailed explanation](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation)

#### b. Merge Two Arrays
Just merge (^_^).

## Problem Statement
<p>Given two sorted arrays <code>nums1</code> and <code>nums2</code> of size <code>m</code> and <code>n</code> respectively, return <strong>the median</strong> of the two sorted arrays.</p>

<p>The overall run time complexity should be <code>O(log (m+n))</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,3], nums2 = [2]
<strong>Output:</strong> 2.00000
<strong>Explanation:</strong> merged array = [1,2,3] and median is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2], nums2 = [3,4]
<strong>Output:</strong> 2.50000
<strong>Explanation:</strong> merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [0,0], nums2 = [0,0]
<strong>Output:</strong> 0.00000
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums1 = [], nums2 = [1]
<strong>Output:</strong> 1.00000
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> nums1 = [2], nums2 = []
<strong>Output:</strong> 2.00000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums1.length == m</code></li>
	<li><code>nums2.length == n</code></li>
	<li><code>0 &lt;= m &lt;= 1000</code></li>
	<li><code>0 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= m + n &lt;= 2000</code></li>
	<li><code>-10<sup>6</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
</ul>
