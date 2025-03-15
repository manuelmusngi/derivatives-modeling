#ifndef __BLACK_SCHOLES_H
#define __BLACK_SCHOLES_H

#include <cmath>
#include <stdexcept>

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
     * @param _S Underlying asset price (must be non-negative).
     * @param _K Strike price (must be non-negative).
     * @param _r Risk-free rate (must be non-negative).
     * @param _T Time to maturity in years (must be non-negative).
     * @throws std::invalid_argument if any parameter is negative.
     */
    BlackScholesCall(double _S, double _K, double _r, double _T)
        : S(_S), K(_K), r(_r), T(_T)
    {
        if (_S < 0 || _K < 0 || _r < 0 || _T < 0) {
            throw std::invalid_argument("All parameters must be non-negative.");
        }
    }

    /**
     * @brief Calculate the price of the option.
     * @param sigma Volatility of the underlying asset (must be non-negative).
     * @return Option price.
     * @throws std::invalid_argument if sigma is negative.
     */
    double optionPrice(double sigma) const {
        if (sigma < 0) {
            throw std::invalid_argument("Volatility (sigma) must be non-negative.");
        }
        // Implement Black-Scholes formula for option pricing here
        // ...
        return 0.0; // Placeholder
    }

    /**
     * @brief Calculate the Vega of the option.
     * @param sigma Volatility of the underlying asset (must be non-negative).
     * @return Option Vega.
     * @throws std::invalid_argument if sigma is negative.
     */
    double optionVega(double sigma) const {
        if (sigma < 0) {
            throw std::invalid_argument("Volatility (sigma) must be non-negative.");
        }
        // Implement Black-Scholes formula for option Vega here
        // ...
        return 0.0; // Placeholder
    }
};

#endif
