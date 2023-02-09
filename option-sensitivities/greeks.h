#ifndef GREEKS_H
#define GREEKS_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <numeric>

// Standard normal probability density function
double normPDF(const double x);

// Approximations to the cumulative distribution function(cdf) for the standard normal distribution(pdf)
double normCDF(const double x);

// This calculates d_j, for j in {1,2}. 
// This term appears in the closed form solution for the European Call or Put price
double d_j(const int j, const double S, const double K, const double r, const double v, const double T);

/* Calculate Option Greek based on:
   underlying S, 
   strike K, 
   risk-free rate r, 
   volatility of underlying v 
   time to expiration T
*/

// Call Option
double callPrice(const double S, const double K, const double r, const double v, const double T);
double callDelta(const double S, const double K, const double r, const double v, const double T);
double callGamma(const double S, const double K, const double r, const double v, const double T);
double callVega(const double S, const double K, const double r, const double v, const double T);
double callTheta(const double S, const double K, const double r, const double v, const double T);
double callRho(const double S, const double K, const double r, const double v, const double T);

// Put Option
double putPrice(const double S, const double K, const double r, const double v, const double T);
double putDelta(const double S, const double K, const double r, const double v, const double T);
double putGamma(const double S, const double K, const double r, const double v, const double T);
double putVega(const double S, const double K, const double r, const double v, const double T);
double putTheta(const double S, const double K, const double r, const double v, const double T);
double putRho(const double S, const double K, const double r, const double v, const double T);

#endif


