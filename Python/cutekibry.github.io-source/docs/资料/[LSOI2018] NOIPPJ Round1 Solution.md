# [LSOI2018]NOIPPJ Round1 Solution
## A - 成绩
很简单，水题一道。

结果各位同学莫名奇妙地WA/TLE/RE了，实在不太应该。

注意：

1. 小测成绩要求输出的是严格次小的成绩，也就是给出 \([1,1,2,2]\) ，小测成绩应该是 \(1\) 。
2. 注意要四舍五入后输出，可以考虑`printf("%.0lf", ans)`或`printf("%d", int(ans+0.5))`。

<br /><br /><br /><br /><br /><br /><br /><br />

## B - 图书管理员
同上，模拟即可。

由于需求码的长度不大于 \(100\) ，所以需要使用字符串存储。

<br /><br /><br /><br /><br /><br /><br /><br />

## C - 棋盘
### 对于 \(30\%\) 的数据
设

$$
f(k)=\frac {\sum_{i=1}^n (a_i+k)^2}k
$$

则题目求的便是
\(min\{f(k)\} \quad (1 \leq k \leq x, k \in \mathbb{N}^*)\) 。<span style="display:none">**</span>

我们可以用 \(O(n)\) 的时间暴力算出 \(f(k)\) ，用前缀和的形式在 \(O(nx)\) 的时间内算出答案。

具体来说，设 \(minv_i=\min\{f(k)\} \quad (1 \leq k \leq i)\) ，则有 \(minv_i=\min\{f(i), minv_{i-1}\}\) 。

在 \(O(nx)\) 的时间内算出所有 \(minv_i\) ，则 \(minv_x\) 就是我们要求的答案了。

### 另外 \(30\%\) 的数据
注意到 \(a_i\) 取值不超过 \(100\) 种，所以我们将相同的 \(a_i\) 统计起来，则 \(f(k)\) 的时间复杂度降为 \(O(a_i取值种数)\) 。

### 对于 \(100\%\) 的数据

我们可以使用`NOIP2015普及组T3 求和`的方法将该式子拆开：

$$
\begin{align}
f(k)&=\frac {\sum_{i=1}^n (a_i+k)^2}k \\
    &=\frac {\sum_{i=1}^n (a_i^2+2ka_i+k^2)}k
\end{align}
$$

设 \(sum=\sum_{i=1}^n a_i\) ， \(powsum=\sum_{i=1}^n a_i^2\) ，则

$$
\begin{align}
f(k)&=\frac {\sum_{i=1}^n (a_i^2+2ka_i+k^2)}k \\
    &=\frac {powsum+2ksum+nk^2}k
\end{align}
$$

我们可以用 \(O(n)\) 的时间预处理出 \(powsum\) 和 \(sum\) ，这样就可以在 \(O(1)\) 的时间内算出 \(f(k)\) 了。

### 函数的规律
**以下部分涉及高中导数内容，不要求掌握。**

令 \(a=powsum\) ， \(b=sum\) 。

$$
h(x)=\frac {a+2bx+x^2n}x
$$

设

$$
f(x)=a+2bx+x^2n \\
g(x)=\frac 1x
$$



$$
f'(x)=2b+2nx \\
g'(x)=-\frac 1{x^2}
$$

则

$$
\begin{align}
    &h'(x) \\
  = &\frac d{dx} (f(x)g(x)) \\
  = &f'(x)g(x)+f(x)g'(x) \\
  = &\frac {2b+2nx}x - \frac {a+2bx+nx^2}{x^2} \\
  = &\frac {2bx+2nx^2-a-2bx-nx^2}{x^2} \\
  = &\frac {nx^2-a}{x^2} \\
  = &n - \frac a{x^2} \\
\end{align}
$$

当 \(h'(x)=n-\frac a{x^2}<0\) 时，函数呈负增长趋势，此时 \(x<\sqrt \frac an\) ；

当 \(h'(x)=n-\frac a{x^2}=0\) 时，函数取最值，此时 \(x=\sqrt\frac an\) 。

当 \(h'(x)=n-\frac a{x^2}>0\) 时，函数呈正增长趋势，此时 \(x>\sqrt \frac an\) 。

<br /><br /><br /><br /><br /><br /><br /><br />

## D - 魔法阵
### 对于 \(20\%\) 的数据
直接手算打表即可。

### 对于 \(50\%\) 的数据
使用深搜枚举每个数放或不放，并检查状态是否合法。

时间复杂度为 \(O(2^n)\) 。

### 对于 \(100\%\) 的数据
注意到只有当 \(i \leq \sqrt n\) 的时候， \(i\) 才会对后面的物品造成影响。

枚举前 \(\sqrt n\) 个物品，后面的物品使用公式 \(2^k\) 就可以算出来了。

时间复杂度为 \(O(2^{\sqrt n})\) 。
