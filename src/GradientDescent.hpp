#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <limits>

struct Point {
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double x, y;
};

class GradientDescent {
public:
    explicit GradientDescent(double (*func)(double, double), double x = 0.0, double y = 0.0, double step = 0.5);

    virtual ~GradientDescent() = default;

    void setFunction(double (*func)(double, double));
    double setStartPosition(double x, double y);
    void setConvergence(double);
    bool isConvergence();
    Point step();

private:
    double m_step;
    static constexpr double m_eps = 0.000001;
    double m_converg = 0.000001;
    double (*m_func)(double, double);
    Point m_currentPosition = {0.0, 0.0};
    Point m_prevPositon = {std::numeric_limits<double>::max(), std::numeric_limits<double>::max()};

    double m_derivativeX(Point);
    double m_derivativeY(Point);
    Point m_gradient(Point);
};

#endif // GRADIENT_DESCENT_HPP
