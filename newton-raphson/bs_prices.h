#pragma once

#include <iostream>
#include <cmath>
#include <numeric>
#include <random>

// Normal Cumulative Distribution Function 
constexpr double normalCDF(double value)
{
    return 0.5 * std::erfc(-value * M_SQRT1_2);
}

// Calculates d_j, for j in {1,2}
// Closed form solution for the European call or put price
constexpr double d_j(const int j, const double S, const double K, const double r, const double sigma, const double T) 
{
    if (T <= 0 || sigma <= 0) {
        throw std::invalid_argument("Invalid input values");
    }
    return (std::log(S/K) + (r + (std::pow(-1, j-1)) * 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

/* Calculates call price based on:
    underlying S, 
    strike K, 
    risk-free rate r, 
    volatility of underlying sigma 
    time to maturity T
*/
constexpr double callPrice(const double S, const double K, const double r, const double sigma, const double T) 
{
    return S * normalCDF(d_j(1, S, K, r, sigma, T)) - K * std::exp(-r * T) * normalCDF(d_j(2, S, K, r, sigma, T));
}

// Calculate call Vega 'Greek' 
constexpr double callVega(const double S, const double K, const double r, const double sigma, const double T) 
{
    return S * std::sqrt(T) * std::exp(-0.5 * d_j(1, S, K, r, sigma, T) * d_j(1, S, K, r, sigma, T)) / std::sqrt(2 * M_PI);
}
