# Modeling l<sub>n</sub>  Metric Trends in C++

Created By : Tyler Dorey

The purose of this project is to model the trends in different functions of the general l<sub>n</sub> metric on sets of points in either 2d or 3d.  

Please note this project was created in Visual Studio 2022 so you will need that version unless you plan on creating your own Visual Studio solution. 

## About the l<sub>n</sub> Metric:
The l<sub>n</sub> metric is one of the most frequently used distance metrics in coordinate geometry.  Without even knowing what the l<sub>n</sub> metric is you are most likely already familiar with the Euclidean distance metric also known as the l<sub>2</sub> metric as n = 2 (more on that below):

![euclideanMetric](https://user-images.githubusercontent.com/98759325/154756299-64f8fe4b-8497-482a-9b68-be89b83dac70.JPG)

This metric is something taught to almost all students as they go through general education.  
<br/>However, there is a more general version of this metric for all n greater than or equal to 1:

![generalMetric](https://user-images.githubusercontent.com/98759325/154756680-e0dde418-674d-4c95-8de9-9fcfc5bd0515.JPG)

If you use different values for n in the generalized form on the same two points you may realize that there emerges a trend in the distances as n increases.  That is the core purpose of this project.  To analyize and make conclusions about the trend that emerges.

## About the Project:

Currently the project contains a simple Point struct which has the following functions:
- 3 Constructors:
1) Default constructor - creates a 2d point at (0,0)
2) 2d constructor - takes a x and y coordinate
3) 3d constructor - takes x, y, and z coordinates
<br />**Please note:  For 2d points the z coordinate is initialized to NaN**
- Overriden == and != operators for both 2d and 3d points
- Overriden >> and << operators (NOTE: Input uses std::cout for prompts, also asks user if 2d or 3d)
- Overriden subtraction operator (Do not mix 2d and 3d points, it will cause an error currently)
- A function to check if a point is 3d
- A distance calculation on two points requiring a value for n to determine which metric will be used

#### Current Goals:
- Create a .cpp file for direct interaction with user through the console
- Study 3d point trends further

#### Long Term Goals: 
- Find a graphics library to create a GUI which the user can use to dynamically calculate distances between points and constructions 
- Create a Excel Log of observations of Different Points
- Create a research paper about a potential infinity model of l<sub>n</sub> metric (Possible, not yet planned)

This project is licensed under the terms of the MIT license.
