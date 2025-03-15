#ifndef __BLACK_SCHOLES_H
#define __BLACK_SCHOLES_H

#include <cmath>

/**
 * @class BlackScholesCall
 * @brief A class to calculate Black-Scholes option pricing and its Vega.
 */
class BlackScholesCall 
{
private:
    double S;  // Underlying asset price
    double K;  // Strike price
    double r;  // Risk-free rate
    double T;  // Time to maturity

public:
    /**
     * @brief Constructor for BlackScholesCall.
     * @param _S Underlying asset price.
     * @param _K Strike price.
     * @param _r Risk-free rate.
     * @param _T Time to maturity.
     */
    BlackScholesCall(double _S, double _K, double _r, double _T);

    /**
     * @brief Calculate the price of the option.
     * @param sigma Volatility of the underlying asset.
     * @return Option price.
     */
    double optionPrice(double sigma) const;

    /**
     * @brief Calculate the Vega of the option.
     * @param sigma Volatility of the underlying asset.
     * @return Option Vega.
     */
    double optionVega(double sigma) const;
};
#endif
