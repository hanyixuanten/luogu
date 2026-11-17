# AT_arc101_c [ARC101E] Ribbons on Tree 题解

## 题意

给定 $2 * N$ 个节点个树，要求两两成对，并在一对节点的最短路径上每条边打上标记，求有多少方案使得每个边都被标记。

## 思路

考虑倒着做并容斥。记 $F(S)$ 表示不标记 $S$ 中边的方案数，根据容斥原理，答案为 $\sum(-1)^{\mid S\mid} F(S)$。

选择一些边不被标记相当于将这些边断开，在分成的连通块中任意配对。容易发现，对于一个大小为 $m$ 的连通块，任意配对的方案数为：

$$
sum_m = \big\{
\begin{aligned}
&0 &2\nmid m \\
&(m - 1) \times (m - 3) \times \cdots \times 1 &2\mid m
\end{aligned}
$$

接下来考虑 dp。设 $f_{i, j} (j \le siz_i)$ 表示以 $i$ 为根的子树内，且 $i$ 所在的联通块的大小为 $j$ 的方案数（不算 $i$ 所在的连通块本身）。

考虑节点 $u$ 和其某个孩子节点 $v$。可以写出转移方程式：

$$
\begin{aligned}
&f^\prime_{u, i + j} &&\operatorname{+=} f_{u, i} \times f_{v, j}\\
&f^\prime_{u, i} &&\operatorname{+=} (-sum_j) \times f_{u, i} \times f_{v, j}
\end{aligned}
$$

其中第一个式子表示合并 $u, v$ 所在的连通块（连接两个子树），第二个式子表示断开 $u, v$ 之间的边为两个连通块，此时由于边数 $-1$ 需要乘上容斥系数，且 $v$ 连通块内可任意配对。

最终答案为 $\sum_{i = 1}^{n} f_{1, i} \times i$。乘上 $sum_i$ 的原因是定义中不含 $i$ 所在的连通块本身，因此需要加上。

[code](../AT_arc101_c.cpp)
