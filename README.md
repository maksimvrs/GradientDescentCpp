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

double function(std::vector<double> args)
{
    return sin(args[0]) * cos(args[1]);
}

int main()
{
    GradientDescent<double> grad(function, {0.0, 0.0});
    std::cout << "Start position: " << std::fixed << std::setprecision(4)
              << 0.0 << " " << 0.0 << " " << function({0.0, 0.0}) << std::endl;
    while (!grad.isConvergence()) {
        std::vector<double> position = grad.step();
        std::cout << "Current position: ";
        for (double k : position)
            std::cout << std::fixed << std::setprecision(4) << k << " ";
        std:: cout << function(position) << std::endl;
    }
}
```
### Building
```
cmake ./
make 
./GradientDescentCpp
```
or
```
c++ --std=c++11 main.cpp -o GradientDescentCpp
```
