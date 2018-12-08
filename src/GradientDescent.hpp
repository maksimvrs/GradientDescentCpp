#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <limits>
#include <functional>
#include <cmath>

#include "vector_extensions.hpp"

template <typename T>
class GradientDescent {
public:
    explicit GradientDescent(T (*func)(std::vector<T>), std::vector<T> args, T step = 0.5)
    {
        setFunction(func);
        setStartPosition(args);
        m_step = step;
    }


    virtual ~GradientDescent() = default;

    void setFunction(T (*func)(std::vector<T>))
    {
        m_func = func;
    }

    T setStartPosition(std::vector<T> position)
    {
        m_currentPosition = position;
        m_prevPositon.resize(position.size());
        std::fill(m_prevPositon.begin(), m_prevPositon.end(), std::numeric_limits<T>::max());
        return m_func(position);
    }

    void setAccuracy(T accuracy)
    {
        m_accuracy = accuracy;
    }

    bool isConvergence()
    {
        return fabs(m_func(m_prevPositon) - m_func(m_currentPosition)) < m_accuracy;
    }

    std::vector<T> step()
    {
        m_prevPositon = m_currentPosition;
        std::vector<T> grad = m_derivative(m_currentPosition);
        auto gradientLine = [=](T step) {return m_func(m_currentPosition - step * grad);};
        m_step = symmetricOptimization(std::function<T (T)>(gradientLine), 0, 2, m_eps);
        std::vector<T> antiGradient = m_gradient(grad);
        m_currentPosition += antiGradient;
        return m_currentPosition;
    }


private:
    T m_step;
    static constexpr T m_eps = 0.000001;
    T m_accuracy = 0.000001;
    T (*m_func)(std::vector<T>);
    std::vector<T> m_currentPosition;
    std::vector<T> m_prevPositon;

    std::vector<T> m_derivative(std::vector<T> args)
    {
        std::vector<T> result(args.size());
        for (int i = 0; i < args.size(); i++) {
            std::vector<T> temp(args);
            temp[i] += m_eps;
            result[i] = (m_func(temp) - m_func(args)) / m_eps;
        }
        return result;
    }

    std::vector<T> m_gradient(std::vector<T> args)
    {
        return args * m_step;
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
