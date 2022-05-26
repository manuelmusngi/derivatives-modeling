#ifndef __NEWTON_RAPHSON_H
#define __NEWTON_RAPHSON_H

#include <cmath>

template<typename T, 
         double (T::*g)(double) const,
         double (T::*g_prime)(double) const>
double newton_raphson(double y_target,       // Target y value
                      double init,           // Initial x value
                      double epsilon,        // Tolerance
                      const T& root_func) {  // Function objec
  // Set the initial option prices and volatility
  double y = (root_func.*g)(init);           // Initial option prices
  double x = init;                           // Initial volatility

  // While y and y_target are not similar enough
  // Take the vega of the option and recalculate
  // a new call price based on the best linear
  // approximation at that particular vol value
  while (fabs(y-y_target) > epsilon) {
    double d_x = (root_func.*g_prime)(x);
    x += (y_target-y)/d_x;
    y = (root_func.*g)(x);
  }
  return x;
}

#endif
