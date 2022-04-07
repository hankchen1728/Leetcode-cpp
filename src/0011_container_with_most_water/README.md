# 11. Container With Most Water
- Link: [https://leetcode.com/problems/container-with-most-water/](https://leetcode.com/problems/container-with-most-water/)

## Idea
Each time always move the shorter line.
Keep moving until the height is larger than current minimal one.

## Problem Statement
<p>Given <code>n</code> non-negative integers <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code><sub> </sub>, where each represents a point at coordinate <code>(i, a<sub>i</sub>)</code>. <code>n</code> vertical lines are drawn such that the two endpoints of the line <code>i</code> is at <code>(i, a<sub>i</sub>)</code> and <code>(i, 0)</code>. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.</p>

<p><strong>Notice</strong> that you may not slant the container.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg" style="width: 600px; height: 287px;">
<pre><strong>Input:</strong> height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain&nbsp;is 49.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> height = [1,1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> height = [4,3,2,1,4]
<strong>Output:</strong> 16
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> height = [1,2,1]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>

## Hints
### Hint 1
The aim is to maximize the area formed between the vertical lines. The area of any container is calculated using the shorter line as length and the distance between the lines as the width of the rectangle.

<pre>Area = length of shorter vertical line * distance between lines
</pre>

We can definitely get the maximum width container as the outermost lines have the maximum distance between them. However, this container <b>might not be the maximum in size</b> as one of the vertical lines of this container could be really short.

<br>
<img src="https://assets.leetcode.com/uploads/2019/10/20/hint_water_trap_1.png" width="500">

<br>
<img src="https://assets.leetcode.com/uploads/2019/10/20/hint_water_trap_2.png" width="500">

### Hint 2
Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line. This way we are compromising on the width but we are looking forward to a longer length container.
