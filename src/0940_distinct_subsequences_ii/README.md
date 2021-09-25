# 940. Distinct Subsequences II
- Link: [https://leetcode.com/problems/distinct-subsequences-ii/](https://leetcode.com/problems/distinct-subsequences-ii/)

## Idea
First, we define that `DP[i]` is the number of distinct non-empty subsequences of substring `s[0:i]` (not contain the char `s[i]`). Thus the final answer would be `DP[s.length()]`.
And `DP[0] = 0` since `s[0:0]` is a empyt string.

In addition, we need another hash table to record the last position of each letter (we can simply use `vector<int>` of size `26` here).

Now we need to find the equation of each `DP[i+1]`. For the case that current letter `s[i]` is not appeared before, then the increased number would be `DP[i] + 1`, since all the subsequences appending the new letter `s[i]` would be new subsequences, also `"s[i]"` is also a new subsequence.

For the case that `s[i]` appeared before, a number of `DP[Table[s[i]]]` is counted (or say repeated), hence the increased number would be `DP[i] - DP[Table[s[i]]]`.

For example, consider the string `"abcbc"`, when we are at the second `"c"`, some subsequences such as `"ac"`,`"bc"` are counted at the first `"c"`, the number of these repeated subsequences are 3, exactly the number of distinct non-empty subsequences of substring `"ab"`.

```
          ┌── 2 * DP[i] + 1, if s[i] does not appear before
DP[i+1] = ┤
          └── 2 * DP[i] - DP[Table[s[i]]], where s[i] appeared in `Table[s[i]]` for last time
```

## Problem Statement
<p>Given a string s, return <em>the number of <strong>distinct non-empty subsequences</strong> of</em> <code>s</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
A <strong>subsequence</strong> of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., <code>"ace"</code> is a subsequence of <code>"<u>a</u>b<u>c</u>d<u>e</u>"</code> while <code>"aec"</code> is not.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> 7
<strong>Explanation:</strong> The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aaa"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The 3 distinct subsequences are "a", "aa" and "aaa".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
