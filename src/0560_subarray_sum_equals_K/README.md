# 560. Subarray Sum Equals K
- Link: [https://leetcode.com/problems/subarray-sum-equals-k/](https://leetcode.com/problems/subarray-sum-equals-k/)

## Problem Statement
<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the total number of continuous subarrays whose sum equals to <code>k</code></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1], k = 2
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3], k = 3
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>-10<sup>7</sup> &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>

## Hints
1. Will Brute force work here? Try to optimize it.
2. Can we optimize it by using some extra space?
3. What about storing sum frequencies in a hash table? Will it be useful?
4. `sum(i,j)=sum(0,j)-sum(0,i)`, where `sum(i,j)` represents the sum of all the elements from index `i` to `j-1`. Can we use this property to optimize it.

## Idea
Create a **hash table** to store the **frequencies** of `sum(0,j)`, where is the sum of all the elements from index `0` to `j`.
Given the target `k`. For each iteration `i`, calculate the number `sum(0,i)`.
Then find the frequencies of `res=sum(0,i)-k` from the hash table,
if `res`>0, then there must exists some `j` <= `i` such that `sum(i,j)=sum(0,i)-sum(0,j)=k`.
