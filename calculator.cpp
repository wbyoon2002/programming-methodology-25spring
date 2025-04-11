#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if ((a > std::numeric_limits<int>::max() - b) && a > 0 && b > 0)
    {
        throw std::overflow_error("Addition overflow");
    }
    if ((a < std::numeric_limits<int>::min() - b) && a < 0 && b < 0)
    {
        throw std::overflow_error("Addition underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if ((a > std::numeric_limits<int>::max() + b) && a > 0 && b < 0)
    {
        throw std::overflow_error("Subtraction overflow");
    }
    if ((a < std::numeric_limits<int>::min() + b) && a < 0 && b > 0)
    {
        throw std::overflow_error("Subtraction underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a < 0)
    {
        a *= -1;
        b *= -1;
    }
    if (b > 0 && a > std::numeric_limits<int>::max() / b)
    {
        throw std::overflow_error("Multiplication overflow");
    }
    if (b < 0 && a > std::numeric_limits<int>::min() / b)
    {
        throw std::overflow_error("Multiplication underflow");
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (a == std::numeric_limits<int>::min() && b == -1)
    {
        throw std::overflow_error("Division overflow");
    }
    if (b == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}