#ifndef BLACK_SCHOLES_MODEL_H
#define BLACK_SCHOLES_MODEL_H

#include <cmath> // For mathematical functions

/**
 * @class BlackScholesModel
 * @brief A class to model the Black-Scholes options pricing model and calculate the Greeks.
 */
class BlackScholesModel 
{
    public:
        /**
         * @brief Constructor for BlackScholesModel.
         * @param spotPrice The current price of the underlying asset.
         * @param strikePrice The strike price of the option.
         * @param riskFreeRate The risk-free interest rate.
         * @param timeToExpiry The time to expiry of the option.
         * @param volatility The volatility of the underlying asset.
         */
        BlackScholesModel(double spotPrice = 100.0, 
                          double strikePrice = 100.0, 
                          double riskFreeRate = 0.05,
                          double timeToExpiry = 1.0, 
                          double volatility = 0.2);

        // Accessor methods
        double getDelta() const;
        double getTheta() const;
        double getGamma() const;
        double getVega() const;
        double getRho() const;

    private:
        // Input parameters
        double spotPrice_;
        double strikePrice_;
        double riskFreeRate_;
        double timeToExpiry_;
        double volatility_;

        // Helper functions
        double d1() const;
        double d2() const;
        double normalCDF(double x) const;

        // Greeks
        double delta_;
        double theta_;
        double gamma_;
        double vega_;
        double rho_;
};

#endif // BLACK_SCHOLES_MODEL_H
