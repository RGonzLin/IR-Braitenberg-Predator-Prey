# Predator-prey model using Braitenberg vehicles

This repository contains a Webots world (`/worlds/braitenberg_1.wbt`) for the simulation of a predator-prey model using Braitenber Vehicles. These vehicles are equipped with light sensors. The intensity of light received by each sensor is used as input to the vehicle's actuators, which control the speed and direction of the wheels. In particular two types of such vehicles were implemented; 2a and 2b.   
2a corresponds to the prey. In this case, the right-side sensor controls the speed of the right-side motor, and the left-side sensors of the left-side motor. This results in avoidance behavior, where the vehicle escapes from light sources.   
2b corresponds to the predator. The architecture is the exact opposite, the right-side sensor controls the speed of the left-side motor, and the left-side sensors of the right-side motor. This results in an attractive behavior, where the vehicle follows light sources.  
The prey contains a blue light source, while the prey (along with the corners of the world) contains a red one. The light sensors of the prey contain a filter that only lets red light through, while the predator contains one that only lets blue light through. As such, both agents can recognize each other, while remaining undisturbed by other light sources.
The Braitenberg vehicles were implemented using an ePuck robot. As they are quite slow, I recommend running the simulations at full speed.  
For the default initial locations of the vehicles, the predator eventually catches up with the prey; however, for other initial positions, the vehicles get caught in stable orbits, in which the predator forever chases the prey without being able to catch it. 

## Before starting
Install Webots, a software for robot simulation. 
