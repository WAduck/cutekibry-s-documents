
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
