# 19: Solving Higher Order constant coefficient homogeneous equations

## 19.1: Solving 2nd order constant coefficient homogeneous equations 

$$ay'' + by' + cy = 0\quad (1)$$
solve characteristic polynomial
$$ar^2+br+c = 0\quad (2)$$


if $b^2-4ac > 0$, then 

$$y(t) = c_1y_1(t) + c_2y_2(t)$$
$$y(t) = c_1e^{r_1t}  + c_2e^{r_2t}$$


if $b^2-4ac < 0$, then 

$$r_1 = \alpha + \beta i, \quad r_2 = \alpha -\beta i, \quad \alpha = -\frac{b}{2a}, \quad \beta = \frac{\sqrt{b^2-4ac}}{2a} $$

$$y(t) = c_1e^{(\alpha +\beta i)t} + c_2e^{(\alpha -\beta i)t}$$
$$y(t) = e^{\alpha t}(c_1\cos(\beta t) + c_2\sin(\beta t))$$

if $b^2-4ac = 0$, then 
$$r = -\frac{b}{2a}$$
$$y(t) = c_1e^{rt} + c_2te^{rt}$$

## 19.2: Solving Higher order constant coefficient equations 

 Given L[y] = $a_0y^{(n)} + ... a_{n-1}y' + a_ny = 0,$
- find the roots of $a_0r^n + ... + a_{n-1}r + a_n = 0$
- If r is a real zero (root) of multiplicity m of the characteristic polynomial for $L[y] = 0$, then the m functions 
$$e^{rx}, xe^{rx}, x^2e^{rx}, ..., x^{m-1}e^{rx}$$
are solutions to the ODE
- If $\lambda \pm i\mu$ is a non-real zero of multiplicity m of the characteristic polynomial for $L[y] = 0$, then the 2m functions 
$$e^{\lambda x}\cos\mu x, e^{\lambda x}\sin\mu x, xe^{\lambda x}\cos\mu x, xe^{\lambda x}\sin\mu x, ..., x^{m-1}e^{\lambda x}\cos\mu x, x^{m-1}e^{\lambda x}\sin\mu x$$
are solutions to the ODE $L[y] = 0$

