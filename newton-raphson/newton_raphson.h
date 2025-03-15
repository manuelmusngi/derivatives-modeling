#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include <cmath>
#include <numeric>

/**
 * @brief Perform Newton-Raphson method to find the root of a function.
 * 
 * @tparam T Class type that implements the function and its derivative.
 * @tparam g Member function pointer to the function.
 * @tparam g_prime Member function pointer to the derivative of the function.
 * @param y_target Target y value to find the corresponding x.
 * @param init Initial guess for the x value.
 * @param epsilon Tolerance for the root finding.
 * @param root_func Instance of the class implementing the function and its derivative.
 * @return double The x value corresponding to the target y.
 */
template<typename T, 
         double (T::*g)(double) const,
         double (T::*g_prime)(double) const>
double newton_raphson(double y_target,       // Target y value
                      double init,           // Initial x value
                      double epsilon,        // Tolerance
                      const T& root_func)    //
{   
    double y = (root_func.*g)(init);
    double x = init;

    // Iteratively apply Newton-Raphson method
    while (std::fabs(y - y_target) > epsilon) 
    {
        double d_x = (root_func.*g_prime)(x);

        // Check for division by zero
        if (d_x == 0.0) {
            throw std::runtime_error("Derivative is zero, cannot proceed with Newton-Raphson method");
        }

        x += (y_target - y) / d_x;
        y = (root_func.*g)(x);
    }
    return x;
}

#endif // NEWTON_RAPHSON_H
