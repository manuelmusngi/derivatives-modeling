#ifndef BLACKSCHOLESMODEL_H
#define BLACKSCHOLESMODEL_H

#include <cmath> // For mathematical functions

class BlackScholesModel 
{
    public:
        // Constructor
        BlackScholesModel(double spotPrice, 
                          double strikePrice, 
                          double riskFreeRate,
                          double timeToExpiry, 
                          double volatility);

        // Accessor methods
        double getDelta();
        double getTheta();
        double getGamma();
        double getVega();
        double getRho();

    private:
        // Input parameters
        double spotPrice_;
        double strikePrice_;
        double riskFreeRate_;
        double timeToExpiry_;
        double volatility_;

        // Helper functions
        double d1();
        double d2();
        double normalCDF(double x);

        // Greeks
        double delta_;
        double theta_;
        double gamma_;
        double vega_;
        double rho_;
};

#endif 
