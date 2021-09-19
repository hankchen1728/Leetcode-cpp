# 115. Distinct Subsequences
- Link: [https://leetcode.com/problems/distinct-subsequences/](https://leetcode.com/problems/distinct-subsequences/)

## Idea
Subproblem: `DP[i][j]` means number of distinct subsequences `s[0:j]` equals `t[0:i]`, then the answer of original problem would be `DP[t.length()][s.length()]`.

If `s[j] != t[i]`, then the number would be equal to `DP[i][j-1]`, which is number of distinct subsequences `s[0:j-1]` equals `t[0:i]`. <br/>
If `s[j] == t[i]`, then the number would be equal to `DP[i-1][j-1] + DP[i][j-1]`.

## Problem Statement
<p>Given two strings <code>s</code> and <code>t</code>, return <em>the number of distinct subsequences of <code>s</code> which equals <code>t</code></em>.</p>

<p>A string's <strong>subsequence</strong> is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., <code>"ACE"</code> is a subsequence of <code>"ABCDE"</code> while <code>"AEC"</code> is not).</p>

<p>It is guaranteed the answer fits on a 32-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "rabbbit", t = "rabbit"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
As shown below, there are 3 ways you can generate "rabbit" from S.
<code><strong><u>rabb</u></strong>b<strong><u>it</u></strong></code>
<code><strong><u>ra</u></strong>b<strong><u>bbit</u></strong></code>
<code><strong><u>rab</u></strong>b<strong><u>bit</u></strong></code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "babgbag", t = "bag"
<strong>Output:</strong> 5
<strong>Explanation:</strong>
As shown below, there are 5 ways you can generate "bag" from S.
<code><strong><u>ba</u></strong>b<u><strong>g</strong></u>bag</code>
<code><strong><u>ba</u></strong>bgba<strong><u>g</u></strong></code>
<code><u><strong>b</strong></u>abgb<strong><u>ag</u></strong></code>
<code>ba<u><strong>b</strong></u>gb<u><strong>ag</strong></u></code>
<code>babg<strong><u>bag</u></strong></code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 1000</code></li>
	<li><code>s</code> and <code>t</code> consist of English letters.</li>
</ul>
