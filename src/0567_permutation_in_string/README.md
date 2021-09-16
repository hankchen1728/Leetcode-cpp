# 567. Permutation in String
- Link: [https://leetcode.com/problems/permutation-in-string/](https://leetcode.com/problems/permutation-in-string/)

## Idea
Create a table `freq1` to record the character frequencies in `s1`.
Then create another table `freq2` for record the character frequencies within a `s1.length()`-long sliding window of `s2`.
For each iteration in the for loop, moving the sliding window 1-step right-forward, and then return `true` if `freq1==freq2`.

## Problem Statement
<p>Given two strings <code>s1</code> and <code>s2</code>, return <code>true</code><em> if </em><code>s2</code><em> contains a permutation of </em><code>s1</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>In other words, return <code>true</code> if one of <code>s1</code>'s permutations is the substring of <code>s2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidbaooo"
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 ("ba").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidboaoo"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>

## Hints
1. Obviously, brute force will result in TLE. Think of something else.
2. How will you check whether one string is a permutation of another string?
3. One way is to sort the string and then compare. But, Is there a better way?
4. If one string is a permutation of another string then they must one common metric. What is that?
5. Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?
6. What about hash table? An array of size 26?
