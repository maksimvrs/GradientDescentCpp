#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <limits>
#include <functional>
#include <cmath>

#include <iostream>

template <typename T>
struct Point {
    Point(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    T x, y;
};

template <typename T>
class GradientDescent {
public:
    explicit GradientDescent(T (*func)(T, T), T x = 0.0, T y = 0.0, T step = 0.5)
    {
        setFunction(func);
        setStartPosition(x, y);
        m_step = step;
    }


    virtual ~GradientDescent() = default;

    void setFunction(T (*func)(T, T))
    {
        m_func = func;
    }

    T setStartPosition(T x, T y)
    {
        m_currentPosition = Point<T>(x, y);
        return m_func(x, y);
    }

    void setAccuracy(T accuracy)
    {
        m_accuracy = accuracy;
    }

    bool isConvergence()
    {
        return fabs(m_func(m_prevPositon.x, m_prevPositon.y) -
                    m_func(m_currentPosition.x, m_currentPosition.y)) < m_accuracy;
    }

    Point<T> step()
    {
        m_prevPositon = m_currentPosition;
        T dx = m_derivativeX(m_currentPosition);
        T dy = m_derivativeY(m_currentPosition);
        auto gradientLine = [=](T step) {return m_func(m_currentPosition.x - step * dx,
                                                       m_currentPosition.y - step * dy);};
        m_step = symmetricOptimization(std::function<T (T)>(gradientLine), 0, 2, m_eps);
        std::cerr << "New step: " << m_step << std::endl;
        Point<T> gradient = m_gradient(Point<T>(dx, dy));
        m_currentPosition.x += gradient.x;
        m_currentPosition.y += gradient.y;
        return m_currentPosition;
    }


private:
    T m_step;
    static constexpr T m_eps = 0.000001;
    T m_accuracy = 0.000001;
    T (*m_func)(T, T);
    Point<T> m_currentPosition = {0.0, 0.0};
    Point<T> m_prevPositon = {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()};

    T m_derivativeX(Point<T> point)
    {
        return (m_func(point.x + m_eps, point.y) - m_func(point.x, point.y)) / m_eps;
    }

    T m_derivativeY(Point<T> point)
    {
        return (m_func(point.x, point.y + m_eps) - m_func(point.x, point.y)) / m_eps;
    }

    Point<T> m_gradient(Point<T> point)
    {
        return {-point.x * m_step, -point.y * m_step};
    }

    const double goldenRatio = (1 + sqrt(5)) / 2;

    T symmetricOptimization(std::function<T (T)> func, T a, T b, T accuracy)
    {
        T x1, x2;
        while (fabs(b - a) > accuracy) {
            x1 = b - (b - a) / goldenRatio;
            x2 = a + (b - a) / goldenRatio;
            if (func(x1) >= func(x2))
                a = x1;
            else
                b = x2;
        }
        return (a + b) / 2;
    }

};

#endif // GRADIENT_DESCENT_HPP
