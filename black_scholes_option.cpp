/* 
   Black Scholes Pricing Model
   Modified as a standalone which can be recompiled and re-run.
*/ 
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

// Standard normal probability density function
double norm_pdf(const double& x) 
{
    return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
}

// Approximation to cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double norm_cdf(const double& x) 
{
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) 
    {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } 
    else 
    {
        return 1.0 - norm_cdf(-x);
    }
}

// Calculates d_j, for j in {1,2}. This term appears in the closed
// form solution for the European call or put price
double d_j(const int& j, const double& S, const double& K, const double& r, const double& v, const double& T) 
{
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
}

// Calculate the European vanilla call price based on:
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double call_price(const double& S, const double& K, const double& r, const double& v, const double& T) 
{
    return S * norm_cdf(d_j(1, S, K, r, v, T))-K*exp(-r*T) * norm_cdf(d_j(2, S, K, r, v, T));
}

// Calculate the European vanilla put price based on:
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double put_price(const double& S, const double& K, const double& r, const double& v, const double& T) 
{
    return -S*norm_cdf(-d_j(1, S, K, r, v, T))+K*exp(-r*T) * norm_cdf(-d_j(2, S, K, r, v, T));
}

int main(int argc, char **argv) 
{
    // Parameter list of Option components with values 
    // as an example
    double S = 100.0;  // Underlying price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate (5%)
    double v = 0.2;    // Volatility of the underlying (20%)
    double T = 1.0;    // One year until expiry

    // Calculate the Call or Put values
    double call = call_price(S, K, r, v, T);
    double put = put_price(S, K, r, v, T);

    // Output parameters and prices
    cout << "Underlying:      " << S << endl;
    cout << "Strike:          " << K << endl;
    cout << "Risk-Free Rate:  " << r << endl;
    cout << "Volatility:      " << v << endl;
    cout << "Expiration:      " << T << endl;

    cout << "Call Price:      " << call << endl;
    cout << "Put Price:       " << put << endl;

    return 0;
}
