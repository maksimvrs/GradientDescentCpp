#include "GradientDescent.hpp"

GradientDescent::GradientDescent(double (*func)(double, double), double x, double y, double step)
{
    setFunction(func);
    setStartPosition(x, y);
    m_step = step;
}

void GradientDescent::setFunction(double (*func)(double, double))
{
    m_func = func;
}

double GradientDescent::setStartPosition(double x, double y)
{
    m_currentPosition = Point(x, y);
    return m_func(x, y);
}

double GradientDescent::m_derivativeX(Point point)
{
    return (m_func(point.x + m_eps, point.y) - m_func(point.x, point.y)) / m_eps;
}

double GradientDescent::m_derivativeY(Point point)
{
    return (m_func(point.x, point.y + m_eps) - m_func(point.x, point.y)) / m_eps;
}

Point GradientDescent::m_gradient(Point point)
{
    return {-point.x * m_step, -point.y * m_step};
}

Point GradientDescent::step() {
    double dx = m_derivativeX(m_currentPosition);
    double dy = m_derivativeY(m_currentPosition);
    Point gradient = m_gradient(Point(dx, dy));
    m_currentPosition.x += gradient.x;
    m_currentPosition.y += gradient.y;
    return m_currentPosition;
}
