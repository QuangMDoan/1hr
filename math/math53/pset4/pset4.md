# XM531 Problem Set 4 
#   Quang Doan

# Problem 1 

The `gamma function` is denoted by $\Gamma(p)$ and is defined by the integral

$$\Gamma(p+1)=\int_0^\infty e^{-x}x^pdx $$

**A.** Show that, for $p>0, \Gamma(p+1) = p\Gamma(p)$

By definition

$$\Gamma(p) = \int_0^\infty e^{-x}x^{p-1}dx$$

Thus,

$$p \Gamma(p) = p \int_0^\infty e^{-x}x^{p-1}dx = \int_0^\infty e^{-x} p x^{p-1}dx$$

we need to show that 

$$\Gamma(p+1)=\int_0^\infty e^{-x}x^pdx = \int_0^\infty e^{-x} p x^{p-1}dx \quad (*) $$

Let

$$u = x^p, \quad  du = p x^{p-1} dx $$
$$dv = e^{-x}dx,  v = -e^{-x} $$


$$\int e^{-x}x^pdx \quad \text{is} \int udv = uv - \int vdu $$ 


$$\int_0^\infty e^{-x}x^pdx = -x^p e^{-x} |_0^{\infty} -  \int_0^\infty -e^{-x} p x^{p-1} dx 
= (0 - 0) + \int_0^\infty e^{-x} p x^{p-1} dx = \int_0^\infty e^{-x} p x^{p-1} dx $$ 

Thus 

$$\Gamma(p+1)=\int_0^\infty e^{-x}x^pdx = \int_0^\infty e^{-x} p x^{p-1}dx 
 = p \int_0^\infty e^{-x}x^{p-1}dx = p \Gamma(p) \quad  \text{Q.E.D.}$$



**B.** Show that $\Gamma(1)=1$

By definition

$$\Gamma(1) = \int_0^\infty e^{-x}x^{0}dx 
= \int_0^\infty e^{-x}dx $$

$$\Gamma(1) = \int_0^\infty e^{-x}dx = -e^{-x}|_0^\infty $$
$$\Gamma(1) = -e^{-x}|_0^\infty = -0 - (-e^0) = e^0 = 1 $$

**C.** If $p$ is a positive integer $n$, show that $\Gamma(n+1) = n!$

Prove by induction:

Base case: $n = 1$:

$$\Gamma(1+1) = 1*\Gamma(1) \quad \text{per part A} $$
$$1*\Gamma(1) = 1*1 \quad \text{per part B} $$
$$\Gamma(n+1) = \Gamma(1+1) = 1 = n! \quad \text{for n = 1}  $$

Induction step:

- Suppose that for some positive integer $k$ 
$$\Gamma(k+1) = k!  $$

- we must show that 

$$\Gamma(k+2) = (k+1)!  $$

- Applying the result from part **A**:   $\Gamma(p+1) = p\Gamma(p)$, with p = (k+1) 

$$\Gamma(k+2) = \Gamma( \mathbf{(k+1)} + 1 ) = (k+1) \Gamma(k+1) $$
$$(k+1) \Gamma(k+1) = (k+1) k!  \quad \text{per induction hypothesis} $$

$$\text{thus} \quad \Gamma(k+2) = (k+1) k! = (k+1)!$$

we have shown that 

$$\Gamma(n+1) = n! \quad \text{by induction}$$



**D.** Show that, for $p>0$, 

$$p(p+1)(p+2)\dots (p+n-1) = \frac{\Gamma(p+n)}{\Gamma(p)} $$ 


Applying the result from part **A**

- $\Gamma(p+1) =  (p) \Gamma(p)$
- $\Gamma(p+2) = (p+1) \Gamma( p+1) = (p+1) (p) \Gamma( p)$
- $\Gamma(p+3) = (p+2) \Gamma( p+2) = (p+2) (p+1) (p) \Gamma( p)$
- ...
- $\Gamma(p+n) = (p + n - 1) (p + n - 2) \cdot \cdot \cdot (p+1) (p) \Gamma(p)$

Thus 

$$p(p+1)(p+2)\dots (p+n-1) = \frac{\Gamma(p+n)}{\Gamma(p)} $$ 

**E.** Given $\Gamma(\frac{1}{2}) = \sqrt \pi$, find $\Gamma(\frac{3}{2})$, and $\Gamma(\frac{11}{2})$


$$\Gamma(\frac{3}{2})=\Gamma(\frac{1}{2} + 1)=\frac{1}{2} \cdot \Gamma(\frac{1}{2})=\frac{\sqrt \pi}{2}$$ 

$$\Gamma(\frac{11}{2})=\Gamma(\frac{1}{2} + 5) = 
\frac{1}{2} \cdot 
\frac{3}{2} \cdot 
\frac{5}{2} \cdot 
\frac{7}{2} \cdot 
\frac{9}{2} \cdot 
\Gamma(\frac{1}{2})$$ 


$$\Gamma(\frac{11}{2}) = 
\frac{1 \cdot 3 \cdot 5 \cdot 7 \cdot 9}{32} \sqrt \pi = 

\frac{945}{32} \sqrt \pi = 52.36 

$$ 

# Problem 2 

Use the Laplace transform to solve the given intial value problem.

$$ y''+3y'+2y= 0;\ \ \ \ \ y(0)=1, \ \ y'(0)=0. $$

Assuming $y(t)$ is the solution to equation $y''+3y'+2y= 0 \ \ (1)$ 

$$ \mathcal{L} \{ y(t) \}(s) = Y(s) $$ 

$$ \mathcal{L}\{ y'(t) \}(s) = s Y(s) - y(0) $$ 

$$ \mathcal{L}\{ y'(t) \}(s) = s Y(s) - 1 $$ 


$$ \mathcal{L}\{ y''(t) \}(s) = s^2 Y(s) -s y(0) -y'(0)  $$ 
$$ \mathcal{L}\{ y''(t) \}(s) = s^2 Y(s) -s $$ 

Apply Laplace transforms to all terms in (1)
$$ s^2 Y -s + 3(sY  -1) + 2Y = 0 $$ 

$$ s^2 Y -s + 3sY  -3 + 2Y = 0 $$ 

$$ Y(s^2 + 3s + 2) = s + 3 $$ 

$$ Y = \frac{s + 3}{s^2 + 3s + 2} = \frac{s + 3}{ (s+2)(s+1)}  $$ 
$$ Y = \frac{s + 3}{ (s+2)(s+1)} = \frac{2}{s+1} - \frac{1}{s+2} $$ 

Apply inverse transforms 

$$ \mathcal{L^{-1}} \{ Y(s)\}(t) =  

    \mathcal{L^{-1}} \{ \frac{2}{s+1} \}(t) + 
    \mathcal{L^{-1}} \{ \frac{-1}{s+2} \}(t)

$$

$$ y(t) =  2e^{-t} - e^{-2t} $$


# Problem 3 

Let $\alpha$ be a real number. Express the solution of the given initial value problm in terms of a convolution integral.

$$y''+2y'+2y = \sin(\alpha t);\ \ \ \ \ y(0)=0,\ \ y'(0)=0 \ \ (1)$$

Assuming $y(t)$ is the solution to equation (1). Apply Laplace transforms $y, y', y''$ and simplifying using initial conditions. 

$$ \mathcal{L} \{ y(t) \}(s) = Y(s) $$ 

$$ \mathcal{L}\{ y'(t) \}(s) = s Y(s) - y(0) = s Y(s)$$ 

$$ \mathcal{L}\{ y''(t) \}(s) = s^2 Y(s) -s y(0) -y'(0)  = s^2 Y(s) $$ 

Apply Laplace transforms to all terms in (1) and simplifying using initial conditions.

$$ s^2 Y + 2(sY) + 2Y = \mathcal{L}\{  \sin(\alpha t) \} $$ 

$$ Y(s^2 + 2s + 2) = \mathcal{L}\{  \sin(\alpha t) \}  $$ 

$$ Y(s) = \frac{\mathcal{L}\{  \sin(\alpha t) \}}{s^2 + 2s + 2}  
     =  \frac{1}{ (s + 1)^2  + 1} \cdot \mathcal{L}\{  \sin(\alpha t) \}
     = Y_1(s) Y_2(s)
$$ 

Apply the inverse transforms to both sides 

$$ y(t) = \mathcal{L^{-1}}\{ Y(s) \}(t)
        = \mathcal{L^{-1}}\{ Y_1(s) Y_2(s) \}(t)
$$ 

$$ y(t) = \mathcal{L^{-1}}\{ Y_1(s) Y_2(s) \}(t) 
        = \mathcal{L^{-1}}\{  \frac{1}{ (s + 1)^2  + 1} \} (t) * 
     \mathcal{L^{-1}}\{  \mathcal{L}\{  \sin(\alpha t) \} \} (t)   $$

$$ y(t) = e^{-t} \sin(t) * \sin(\alpha t) $$

Thus, the solution of the given initial value problem in terms of a convolution integral is

$$ y(t) = \int_0^t { \sin \alpha(t-\tau) } e^{-\tau} \sin(\tau) d\tau $$

# Problem 4
Let $\alpha$ be a real number. Find the Laplace transform of the following:

$a. \quad f(t) = t^2 \sinh(\alpha t)$

$$ \sinh(\alpha t) = \frac{1}{2} (e^{\alpha t} - e^{-\alpha t}) $$

$$ f(t) = t^2 \sinh(\alpha t) = \frac{1}{2} ( t^2 e^{\alpha t} - t^2 e^{-\alpha t}) $$

$$\mathcal{L}\{ f(t) \}(s) = \frac{1}{2}  ( \mathcal{L}\{ t^2 e^{\alpha t} \} - \mathcal{L}\{ t^2 e^{-\alpha t}) \}(s) $$

$$ \mathcal{L}\{ t^2 e^{\alpha t} \}(s) = \frac{2!}{(s - \alpha)^3 } = \frac{2}{(s - \alpha)^3 } $$
$$ \mathcal{L}\{ t^2 e^{-\alpha t} \}(s) = \frac{2}{(s + \alpha)^3 } $$

$$\mathcal{L}\{f(t)\}(s) = \frac{1}{2}  ( \mathcal{L}\{ t^2 e^{\alpha t} \} - \mathcal{L}\{ t^2 e^{-\alpha t}) \}(s) = \frac{1}{(s - \alpha)^3 } - \frac{1}{(s + \alpha)^3 } $$




$b. \quad 
g(t) = 
\begin{cases} 
    t,      & 0\leq t < 1,\\
    2-t,    & 1\leq t< 2,\text{ and}\\
    0,      & 2\leq t <\infty
\end{cases} 
$

$$ g(t) = 
\begin{cases} 
    t,      & 0\leq t < 1,\\
    2-t,    & 1\leq t< 2,\text{ and}\\
    0,      & 2\leq t <\infty
\end{cases} 
$$

$$ g(t) = t + u_1(t)(2-2t) + u_2(t)(t-2) $$


$$ \mathcal{L}\{g(t)\}(s) = \mathcal{L}\{t\} + \mathcal{L}\{u_1(t) (2-2t)\} + \mathcal{L}\{u_2(t) (t-2)\} $$

$$ G(s) = \frac{1}{s^2} + \mathcal{L}\{u_1(t) (-2t + 2)\} + \mathcal{L}\{u_2(t) (t-2)\} $$

$$ \mathcal{L}\{u_2(t) (t-2)\} = e^{-2s} \mathcal{L} \{ t -2 + 2 \} = \frac{e^{-2s}}{s^2} $$

$$ \mathcal{L}\{u_1(t) (-2t + 2)\} = \mathcal{L}\{u_1(t) (2(1-t))\} = \frac{-2e^{-s}}{s^2} $$

Thus, 

$$ \mathcal{L}\{g(t)\}(s) = G(s) = \frac{1}{s^2} -2 \frac{e^{-s}}{s^2} + \frac{e^{-2s}}{s^2} $$

$$ \mathcal{L}\{g(t)\}(s) = G(s) = \frac{ (e^{-s} -1)^2 }{s^2}$$

