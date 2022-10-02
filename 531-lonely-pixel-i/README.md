<h2><a href="https://leetcode.com/problems/lonely-pixel-i/">531. Lonely Pixel I</a></h2><h3>Medium</h3><hr><div><p>Given an <code>m x n</code> <code>picture</code> consisting of black <code>'B'</code> and white <code>'W'</code> pixels, return <em>the number of <b>black</b> lonely pixels</em>.</p>

<p>A black lonely pixel is a character <code>'B'</code> that located at a specific position where the same row and same column don't have <strong>any other</strong> black pixels.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/11/pixel1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> All the three 'B's are black lonely pixels.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/11/pixel2.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> picture = [["B","B","B"],["B","B","W"],["B","B","B"]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;picture.length</code></li>
	<li><code>n ==&nbsp;picture[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>picture[i][j]</code> is <code>'W'</code> or <code>'B'</code>.</li>
</ul>
</div>