# 53. Maximum Subarray
- Link: [https://leetcode.com/problems/maximum-subarray/](https://leetcode.com/problems/maximum-subarray/)

## Idea
1. For **i**-th step, the value is the max sum of every contiguous subarray ends at **i**-th element.
2. Similar to greedy algorithm, mostly adding one more element would increase the sum, hence each step we can directly add the current element to the sum. But if the sum will be negative after adding the current element, we need to reset the sum to 0. In order words, if `sum(nums[i:j-1]) > 0` and `sum(nums[i:j]) < 0`, then any `nums[i:k]` where `k≥j`, will never be the one with max sum, for example, `sum([1,-2,3,5])` is lower than `sum([3,5])`.

Or see [How to solve "Maximum Subarray" by using the divide and conquer approach ?](https://leetcode.com/problems/maximum-subarray/discuss/20372/How-to-solve-%22Maximum-Subarray%22-by-using-the-divide-and-conquer-approach)

## Problem Statement
<p>Given an integer array <code>nums</code>, find the contiguous subarray (containing at least one number) which has the largest sum and return <em>its sum</em>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> [4,-1,2,1] has the largest sum = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.</p>
