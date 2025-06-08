# 22: The Basics of Power Series 
- Power series provide a useful way to represent solutions of more complicated ODEs. 

## 22.1: Basic Properties of Power Series 
- A real power series is an expression of the form 
$$\sum_{n=0}^{\infty} a_n(x-x_0)^n$$
where $x_0, a_n$ for all n are real numbers

The series 
$$\sum_{n=0}^{\infty} a_n(x-x_0)^n$$
`converges absolutely` at $x_1$ means 
$$\sum_{n=0}^{\infty} |a_n(x-x_0)^n|$$
converges at $x_1$
## 22.2: Ratio Test 

Suppose that $a_n \ne 0$ for all sufficeintly large n, and 

$$\lim_{n->\infty} \frac{|a_{n+1}(x_1-x_0)^{n+1}}{|a_{n}(x_1-x_0)^{n}|} = |x_1-x_0|\cdot \lim_{n->\infty}|\frac{a_{n+1}}{a_{n}}| = k$$
Then 
-   if $k < 1$, the series converges absolutely at $x_1$;
