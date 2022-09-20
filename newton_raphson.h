#ifndef __NEWTON_RAPHSON_H
#define __NEWTON_RAPHSON_H

#include <cmath>

using namespace std;

template<typename T,
    double (T::* g)(double) const,
    double (T::* g_prime)(double) const>
    
double newton_raphson(double y_target,       // Target y value
                      double init,           // Initial x value
                      double epsilon,        // Tolerance
                      const T& root_func)                                              
{                                            // Set initial options prices and volatility
double y = (root_func.*g)(init);             // initial option prices
double x = init;                             // initial volatility

while (fabs(y - y_target) > epsilon) 
{
  double d_x = (root_func.*g_prime)(x);
  x += (y_target - y) / d_x;
  y = (root_func.*g)(x);
}
  return x;
}

#endif

