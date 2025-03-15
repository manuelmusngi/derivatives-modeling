#include <iostream>
#include <cmath>
#include <numbers>
#include "BlackScholesModel.h"

// Constructor
BlackScholesModel::BlackScholesModel(double spotPrice, double strikePrice, double riskFreeRate,
    double timeToExpiry, double volatility)
    : spotPrice_(spotPrice), strikePrice_(strikePrice), riskFreeRate_(riskFreeRate),
      timeToExpiry_(timeToExpiry), volatility_(volatility)
{
    // Initialize Greeks
    delta_ = normalCDF(d1());
    theta_ = (-spotPrice_ * normalCDF(d1()) * volatility_) / (2 * std::sqrt(timeToExpiry_)) -
             riskFreeRate_ * strikePrice_ * std::exp(-riskFreeRate_ * timeToExpiry_) * normalCDF(d2());
    gamma_ = normalCDF(d1()) / (spotPrice_ * volatility_ * std::sqrt(timeToExpiry_));
    vega_ = spotPrice_ * std::sqrt(timeToExpiry_) * normalCDF(d1());
    rho_ = strikePrice_ * timeToExpiry_ * std::exp(-riskFreeRate_ * timeToExpiry_) * normalCDF(d2());
}

// Accessor methods
double BlackScholesModel::getDelta() const
{
    return delta_;
}

double BlackScholesModel::getTheta() const
{
    return theta_;
}

double BlackScholesModel::getGamma() const
{
    return gamma_;
}

double BlackScholesModel::getVega() const
{
    return vega_;
}

double BlackScholesModel::getRho() const
{
    return rho_;
}

// Helper functions
double BlackScholesModel::d1() const
{
    return (std::log(spotPrice_ / strikePrice_) + (riskFreeRate_ + 0.5 * std::pow(volatility_, 2)) *
            timeToExpiry_) / (volatility_ * std::sqrt(timeToExpiry_));
}

double BlackScholesModel::d2() const
{
    return d1() - volatility_ * std::sqrt(timeToExpiry_);
}

double BlackScholesModel::normalCDF(double x) const // Phi(-∞, x) aka N(x)
{
    constexpr double pi = 3.14159265358979323846;
    return std::erfc(-x / std::sqrt(2)) / 2;
}
