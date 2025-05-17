# Unit 4 Linear Momentum 

## 4.1 Linear Momentum 

### 4.1. define momentum for a single object and for a system of many objects. We will derive force and momentum change relationship using Newton's second law. 

**Definition**
- linear momentum of an object is the product of mass and velocity 

$$\vec{p} = m\vec{v}$$
- unit of momentum: $kg \cdot m/s$
- Momentum $\vec{p}$ is a vector quantity and has the same direction as the object's velocity, $\vec{v}.$
- Total momentum of a system of multiple objects: 
$$\vec{p} = \vec{p}_A + \vec{p}_B + ...$$

**Force and Momentum Change**

`Newton's Second Law`: When a net force acts on an object, the velocity of the object changes. 

$$\sum \vec{F} = m\vec{a}$$

- The net exertnal force exerted on an object is equal to the time rate of change of its momentum change. 

$$\sum \vec{F} = m\frac{d\vec{v}}{dt} = \frac{d}{dt}(m\vec{v}) = \frac{d\vec{p}}{dt}$$

$$\vec{F}_{avg} = \frac{\Delta \vec{p}}{\Delta t}$$

**Example**
- A system consists of two masses $m_1 < m_2$. The objects are connected by a massless stirng hung over a pulley, then released. When speed of each object is v, what is magnitude of total linear momentum of the system. 

- Objects 1 and 2 have the same momentum. Object 1 can have more kinetic energy than object 2 if, compared with object 2, it is moving faster
$$K = \frac{1}{2}mv^2 = \frac{1}{2}pv$$

- The momentum of a moving object, p, as a function of time, t, is given by the expression $p(t) = kt^3$, where k is a constant. The force causing this motion is given by expression. 
$$\vec{F}_{net} = \frac{d\vec{p}}{dt} = 3kt^2$$

## 4.2 Change in Momentum and Impulse 

### 4.2.1 plot momentum and force vs. time graphs to describe a bouncing a motion. We'll also define impulse and derive the impulse-momentum theorem. 
- Momentum is the property of a moving object that makes it difficult to stop
$$\vec{F}_{avg} = \frac{\Delta \vec{p}}{\Delta t}$$
$$\Delta \vec{p} = \vec{F}_{avg}\Delta t$$
- Sketch the momentum and force vs. time graphs for a bouncing motion. 

**Kinematic Quantities and Motion graphs**

$$v = \frac{dx}{dt}$$
$$a = \frac{dv}{dt}$$

$$v = v_0 + \int_0^t adt$$
$$x = x_0 + \int_0^t vdt $$
**Bouncing ball force and momentum graphs**
$$mv = mv_0 + \int_0^t madt$$
$$ma = m\frac{dv}{dt} = \frac{dp}{dt}$$
$$p = p_0 + \int_0^t Fdt$$
$$F = \frac{dp}{dt}$$

**Impulse-Definition**
- `Impulse` is defined as the integral of a force exerted on a n object over a time interval. Impulse is equal to the area under the force vs. time graph. 

**Impulse-Momentum Theorem**
- Impulse is equal to the object's change in momentum. 
$$\vec{J} = \int_{t1}^{t2} \sum \vec{F} dt = \vec{p}_2 - \vec{p}_1$$
$$\vec{J} = \Delta \vec{p}= m\vec{v}_2 - m\vec{v}_1$$
- Unit of Impulse: $N\cdot s$ or $kg\cdot m/s$
- Impulse , $\vec{J}$, is a vector quantity that has the same direction as the net force exerted on the object. 
$$\sum F_{x}t = mv_x - mv_{0x}$$
$$\sum F_{y}t = mv_y - mv_{0y}$$

**Bouncing Tennis Ball**
- Determine collision time and average impact force during the rebound. 
- Determine average impact force. 
$$\vec{F}_{avg} = m\vec{a}_{avg}$$
$$\vec{a}_{avg} = \frac{\Delta \vec{v}}{\Delta t}$$

### 4.2.2 compare the work-energy theorem with the impulse-momentum theorem and solve for unknown quantities using these relationships. 

$$A: m_a, B:4m_a$$
- Change in a object's momentum is due to impulse which depends on the time over which net force acts. 
 $$\vec{J} = \int_{t1}^{t2} \sum \vec{F} dt = \vec{p}_2 - \vec{p}_1 = m\vec{v}_2 - m\vec{v}_1$$
- By contrast, `kinetic energy` changes when `work` is done on an object; the total work depends on the `distance` over which the net force acts. 

$$W_{net} = \int_{p_1}^{p_2}\sum \vec{F} \cdot d\vec{l} = \frac{1}{2}m\vec{v}_2^2 - \frac{1}{2}m\vec{v}_1^2$$

### 4.2.3 explore the effect of collision time on impulse and impact force during collisions using the impulse-momentum theorem. 
**Momentum vs. Kinetic Energy**
- Impulse-Momentum Theorem: 
$$\vec{J} = \int_{t1}^{t2} \sum \vec{F} dt = m\vec{v}_2 - m\vec{v}_1$$

$$\vec{J} = F_{avg} \Delta t$$

- Work Energy Theorem: 
$$W_{net} = \int_{x_1}^{x_2}\sum \vec{F} \cdot d\vec{r} = \frac{1}{2}m\vec{v}_2^2 - \frac{1}{2}m\vec{v}_1^2$$

$$W_{net} = F_{avg} \Delta x$$
- Is it possible to have a faster serve in tennis without exerting a bigger force?

$$\int_{t_1}^{t_2} \vec{F}_{net}dt = \vec{p}(t_2)-\vec{p}(t_1) = \Delta p$$

- Force, F, times "follow-through", t, equals change in momentum, p. 
- The change in momentum that a force produces on an object depends on how long the force acts on the body. 

$$\vec{F}_{avg}\Delta t = \Delta \vec{p}$$

$$\vec{F}_{avg} = \frac{\vec{J}}{\Delta t} = \frac{\Delta \vec{p}}{\Delta t}$$

- Can you think about another approach that can be used to determine the collision time and the impact force of the bouncing ball without using graphs? 

### 4.2.4 explore how bouncing effects impulse and impact force during collisions using the impulse-momentum theorem. 

- Two equal mass balls swing down and hit identical wooden blocks travel identical speeds. Ball A bounces back ball b stops when it hits the block. Which ball is more likely to knock the block over. 
- the ball that bounces off will have more impact force.

### Takeaways 
- `Bouncing` means `greater change in velocity` and `momentum`. 
- greater momentum change means greater impulse and impact force given same impact time. 
$$\Delta \vec{p} = \vec{F}_{avg}\Delta t$$
$$\vec{F}_{avg} = \frac{\Delta \vec{p}}{\Delta t}$$

### 4.2.5 use the impulse-momentum theorem and Newton's second Law to analyze the behavior of systems with constant mass and solve for unknown quantities. 

### 4.2.6 use the impulse-momentum theorem to analyze the behavior of systems which changing mass and solve for unknown quantities. 

$$\sum \vec{F} = \frac{d\vec{p}}{dt} = \vec{v}\frac{dm}{dt}$$
$$\sum \vec{F} = (6\frac{m}{s})(1\frac{kg}{s}) = 6N$$

**Rocket propulsion 1**
$$m\frac{dv}{dt} = -\frac{dm}{dt}v_{ex}$$

## 4.3 Conservation of momentum 

### 4.3.1 define a system. We'll also explore when and why a system's momentum must remain constant. 

**Conservation of Momentum**
- In the absence of net external forces on a system... the p of the system remains constant. 

### 4.3.2 use the principle of conservation of momentum to solve a problem, design an experimental setup, and analyze a simulation. 

**Solving problems with conservation of p**
- a cart with mass $m_a$ moves on a frictionless horizontal track at velocity $v_{1a}$
- another cart, with mass $m_b$ is initially at rest on the track.
- The carts collide and stick together. 
- What will be the velocity, $v_2$, of the two attached carts?

1. Draw a "before/after" picture. 
2. Choose a system in which p stays constant. 
3. Write its p before and after, algebraically. 

**Designing an experiment**

Carts A and B move on a frictionless, horizontal track. Cart A is initially moving towards cart B, which is initally at rest. The carts stick together when they collide. 
- students want to determine if the two cart system's p is equal before and after the collision. 
- Outline an experiment they could perform. Indicate what data to take and what lab equipment to use.

$$y_{com} = \frac{m_sy_s + m_by_b}{m_s+m_b} = \frac{m*\frac{l}{2}}{2m+m}$$

## 4.4 elastic and inelastic collisions

### 4.4.2 practive solving problems using elastic and inelastic collisions. 

- `Elastic` collisions: K constant in system 
- `Inelastic` collisions: nonconservative forces change K to othe forms. 
- `Completely inelastic` collisions: objects stick together
- 