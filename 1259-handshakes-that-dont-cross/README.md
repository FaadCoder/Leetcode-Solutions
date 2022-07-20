<h2><a href="https://leetcode.com/problems/handshakes-that-dont-cross/">1259. Handshakes That Don't Cross</a></h2><h3>Hard</h3><hr><div><p>You are given an <strong>even</strong> number of people <code>numPeople</code> that stand around a circle and each person shakes hands with someone else so that there are <code>numPeople / 2</code> handshakes total.</p>

<p>Return <em>the number of ways these handshakes could occur such that none of the handshakes cross</em>.</p>

<p>Since the answer could be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/07/11/5125_example_2.png" style="width: 450px; height: 215px;">
<pre><strong>Input:</strong> numPeople = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/07/11/5125_example_3.png" style="width: 335px; height: 500px;">
<pre><strong>Input:</strong> numPeople = 6
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= numPeople &lt;= 1000</code></li>
	<li><code>numPeople</code> is even.</li>
</ul>
</div>