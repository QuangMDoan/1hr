# Unit 3 Work, Energy, and Power 

## 3.1 Translational Kinetic Energy

### 3.1.1 define an object's translational kinetic energy. We'll also discuss K's units, its scalar nature, and its dependence on reference frame. 

**definition of kinetic energy**
$$K = \frac{1}{2}mv^2$$

**K of a system**
$$K_{sys} = K_1 + K_2 + K_3 + ...$$

**K depends on frame of reference**

- A blue person, mass $m_b$, stands still on a train moving over ground at velocity v. What's her K according to...
  - ...an orange person at rest on ground? 
  $$\frac{1}{2}m_bv^2$$
  - ... a purple person standing still in the train.   
  $$\frac{1}{2}m_b(0)^2 = 0$$

### Takeaways 

$$K = \frac{1}{2}mv^2$$
$$K_{sys} = K_1+K_2+K_3+...$$
K depends on frame of reference

## 3.2  Work 

### 3.2.1 Name different forms of energy can take. We'll also observe that forces transform energy and transfer it between objects. 

### Strategy: learning about work and potential energy 
$$\int \vec{F} \cdot d\vec{x} = W = -\Delta U$$

**Force acting through $\Delta x$ changes energy**

- Cart, mass m, is on a frictionless horizontal track.
- I push the cart with one constant horizontal force F over a displacement $\Delta x$ bringing its velocity from $v_{x0}$ to $v_x$
$$v_x^2 = v_{x0}^2 + 2a\Delta x$$
$$v_x^2 = v_{x0}^2 + 2(\frac{F}{m})\Delta x$$
$$\frac{1}{2}mv_x^2-\frac{1}{2}v_{x0}^2 = F\Delta x$$
$$K_x - K_{x0} = F\Delta x$$

**Energy takes different forms**
- K (energy of motion) 
- chemical potential, $U_{ch}$
- Elastic (spring) potential, $U_{el}$
- Gravitational potential, $U_g$
- Dissipated thermal energy, $E_{diss}$
- U is not "the potential ability of something to happen."
- It's "energy of relative position"

$F_{push}$: Gain $\Delta K = F\Delta x$

$F_{grav}$: $\Delta K = F_g\cdot y = mgy$

**Conservative and nonconservative forces**

Friction creates $E_{diss}$, so it's a nonconservative force. Others: 
  - Air drag; other fluid(liquid or gas) drag 
  - Forces involved in making sound 
  - forces involved in storing or releasing $U_ch$  

### 3.2.2 define work as mechanical energy transferred into or out of a system. We'll also elaborate on the nature of conservative and nonconservative forces. 

$$E = K+U$$
- except excluding thermal E 
- and excluding $U_{ch}$

Work's relationship to energy 
- W = the amount of $E_{mech}$ transferred, via force, into or out of a system. 
  - If $E_{mech}$ is transferred into the system, W is +
  - If $E_{mech}$ is transferred out of the system, W is -

**How much work was done on the system? By what force?**
- Skater initially has $K = 300J$, then rolls to a stop up a frictionless ramp. System = skater. 

**Derivation: the work-kinetic energy theorem**
- Given: a particular ball accumulates K = 1.25J when dropped from rest by 50 cm.
- ($F_g$ has done +1.25 J of W on ball.)

Now, lower the same ball, rest to rest, 50cm. 
- W done on ball by $F_g$?

- Conservative forces: 
  - "Store energy" in an associated U 
  - Do zero total W on a closed path. 
  - Do path-independent work. 
- Nonconservative forces: 
  - Has no associated U. 
  - do path dependent W. 

### 3.2.3 describe work as the effect of force acting through displacement.

$$W = \int \vec{F} \cdot dx = F \Delta x$$
$$W = 50N * 0.3m = 15J$$

**A constant force at an angle to displacement**
- cart moves right on horizontal frictionless track; F_T = 5N acts at $\theta$ without lifting cart off the track. How much work does $F_T$ do over $\Delta x = 1m$ 

### 3.2.4 introduce a "path-integral" notation as a way to hold all our ideas about how forces create work. We'll also conclude with some more complex examples. 

**Work and force: deriving a most general case**
- An object undergoes a complicated path. 
- At each location, a force (not necessarily along path, varying by position) acts on the object. 
- Along each teensy displacement dx, F does a teensy amount of work

$$dW = \vec{F} \cdot d\vec{x}$$

- Along whole path, add up the teensy bits... 
$$\int dW = \int \vec{F} \cdot d\vec{x}$$

$$W = \int_a^b \vec{F} \cdot d\vec{r}$$
- when force acts on an object undergoing a path from location a to location b. 
- the work done by a force acting on a object undergoing a path is called the path integral of the vector force dotted with little vector steps. 

## 3.3 Potential Energy 

### 3.3.1 explore a simple expression for gravitational potential energy. We'll also discuss its scalar nature and sign, then use it to derive the results. 

In earth mass system, where y is the height above 
$$U_g = mgy$$

lost $U_g =$ gained $K$  

**Descent, version 3...**
- A cart slides on a frictionless roller coaster from rest. Find its v after its descended a vertical height h. 
- does any $f_{ext}$ do work on the cart-earth system. 

### 3.3.2 derive the potential energies assosciated with constant gravitational force and with elastic force. We'll also deploy the results to solve example problems. 

**Observing a relationship between W and U**
- Raise a mass $m$ by an amount $h$. How much work done by gravity?
$$W_g = \vec{F_g} \cdot \Delta \vec{y}$$
$$W_g = F_g\Delta y \cos(180\degree)$$
$$\Delta U_g = mgy_2 -mgy_1 = mg\Delta y = +mgh$$
we find that the work done by this conservative force gravity is the opposite of its change in potential energy. 
**Potential energy in general**
- When a conservative force acts as a system moves from state $a$ to state $b$... 
$$\Delta U_{a->b} = -W = -\int_a^b \vec{F} \cdot d\vec{r}$$

**$F_{elastic}$**
- when a spring of constant k is displaced by x from its natural length/equilibrium position ($F_{el}$ always opposite x)

$$F_{el} = -kx$$
$$[k] = \frac{N}{m}$$

**Deriving $U_{elastic}$**

Given: $F_{el} = -kx$

Derive: $U_{el}$ in a spring displaced by x from its natural length/equilibrium position.

**$U_{elastic}:$ formula and example**
$$U_{el} = \frac{1}{2}kx^2$$ 

- in spring of constant k compressed or stretched by x from its natural length. 
- when we double the compression from $d$ to $2d$, the potential energy $U$ will be $2^2 = 4$ times 

$$\frac{1}{2}kd^2 = F_f \cdot L$$
Scale $d$ by 2 => $L$ by 4

**Flipping the relationship: $F$ from $U$**

$$\Delta U = -\int F dx$$
take derivative both sides 
$$F(x) = -\frac{dU}{dx}$$

Example: Given the following U(x), find the associated F(x)
- $U(x) = \frac{1}{2}kx^2$

### 13.3 qualitatively discuss, then derive, the potential energy associated with universal gravitation. We'll also practice using it in astronomical contexts. 

**U = 0  is arbitrary**

- Having a mass on a table and defining y = 0 at the table height 

$$U_g = mgy$$
$$ = 1kg * 10\frac{m}{s^2} * (0) = 0J$$

potential energy is the energy of relative position

**But... we need a new $U_g$ function.**
- Constant-force model of gravitation
- For $F_g$ by Earth on a mass m near Earth's surface 
$$F_g = mg$$
$$U_g = mgy$$
- Universal model of gravitation 
- For spherical or pointlike masses $m_1$ and $m_2$, COM's separated by R... 
$$F_g = G\frac{m_1m_2}{R^2}$$
$$(G = 6.67*10^{-11} \frac{Nm^2}{kg^2})$$
Universal gravitation model: spherical or pointlike massses $m_1$ and $m_2$, COM's separated by R...
$$U_g = \frac{-Gm_1m_2}{R}$$

**$U_g$ with more than two objects**
- In terms of m and d, state the $U_g$ of the three object system below. 
- three objects with masses m, 2m, 3m in a equilateral triangle of size d.

$$U_{sys} = U_{m,2m} + U_{m, 3m} + U_{2m,3m}$$ 

### 3.3.4 explore graphs showing potential energy as a function of position, discussing equilibrium points and other concepts illuminated by the graphical approach. 

**Conservative forces and their U(x) functions**
$$\Delta U_{a->b} = -W = -\int_a^b\vec{F}\cdot d\vec{r}$$

In 1 dimension:

$$\Delta U = -\int F dx$$
$$F(x) = -\frac{dU}{dx}$$
`Example:` Say a particular conservative force F(x) has a potential energy given by $U(x) = x-x^2$. Find the force exerted at x = 2

$$F(x) = -\frac{dU}{dx}$$
$$F(x) = 2x-1$$
$$F(2) = 2*2-1$$
$$F(2) = 3N$$

**U(x) and F(x), graphically**
- where is F(x) positive?
  - (6,10)
- where is F(x) zero?
  - (3,6)
- where is F(x) negative?
  - (0,3)

- Find F when x = 2 meters. 
$$F(x) = -\frac{dU}{dx}$$
$$F(2) = -4/3N$$

