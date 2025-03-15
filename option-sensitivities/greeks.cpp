#include <iostream>
#include <cmath>
#include <algorithm>
#include "greeks.h"

#define _USE_MATH_DEFINES

using namespace std;

// Standard normal probability density function
double normPDF(const double x)
{
    constexpr double inv_sqrt_2pi = 1.0 / sqrt(2 * M_PI);
    return inv_sqrt_2pi * exp(-0.5 * x * x);
}

// Cumulative distribution function for the standard normal distribution
double normCDF(const double x)
{
    constexpr double k1 = 0.2316419;
    constexpr double k2 = 0.319381530;
    constexpr double k3 = -0.356563782;
    constexpr double k4 = 1.781477937;
    constexpr double k5 = -1.821255978;
    constexpr double k6 = 1.330274429;

    double k = 1.0 / (1.0 + k1 * x);
    double k_sum = k * (k2 + k * (k3 + k * (k4 + k * (k5 + k6 * k))));

    if (x >= 0.0)
    {
        return 1.0 - normPDF(x) * k_sum;
    }
    else
    {
        return 1.0 - normCDF(-x);
    }
}

// This calculates d_j, for j in {1,2}.
// This term appears in the closed form solution for the European Call or Put price
double d_j(const int j, const double S, const double K, const double r, const double v, const double T)
{
    return (log(S / K) + (r + (j == 1 ? 0.5 : -0.5) * v * v) * T) / (v * sqrt(T));
}

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
        - r * K * exp(-r * T) * normCDF(d_j(2, S, K, r, v, T));
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
    return callGamma(S, K, r, v, T); // Identical to call by put-call parity
}

double putVega(const double S, const double K, const double r, const double v, const double T)
{
    return callVega(S, K, r, v, T); // Identical to call by put-call parity
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
