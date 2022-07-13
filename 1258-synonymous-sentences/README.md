<h2><a href="https://leetcode.com/problems/synonymous-sentences/">1258. Synonymous Sentences</a></h2><h3>Medium</h3><hr><div><p>You are given a list of equivalent string pairs <code>synonyms</code> where <code>synonyms[i] = [s<sub>i</sub>, t<sub>i</sub>]</code> indicates that <code>s<sub>i</sub></code> and <code>t<sub>i</sub></code> are equivalent strings. You are also given a sentence <code>text</code>.</p>

<p>Return <em>all possible synonymous sentences <strong>sorted lexicographically</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]], text = "I am happy today but was sad yesterday"
<strong>Output:</strong> ["I am cheerful today but was sad yesterday","I am cheerful today but was sorrow yesterday","I am happy today but was sad yesterday","I am happy today but was sorrow yesterday","I am joy today but was sad yesterday","I am joy today but was sorrow yesterday"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> synonyms = [["happy","joy"],["cheerful","glad"]], text = "I am happy today but was sad yesterday"
<strong>Output:</strong> ["I am happy today but was sad yesterday","I am joy today but was sad yesterday"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= synonyms.length &lt;= 10</code></li>
	<li><code>synonyms[i].length == 2</code></li>
	<li><code>1 &lt;= s<sub>i</sub>.length,<sub> </sub>t<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>s<sub>i</sub> != t<sub>i</sub></code></li>
	<li><code>text</code> consists of at most <code>10</code> words.</li>
	<li>All the pairs of&nbsp;<code>synonyms</code> are <strong>unique</strong>.</li>
	<li>The words of <code>text</code> are separated by single spaces.</li>
</ul>
</div>