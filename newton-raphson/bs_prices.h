#ifndef BS_PRICES_H
#define BS_PRICES_H

#define _USE_MATH_DEFINES
#define M_SQRT1_2  0.707106781186547524401

#include <iostream>
#include <cmath>
#include <numeric>
#include <random>


// Normal Cumulative Distribution Function 
double normalCDF(double value)
{
return 0.5 * erfc(-value * M_SQRT1_2);
}

// Calculates d_j, for j in {1,2}
// Closed form solution for the European call or put price
double d_j(const int j, const double S, const double K, const double r, const double sigma, const double T) 
{
  return (log(S/K) + (r + (pow(-1,j-1))*0.5*sigma*sigma)*T)/(sigma*(pow(T,0.5)));
}

/*Calculates call price based on:
    underlying  S, 
    strike  K, 
    risk-free rate  r, 
    volatility of underlying  sigma 
    time to maturity  T
*/

double callPrice(const double S, const double K, const double r, const double sigma, const double T) 
{
    return S * normalCDF(d_j(1, S, K, r, sigma, T))-K*exp(-r*T) * normalCDF(d_j(2, S, K, r, sigma, T));
}

// Calculate call Vega 'Greek' 
double callVega(const double S, const double K, const double r, const double sigma, const double T) 
{
    return S * sqrt(T) * std::normal_distribution<double>(d_j(1, S, K, r, sigma, T));  
//  return S * sqrt(T) * norm_pdf(d_j(1, S, K, r, sigma, T));
}

#endif
