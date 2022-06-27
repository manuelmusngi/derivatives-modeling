#include "black_scholes.h"
#include "newton_raphson.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) 
{

    // Parameter list with example values
    double S = 100.0;  // Underlying spot price
    double K = 100.0;  // Strike price
    double r = 0.05;   // Risk-free rate (example 5%)
    double T = 1.0;    // One year until option expiration
    double C_M = 10.5; // Option market price

    // Black-Scholes Call parameters
    BlackScholesCall bsc(S, K, r, T);

    // Newton-Raphson parameters
    double init = 0.3;  // Guess of impl. vol of 30%
    double epsilon = 0.001;

    // Calculate the Implied Volatility
    double sigma = newton_raphson<BlackScholesCall, &BlackScholesCall::option_price, 
                                  &BlackScholesCall::option_vega>(C_M, init, epsilon, bsc);

    // Output values
    cout << "Implied Vol: " << sigma << endl;

    return 0;
}
