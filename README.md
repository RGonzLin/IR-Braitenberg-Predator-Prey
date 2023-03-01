# Predator-prey model using Braitenberg vehicles

This repository contains a Webots world (`/worlds/braitenberg_1.wbt`) for the simulation of a predator-prey model using Braitenberg vehicles. These vehicles are equipped with light sensors. The intensity of light received by each sensor is used as input to the vehicle's actuators, which control the speed of the wheels. In particular two types of such vehicles were implemented; 2a and 2b.   
2a corresponds to the prey. In this case, the right-side sensors controls the speed of the right-side motor, and the left-side sensors of the left-side motor. This results in avoidance behavior, where the vehicle escapes from light sources.   
2b corresponds to the predator. The architecture is the exact opposite, the right-side sensor controls the speed of the left-side motor, while the left-side sensor of the right-side motor. This results in an attractive behavior, where the vehicle follows light sources.  
The prey contains a blue light source, while the predator (along with the corners of the world) contains a red one. The light sensors of the prey contain a filter that only lets red light through, while the predator contains one that only lets blue light through. As such, both agents can recognize each other, while remaining undisturbed by other light sources.
The Braitenberg vehicles were implemented using ePuck robots. As they are quite slow, I recommend running the simulations at full speed.  
For the default initial locations of the vehicles, the predator eventually catches up with the prey; however, for other initial positions, the vehicles get caught in stable orbits, in which the predator forever chases the prey without being able to catch it. 

https://user-images.githubusercontent.com/65770155/222192784-380d5ec2-c9db-4ba3-a243-199038408c59.mp4

## Before starting
Install Webots, a software for robot simulation. 
