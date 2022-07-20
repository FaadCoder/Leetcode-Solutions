<h2><a href="https://leetcode.com/problems/cutting-ribbons/">1891. Cutting Ribbons</a></h2><h3>Medium</h3><hr><div><p>You are given an integer array <code>ribbons</code>, where <code>ribbons[i]</code> represents the length of the <code>i<sup>th</sup></code> ribbon, and an integer <code>k</code>. You may cut any of the ribbons into any number of segments of <strong>positive integer</strong> lengths, or perform no cuts at all.</p>

<ul>
	<li>For example, if you have a ribbon of length <code>4</code>, you can:

	<ul>
		<li>Keep the ribbon of length <code>4</code>,</li>
		<li>Cut it into one ribbon of length <code>3</code> and one ribbon of length <code>1</code>,</li>
		<li>Cut it into two ribbons of length <code>2</code>,</li>
		<li>Cut it into one ribbon of length <code>2</code> and two ribbons of length <code>1</code>, or</li>
		<li>Cut it into four ribbons of length <code>1</code>.</li>
	</ul>
	</li>
</ul>

<p>Your goal is to obtain <code>k</code> ribbons of all the <strong>same positive integer length</strong>. You are allowed to throw away any excess ribbon as a result of cutting.</p>

<p>Return <em>the <strong>maximum</strong> possible positive integer length that you can obtain </em><code>k</code><em> ribbons of</em><em>, or </em><code>0</code><em> if you cannot obtain </em><code>k</code><em> ribbons of the same length</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ribbons = [9,7,5], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong>
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> ribbons = [7,5,9], k = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
- Cut the first ribbon to two ribbons, one of length 4 and one of length 3.
- Cut the second ribbon to two ribbons, one of length 4 and one of length 1.
- Cut the third ribbon to three ribbons, two of length 4 and one of length 1.
Now you have 4 ribbons of length 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> ribbons = [5,7,9], k = 22
<strong>Output:</strong> 0
<strong>Explanation:</strong> You cannot obtain k ribbons of the same positive integer length.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= ribbons.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= ribbons[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>
</div>