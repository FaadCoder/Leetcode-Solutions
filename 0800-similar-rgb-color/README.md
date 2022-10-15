<h2><a href="https://leetcode.com/problems/similar-rgb-color/">800. Similar RGB Color</a></h2><h3>Easy</h3><hr><div><p>The red-green-blue color <code>"#AABBCC"</code> can be written as <code>"#ABC"</code> in shorthand.</p>

<ul>
	<li>For example, <code>"#15c"</code> is shorthand for the color <code>"#1155cc"</code>.</li>
</ul>

<p>The similarity between the two colors <code>"#ABCDEF"</code> and <code>"#UVWXYZ"</code> is <code>-(AB - UV)<sup>2</sup> - (CD - WX)<sup>2</sup> - (EF - YZ)<sup>2</sup></code>.</p>

<p>Given a string <code>color</code> that follows the format <code>"#ABCDEF"</code>, return a string represents the color that is most similar to the given color and has a shorthand (i.e., it can be represented as some <code>"#XYZ"</code>).</p>

<p><strong>Any answer</strong> which has the same highest similarity as the best answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> color = "#09f166"
<strong>Output:</strong> "#11ee66"
<strong>Explanation:</strong> 
The similarity is -(0x09 - 0x11)<sup>2</sup> -(0xf1 - 0xee)<sup>2</sup> - (0x66 - 0x66)<sup>2</sup> = -64 -9 -0 = -73.
This is the highest among any shorthand color.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> color = "#4e3fe1"
<strong>Output:</strong> "#5544dd"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>color.length == 7</code></li>
	<li><code>color[0] == '#'</code></li>
	<li><code>color[i]</code> is either digit or character in the range <code>['a', 'f']</code> for <code>i &gt; 0</code>.</li>
</ul>
</div>