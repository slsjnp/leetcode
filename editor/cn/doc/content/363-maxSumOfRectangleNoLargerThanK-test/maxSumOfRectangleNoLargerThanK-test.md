<p>给你一个 <code>m x n</code> 的矩阵 <code>matrix</code> 和一个整数 <code>k</code> ，找出并返回矩阵内部矩形区域的不超过 <code>k</code> 的最大数值和。</p>

<p>题目数据保证总会存在一个数值和不超过 <code>k</code> 的矩形区域。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg" style="width: 255px; height: 176px;" />
<pre>
<strong>输入：</strong>matrix = [[1,0,1],[0,-2,3]], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>蓝色边框圈出来的矩形区域 <code>[[0, 1], [-2, 3]]</code> 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[2,2,-1]], k = 3
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>-100 <= matrix[i][j] <= 100</code></li>
	<li><code>-10<sup>5</sup> <= k <= 10<sup>5</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>如果行数远大于列数，该如何设计解决方案？</p>
<div><div>Related Topics</div><div><li>数组</li><li>二分查找</li><li>矩阵</li><li>有序集合</li><li>前缀和</li></div></div><br><div><li>👍 417</li><li>👎 0</li></div>