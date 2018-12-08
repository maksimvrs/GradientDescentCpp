#include <vector>

template <typename T>
std::vector<T> operator+=(std::vector<T>& a, const std::vector<T>& b)
{
    for (int i = 0; i < a.size(); i++)
        a[i] += b[i];
    return a;
}


template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b)
{
    std::vector<T> result(a);
    for (int i = 0; i < result.size(); i++)
        result[i] += b[i];
    return result;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b)
{
    std::vector<T> result(a);
    for (int i = 0; i < result.size(); i++)
        result[i] -= b[i];
    return result;
}


template <typename T>
std::vector<T> operator*(const int& value, const std::vector<T>& vec)
{
    std::vector<T> result(vec);
    for (int i = 0; i < result.size(); i++)
        result[i] *= value;
    return result;
}

template <typename T>
std::vector<T> operator*(const std::vector<T>& vec, const int& value)
{
    std::vector<T> result(vec);
    for (int i = 0; i < result.size(); i++)
        result[i] *= value;
    return result;
}

template <typename T>
std::vector<T> operator/(const int& value, const std::vector<T>& vec)
{
    std::vector<T> result(vec);
    for (int i = 0; i < result.size(); i++)
        result[i] /= value;
    return result;
}

template <typename T>
std::vector<T> operator/(const std::vector<T>& vec, const int& value)
{
    std::vector<T> result(vec);
    for (int i = 0; i < result.size(); i++)
        result[i] /= value;
    return result;
}
