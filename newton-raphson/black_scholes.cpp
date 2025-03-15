#ifndef __BLACK_SCHOLES_CPP
#define __BLACK_SCHOLES_CPP

#include "black_scholes.h"
#include "bs_prices.h"

// Constructor for BlackScholesCall
// Initializes the parameters for the Black-Scholes model
BlackScholesCall::BlackScholesCall(double _S, double _K, double _r, double _T) 
    : S(_S), K(_K), r(_r), T(_T) {}

// Calculate the option price using the Black-Scholes formula
// sigma: Volatility of the underlying asset
// Returns the price of the call option
double BlackScholesCall::optionPrice(double sigma) const 
{
    // Ensure sigma is positive
    if (sigma <= 0) {
        throw std::invalid_argument("Volatility (sigma) must be positive.");
    }
    return callPrice(S, K, r, sigma, T);
}

// Calculate the Vega of the option (sensitivity to volatility)
// sigma: Volatility of the underlying asset
// Returns the Vega of the call option
double BlackScholesCall::optionVega(double sigma) const 
{
    // Ensure sigma is positive
    if (sigma <= 0) {
        throw std::invalid_argument("Volatility (sigma) must be positive.");
    }
    return callVega(S, K, r, sigma, T);
}

#endif
