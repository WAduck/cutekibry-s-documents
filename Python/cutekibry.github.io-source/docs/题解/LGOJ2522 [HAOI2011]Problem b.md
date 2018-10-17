# LGOJ2522 [HAOI2011]Problem b
<span style="float:right;font-size:120%">[LGOJ2522→](https://www.luogu.org/problemnew/show/P2522)</span>

## 题意
给出 \(n\) 个询问，每个询问给出 \(a,b,c,d,k\) ，求

$$
\sum_{x=a}^b \sum_{y=c}^d [\gcd(x,y)=k]
$$

\(1 \leq n,a,b,c,d,k \leq 50000\) 。

## 题解
首先，我们可以将其视作求矩形权值和的问题，这个问题便转换为：

给出 \(n,m,k\) ，求

$$
\sum_{x=1}^n \sum_{y=1}^m [\gcd(x,y)=k]
$$

那么，设

$$
f(i)=\sum_{x=1}^n \sum_{y=1}^m [\gcd(x,y)=i] \\
F(i)=\sum_{x=1}^n \sum_{y=1}^m [i|\gcd(x,y)]
$$

易得

$$
F(i)=\sum_{i|d}f(d) \\
f(i)=\sum_{i|d}\mu(\frac di)F(d)
$$

又可推出 \(F(i)\) 的公式为
$$
F(i)=\sum_{x=1}^n \sum_{y=1}^m [i|\gcd(x,y)] \\
F(i)=\sum_{x=1}^{\lfloor\frac ni \rfloor} \sum_{y=1}^{\lfloor\frac mi \rfloor} [1|gcd(x,y)] \\
F(i)=\lfloor\frac ni \rfloor \lfloor\frac mi \rfloor
$$

所以答案为

$$
\begin{align}
    &\sum_{x=1}^n \sum_{y=1}^m [\gcd(x,y)=k] \\
  = &f(k) \\
  = &\sum_{k|d}\mu(\frac dk)F(d) \\
  = &\sum_{k|d}\mu(\frac dk)\lfloor\frac nd \rfloor \lfloor\frac md \rfloor
\end{align}
$$

换个方式，这次我们枚举倍数

$$
    \sum_{k|d}\mu(\frac dk)\lfloor\frac nd \rfloor \lfloor\frac md \rfloor
  = \sum_{i=1}^{\lfloor\frac {\min\{n,m\}}k \rfloor}\mu(k)\lfloor\frac n{ik} \rfloor \lfloor\frac m{ik} \rfloor
$$

注意到 \(\lfloor\frac n{ik} \rfloor\) 和 \(\lfloor\frac m{ik} \rfloor\) 的取值大约有 \(\sqrt{n+m}\) 个，所以使用数论分块即可。

综上，使用 \(O(\max\{n\})\) 的时间预处理出 \(\mu(i)\) 的前缀和，再对每一个询问使用数论分块达到 \(O(\sqrt n)\) 的复杂度，就可以在总时间 \(O(n+t\sqrt n)\) 的时间内完成计算（其中 \(t\) 为询问个数）。
