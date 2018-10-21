## 题意
给出 \(T\) 组数据，每组数据给出 \(n,m\) ，求

$$
(\sum_{i=1}^n \sum_{j=1}^m fib[\gcd(n, m)]) \bmod (10^9+7)
$$

其中 \(fib[i]\) 表示斐波那契数列的第 \(i\) 项。

## 题解
这是一道非常好的题目，将数论分块运用到了极致。

设

$$
f(x)=\sum_{i=1}^n \sum_{j=1}^m [\gcd(i,j)=x]
$$

则答案可转化成

$$
\sum_{x=1}^n fib[x]f(x)
$$

那么设

$$
F(x)=\sum_{i=1}^n \sum_{j=1}^m [x|\gcd(i,j)] \\
F(x)=\lfloor\frac nx \rfloor \lfloor\frac mx \rfloor
$$

而

$$
F(x)=\sum_{x|d} f(d) \\
f(x)=\sum_{x|d} \mu(\frac dx)F(d)
$$

推出

$$
f(x)=\sum_{x|d} \mu(\frac dx)F(d) \\
f(x)=\sum_{i=1}^{\lfloor\frac nx \rfloor} \mu(i)F(ix) \\
f(x)=\sum_{i=1}^{\lfloor\frac nx \rfloor} \mu(i)\lfloor\frac n{ix} \rfloor \lfloor\frac m{ix} \rfloor \\
f(x)=\sum_{i=1}^{\lfloor\frac nx \rfloor} \mu(i)\lfloor\frac {\lfloor\frac nx \rfloor}i \rfloor \lfloor\frac {\lfloor\frac mx \rfloor}i \rfloor \\
$$

设

$$
fn(n,m)=\sum_{i=1}^n \mu(i)\lfloor\frac ni \rfloor \lfloor\frac mi \rfloor \\
$$

对于任意 \(fn(n,m)\) ，我们都可以在 \(O(\sqrt n)\) 的时间内算出结果。

再回来看一下我们刚才得到的答案的式子：

$$
\begin{align}
    &\sum_{x=1}^n fib[x] f(x) \\
  = &\sum_{x=1}^n fib[x] fn(\lfloor\frac nx \rfloor, \lfloor\frac mx \rfloor)
\end{align}
$$

这样就可以做到 \(O(\sqrt n \log n)\) 求解了。
