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
