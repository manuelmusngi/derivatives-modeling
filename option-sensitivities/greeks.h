#ifndef GREEKS_H
#define GREEKS_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <numeric>

/**
 * @namespace Greeks
 * @brief Contains functions to calculate option prices and Greeks.
 */
namespace Greeks {

/**
 * @brief Standard normal probability density function.
 * @param x The input value.
 * @return The probability density.
 */
inline double normPDF(const double x);

/**
 * @brief Approximations to the cumulative distribution function (CDF) for the standard normal distribution (PDF).
 * @param x The input value.
 * @return The cumulative probability.
 */
inline double normCDF(const double x);

/**
 * @brief Calculates d_j, for j in {1,2}. This term appears in the closed form solution for the European Call or Put price.
 * @param j The index (1 or 2).
 * @param S The current stock price.
 * @param K The strike price.
 * @param r The risk-free interest rate.
 * @param v The volatility of the underlying asset.
 * @param T The time to expiration.
 * @return The calculated d_j value.
 */
inline double d_j(const int j, const double S, const double K, const double r, const double v, const double T);

/**
 * @brief Calculate the price of a European Call option.
 * @param S The current stock price.
 * @param K The strike price.
 * @param r The risk-free interest rate.
 * @param v The volatility of the underlying asset.
 * @param T The time to expiration.
 * @return The price of the call option.
 */
inline double callPrice(const double S, const double K, const double r, const double v, const double T);

/**
 * @brief Calculate the Delta of a European Call option.
 * @param S The current stock price.
 * @param K The strike price.
 * @param r The risk-free interest rate.
 * @param v The volatility of the underlying asset.
 * @param T The time to expiration.
 * @return The Delta of the call option.
 */
inline double callDelta(const double S, const double K, const double r, const double v, const double T);

// Similarly, update the rest of the functions with detailed comments and mark them as inline if appropriate.

} // namespace Greeks

#endif // GREEKS_H
