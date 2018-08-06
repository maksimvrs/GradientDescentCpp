# GradientDescentCpp
A simple gradient descent library of a function of two variables on c++
## Getting started
### Installing
```
git clone https://github.com/maksimvrs/GradientDescentCpp.git
```
### Example
A ```function()``` is an optimizable function. ```grad.step()``` returns a position at each step.
```
#include <iostream>
#include <iomanip>
#include <cmath>

#include "./src/GradientDescent.hpp"

double function(double x, double y)
{
    return sin(x) * cos(y);
}

int main()
{
    GradientDescent grad(function, 0.0, 0.0);
    std::cout << "Start position: " << std::fixed << std::setprecision(4)
              << 0.0 << " " << 0.0 << " " << function(0.0, 0.0) << std::endl;
    for (int i = 0; i < 10; i++) {
        Point position = grad.step();
        std::cout << "Current position: " << std::fixed << std::setprecision(4)
                  << position.x << " " << position.y << " " << function(position.x, position.y) << std::endl;
    }
}
```
### Building
```
cmake ./
make 
./GradientDescentCpp
```
