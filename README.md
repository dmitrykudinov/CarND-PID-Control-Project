# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Notes

1. Since the simulator has no obvious API to automate the "Twiddle" process of finding optimal parameters, I had to do pretty much a binary search, at the same time getting a "gut feeling" developed of what exactly each of the Kp, Ki, and Kd are useful for. Still, doing a manual search takes too much time and makes the process too long. There needs to be an API built into the Simulator so onc can put the vehicle at the beginning of the track, and make it run for a single lap or until it’s off the track, recording the Total CTE value, so Twiddle algorithm can be effectively implemented.

2. In case of the Steering PID controller, Kp is useful for immediate response to the fast changing CTE values, whereas Kd is perfect to compensate for over-steering. Ki - works to compensate for bias, but on a curvy road it is dangerous to have it high, as it starts smoothing the trajectory too much leading to cut corners or under-steering.

3. In case of the PID controller for the throttle manipulation, I chose to use cte^2 as the input parameter in order to make controller indifferent of the cte sign. The Kp parameter here plays the major role as we need the fastest reaction to significant cte values and smoothing of the throttle jumps will be done naturally by the car's inertia, so I chose biggest value for the Kp parameter, whereas leaving the Kd and Ki close to zero.

4. The commited code with the given set of parameters and two PID controllers, allows the vehicle to safely make through the whole lap at times reaching 43 mph. Still, there is plenty of oscillation happening – need an API for Twiddle!

