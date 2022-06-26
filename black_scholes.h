#ifndef BS_PRICES_H
#define BS_PRICES_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <algorithm>    

// Standard normal probability density function
double norm_pdf(const double x)
{
    return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x);
}

// Approximation to the cumulative distribution function for the standard normal distribution
double norm_cdf(const double x)
{
    double k = 1.0 / (1.0 + 0.2316419 * x);
    double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

    if (x >= 0.0)
    {
        return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
    }
    else
    {
        return 1.0 - norm_cdf(-x);
    }
}

// This calculates d_j, for j in {1,2}. This term appears in the closed
// form solution for the European call or put price
double d_j(const int j, const double S, const double K, const double r, const double v, const double T)
{
    return (log(S / K) + (r + (pow(-1, j - 1)) * 0.5 * v * v) * T) / (v * (pow(T, 0.5)));
}

// Calculate the European Expiry Call price based on
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double call_price(const double S, const double K, const double r, const double v, const double T)
{
    return S * norm_cdf(d_j(1, S, K, r, v, T)) - K * exp(-r * T) * norm_cdf(d_j(2, S, K, r, v, T));
}

// Calculate the European Expiry Call Delta
double call_delta(const double S, const double K, const double r, const double v, const double T)
{
    return norm_cdf(d_j(1, S, K, r, v, T));
}

// Calculate the European Expiry Call Gamma
double call_gamma(const double S, const double K, const double r, const double v, const double T)
{
    return norm_pdf(d_j(1, S, K, r, v, T)) / (S * v * sqrt(T));
}

// Calculate the European Expiry Call Vega
double call_vega(const double S, const double K, const double r, const double v, const double T)
{
    return S * norm_pdf(d_j(1, S, K, r, v, T)) * sqrt(T);
}

// Calculate the European Expiry Call Theta
double call_theta(const double S, const double K, const double r, const double v, const double T)
{
    return -(S * norm_pdf(d_j(1, S, K, r, v, T)) * v) / (2 * sqrt(T))
        - r * K * exp(-r * T) * norm_cdf(d_j(2, S, K, r, v, T));
}

// Calculate the European Expiry Call Rho
double call_rho(const double S, const double K, const double r, const double v, const double T)
{
    return K * T * exp(-r * T) * norm_cdf(d_j(2, S, K, r, v, T));
}

// Calculate the European Expiry Put price based on
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double put_price(const double S, const double K, const double r, const double v, const double T)
{
    return -S * norm_cdf(-d_j(1, S, K, r, v, T)) + K * exp(-r * T) * norm_cdf(-d_j(2, S, K, r, v, T));
}

// Calculate the European Expiry Put Delta
double put_delta(const double S, const double K, const double r, const double v, const double T)
{
    return norm_cdf(d_j(1, S, K, r, v, T)) - 1;
}

// Calculate the European Expiry Put Gamma
double put_gamma(const double S, const double K, const double r, const double v, const double T)
{
    return call_gamma(S, K, r, v, T); // Identical to Call by Put-Call parity
}

// Calculate the European Expiry Put Vega
double put_vega(const double S, const double K, const double r, const double v, const double T)
{
    return call_vega(S, K, r, v, T); // Identical to Call by Put-Call parity
}

// Calculate the European Expiry Put Theta
double put_theta(const double S, const double K, const double r, const double v, const double T)
{
    return -(S * norm_pdf(d_j(1, S, K, r, v, T)) * v) / (2 * sqrt(T))
        + r * K * exp(-r * T) * norm_cdf(-d_j(2, S, K, r, v, T));
}

// Calculate the European Expiry Put Rho
double put_rho(const double S, const double K, const double r, const double v, const double T)
{
    return -T * K * exp(-r * T) * norm_cdf(-d_j(2, S, K, r, v, T));
}

#endif

