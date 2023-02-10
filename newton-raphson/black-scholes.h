#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <algorithm>    

// Standard normal probability density function
double normPDF(const double x)
{
    return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x);
}

// Approximation to the cumulative distribution function for the standard normal distribution
double normCDF(const double x)
{
    double k = 1.0 / (1.0 + 0.2316419 * x);
    double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

    if (x >= 0.0)
    {
        return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
    }
    else
    {
        return 1.0 - normCDF(-x);
    }
}

// This calculates d_j, for j in {1,2}. This term appears in the closed
// form solution for the European call or put price
double d_j(const int j, const double S, const double K, const double r, const double v, const double T)
{
    return (log(S / K) + (r + (pow(-1, j - 1)) * 0.5 * v * v) * T) / (v * (pow(T, 0.5)));
}

/* Calculate Option Greek based on:
   underlying S, 
   strike K, 
   risk-free rate r, 
   volatility of underlying v 
   time to expiration T
*/

// Call Option
double callPrice(const double S, const double K, const double r, const double v, const double T)
{
    return S * normCDF(d_j(1, S, K, r, v, T)) - K * exp(-r * T) * normCDF(d_j(2, S, K, r, v, T));
}

double callDelta(const double S, const double K, const double r, const double v, const double T)
{
    return normCDF(d_j(1, S, K, r, v, T));
}

double callGamma(const double S, const double K, const double r, const double v, const double T)
{
    return normPDF(d_j(1, S, K, r, v, T)) / (S * v * sqrt(T));
}

double callVega(const double S, const double K, const double r, const double v, const double T)
{
    return S * normPDF(d_j(1, S, K, r, v, T)) * sqrt(T);
}

double callTheta(const double S, const double K, const double r, const double v, const double T)
{
    return -(S * normPDF(d_j(1, S, K, r, v, T)) * v) / (2 * sqrt(T))
        - r * K * exp(-r * T) * normPDF(d_j(2, S, K, r, v, T));
}

double callRho(const double S, const double K, const double r, const double v, const double T)
{
    return K * T * exp(-r * T) * normCDF(d_j(2, S, K, r, v, T));
}

// Put Option
double putPrice(const double S, const double K, const double r, const double v, const double T)
{
    return -S * normCDF(-d_j(1, S, K, r, v, T)) + K * exp(-r * T) * normCDF(-d_j(2, S, K, r, v, T));
}

double putDelta(const double S, const double K, const double r, const double v, const double T)
{
    return normCDF(d_j(1, S, K, r, v, T)) - 1;
}

double putGamma(const double S, const double K, const double r, const double v, const double T)
{
    return callGamma(S, K, r, v, T); // Identical to Call by Put-Call parity
}

double putVega(const double S, const double K, const double r, const double v, const double T)
{
    return callVega(S, K, r, v, T); // Identical to Call by Put-Call parity
}

double putTheta(const double S, const double K, const double r, const double v, const double T)
{
    return -(S * normPDF(d_j(1, S, K, r, v, T)) * v) / (2 * sqrt(T))
        + r * K * exp(-r * T) * normCDF(-d_j(2, S, K, r, v, T));
}

double putRho(const double S, const double K, const double r, const double v, const double T)
{
    return -T * K * exp(-r * T) * normCDF(-d_j(2, S, K, r, v, T));
}

#endif

