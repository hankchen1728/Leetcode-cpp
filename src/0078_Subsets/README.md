# 78. Subsets
- Link: [https://leetcode.com/problems/subsets/](https://leetcode.com/problems/subsets/)

## Idea
#### 1. Cascading
Take `[ 1, 2, 3 ]` for example, for the first number, we have only two subsets `[[], [1]]`, for the second number, we can add the second number to every subset we already have, that is `[[2], [1, 2]]`, now the `[[], [1]]` and `[[2], [1, 2]]` are all the subsets of just considering `[1, 2]`.

Then repeat the step above, we can get all subsets.

#### 2. Bit Manipulation
For the `i`-th subset, each bit in the `i` indicate whether to take the number or not

## Problem Statement
<div><p>Given an integer array <code>nums</code> of <strong>unique</strong> elements, return <em>all possible subsets (the power set)</em>.</p>

<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [[],[0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the numbers of&nbsp;<code>nums</code> are <strong>unique</strong>.</li>
</ul>
</div>
