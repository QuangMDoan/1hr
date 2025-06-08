# 21: Solving Higher Order Non-homogeneous equations: Variation of parameters. 

## 21.1: Variation of parameters 
- in principle this method works for all linear non-homogeneous equations with continuous coefficient functions. 

Variation of parameters for Second order equations Main Idea

Given an ODE of the form 
$$y'' + p(x)y' + q(x)y = g(x)$$

with $y_1$ and $y_2$ a fundamental set of solutions to the corresponding homogeneous equation

Find functions $u_1$ and $u_2$ such that $Y(x) = u_1y_1 + u_2y_2$
 is a particular solution to the non-homogeneous equation. 

$$u_1 = \int\frac{-y_2(x)g(x)}{W(x)}dx$$
$$u_2 = \int\frac{y_1(x)g(x)}{W(x)}dx$$

suppose we want to solve 
$$y'' + p(x)y' + q(x)y = g(x)$$
and we know that $y_1$ and $y_2$ form a fundamental set of solutions to the corresponding homogeneous equation. I.e. :

$$y_1'' + p(x)y_1' + q(x)y_1 = 0$$
$$y_2'' + p(x)y_2' + q(x)y_2 = 0$$

Want 
$$Y(x) = u_1(x)y_1(x) + u_2(x)y_2(x)$$
to be a solution to the non-homogeneous ODE

need $u_1$ and $u_2$ to satisfy 
$$u_1'y1 + u_2'y_2 = 0$$
$$u_1'y1' + u_2'y_2' = g$$

## 21.2 Variation of parameters for higher order equations 

Suppose we want to solve 
$$L[y] = y^{(n)} + ... + p_ny = g$$

and $y_1,..., y_n$ form a fundamental set of solutions for the corresponding homogeneous equation. 

Look for a particular solution of $L[y] = g$ having the following form: 
$$Y(x) = u_1(x)y_1(x) + ... + u_n(x) y_n(x)$$

Need functions $u_1,...,u_n$ such that $L[u_1y_1 + ... + u_ny_n] = g$ 

In other words we need $u_1,...u_n$ satisfy the n-1 equations 
$$y_1u_1' + ... +y_nu_n' = 0$$
$$y_1'u_1' + ... +y_n'u_n' = 0$$ 
$$y_1''u_1' + ... +y_n''u_n' = 0$$
$$ \vdots $$
$$y_1^{(n-2)}u_1' + ... +y_n^{(n-2)}u_n' = 0$$
Then
$$L[y] = g $$
or equivalently 
$$y_1^{(n-1)}u_1' + ... +y_n^{(n-1)}u_n' = g$$

Theorem: Suppose that $y_1,...,y_n$ form a fundamental set of solutions to $L[y] = 0$. Let W(x) be the Wronskian of these n functions, and let $W_m$ be the determinant obtained from W by replacing the mth column by the column (0,0,...,0,1). Then the function

$$Y(x) = \sum_{m=1}^n y_m(x) \int \frac{g(x)W_m(x)}{W(x)}dx$$
will satisfy $L[y] = g$

$$u_i(x) = \frac{g(x)W_i(x)}{W(x)}, \quad i=1,2,...,n$$
$W_i$ is the determinant obtained from W by replacing the ith column by the column (0,0,...,0,1)


