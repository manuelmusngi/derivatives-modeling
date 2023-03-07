#include <iostream>
#include <cmath>
#include <numbers>
#include "BlackScholesModel.h"


// Constructor
BlackScholesModel::BlackScholesModel(double spotPrice, double strikePrice, double riskFreeRate,
    double timeToExpiry, double volatility) :
    spotPrice_(spotPrice), strikePrice_(strikePrice), riskFreeRate_(riskFreeRate),
    timeToExpiry_(timeToExpiry), volatility_(volatility)

// Greeks
{
    delta_ = normalCDF(d1());
    theta_ = (-spotPrice_ * normalCDF(d1()) * volatility_) / (2 * sqrt(timeToExpiry_)) -
               riskFreeRate_ * strikePrice_ * exp(-riskFreeRate_ * timeToExpiry_) * normalCDF(d2());
    gamma_ = normalCDF(d1()) / (spotPrice_ * volatility_ * sqrt(timeToExpiry_));
    vega_ = spotPrice_ * sqrt(timeToExpiry_) * normalCDF(d1());
    rho_ = strikePrice_ * timeToExpiry_ * exp(-riskFreeRate_ * timeToExpiry_) * normalCDF(d2());
}

// Accessor methods
double BlackScholesModel::getDelta()
{
    return delta_;
}

double BlackScholesModel::getTheta()
{
    return theta_;
}

double BlackScholesModel::getGamma()
{
    return gamma_;
}

double BlackScholesModel::getVega()
{
    return vega_;
}

double BlackScholesModel::getRho()
{
    return rho_;
}

// Helper functions
double BlackScholesModel::d1()
{
    return (log(spotPrice_ / strikePrice_) + (riskFreeRate_ + 0.5 * pow(volatility_, 2)) *
                timeToExpiry_) / (volatility_ * sqrt(timeToExpiry_));
}

double BlackScholesModel::d2()
{
    return d1() - volatility_ * sqrt(timeToExpiry_);
}

double BlackScholesModel::normalCDF(double x) // Phi(-∞, x) aka N(x)
{
    const double pi = 3.14159265358979323846;
    return std::erfc(-x / std::sqrt(2)) / 2;
}
 