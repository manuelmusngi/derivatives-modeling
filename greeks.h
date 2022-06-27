#ifndef GREEKS_H
#define GREEKS_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <numeric>

// Standard normal probability density function
double norm_pdf(const double x);

// Approximations to the cumulative distribution function(cdf) for the standard normal distribution(pdf)
double norm_cdf(const double x);

// This calculates d_j, for j in {1,2}. This term appears in the closed form solution for the European Call or Put price
double d_j(const int j, const double S, const double K, const double r, const double v, const double T);

// Calculate the European Call price based on:
// underlying S, strike K, risk-free rate r, volatility of underlying sigma and time to maturity T
double call_price(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Call Delta
double call_delta(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Call Gamma
double call_gamma(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Call Vega
double call_vega(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Call Theta
double call_theta(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Call Rho
double call_rho(const double S, const double K, const double r, const double v, const double T);

// Calculate the European vanilla Put price based on:
// underlying S, strike K, risk-free rate r, volatility of underlying sigma and time to maturity T
double put_price(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Put Delta
double put_delta(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Put Gamma
double put_gamma(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Put Vega
double put_vega(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Put Theta
double put_theta(const double S, const double K, const double r, const double v, const double T);

// Calculate the European Put Rho
double put_rho(const double S, const double K, const double r, const double v, const double T);

#endif

