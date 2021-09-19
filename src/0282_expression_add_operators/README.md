# 282. Expression Add Operators
- Link: [https://leetcode.com/problems/expression-add-operators/](https://leetcode.com/problems/expression-add-operators/)

## Problem Statement
<div><p>Given a string <code>num</code> that contains only digits and an integer <code>target</code>, return <em>all possibilities to add the binary operators</em> <code>'+'</code>, <code>'-'</code>, <em>or</em> <code>'*'</code> <em>between the digits of</em> <code>num</code> <em>so that the resultant expression evaluates to the</em> <code>target</code> <em>value</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num = "123", target = 6
<strong>Output:</strong> ["1*2*3","1+2+3"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num = "232", target = 8
<strong>Output:</strong> ["2*3+2","2+3*2"]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> num = "105", target = 5
<strong>Output:</strong> ["1*0+5","10-5"]
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> num = "00", target = 0
<strong>Output:</strong> ["0*0","0+0","0-0"]
</pre><p><strong>Example 5:</strong></p>
<pre><strong>Input:</strong> num = "3456237490", target = 9191
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10</code></li>
	<li><code>num</code> consists of only digits.</li>
	<li><code>-2<sup>31</sup> &lt;= target &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

## Hints
1. Note that a number can contain multiple digits.
2. Since the question asks us to find all of the valid expressions, we need a way to iterate over all of them. (Hint: Recursion!)
3. We can keep track of the expression string and evaluate it at the very end. But that would take a lot of time. Can we keep track of the expression's value as well so as to avoid the evaluation at the very end of recursion?
4. Think carefully about the multiply operator. It has a higher precedence than the addition and subtraction operators.
```
1 + 2 = 3
1 + 2 - 4 --> 3 - 4 --> -1
1 + 2 - 4 * 12 --> -1 * 12 --> -12 (WRONG!)
1 + 2 - 4 * 12 --> -1 - (-4) + (-4 * 12) --> 3 + (-48) --> -45 (CORRECT!)
```
5. We simply need to keep track of the last operand in our expression and reverse it's effect on the expression's value while considering the multiply operator.
