/*
	Calculation of Options Sensitivities
*/
#include <iostream>
#include <cmath>
#include "greeks.h"
#include "greeks.cpp"

// using namespace std;

int main(int argc, char** argv) 
{
	// Parameter list example
	auto S = 100.0;  // Instrument price
	auto K = 100.0;  // Strike price
	auto r = 0.05;   // Risk-free rate (example 5%)
	auto v = 0.2;    // Volatility of the underlying (example 20%)
	auto T = 1.0;    // One year until expiration

	// Calculate the Call/Put values and Options Greeks
	double call = callPrice(S, K, r, v, T);
	double call_delta_v = callDelta(S, K, r, v, T);
	double call_gamma_v = callGamma(S, K, r, v, T);
	double call_vega_v = callVega(S, K, r, v, T);
	double call_theta_v = callTheta(S, K, r, v, T);
	double call_rho_v = callRho(S, K, r, v, T);

	double put = putPrice(S, K, r, v, T);
	double put_delta_v = putDelta(S, K, r, v, T);
	double put_gamma_v = putGamma(S, K, r, v, T);
	double put_vega_v = putVega(S, K, r, v, T);
	double put_theta_v = putTheta(S, K, r, v, T);
	double put_rho_v = putRho(S, K, r, v, T);

	// Output Greek parameters and Option price
	std::cout << "Underlying:      " << S << std::endl;
	std::cout << "Strike:          " << K << std::endl;
	std::cout << "Risk-Free Rate:  " << r << std::endl;
	std::cout << "Volatility:      " << v << std::endl;
	std::cout << "Expiration:      " << T << std::endl << std::endl;

	std::cout << "Call Price:      " << call << std::endl;
	std::cout << "Call Delta:      " << call_delta_v << std::endl;
	std::cout << "Call Gamma:      " << call_gamma_v << std::endl;
	std::cout << "Call Vega:       " << call_vega_v << std::endl;
	std::cout << "Call Theta:      " << call_theta_v << std::endl;
	std::cout << "Call Rho:        " << call_rho_v << std::endl << std::endl;

	std::cout << "Put Price:       " << put << std::endl;
	std::cout << "Put Delta:       " << put_delta_v << std::endl;
	std::cout << "Put Gamma:       " << put_gamma_v << std::endl;
	std::cout << "Put Vega:        " << put_vega_v << std::endl;
	std::cout << "Put Theta:       " << put_theta_v << std::endl;
	std::cout << "Put Rho:         " << put_rho_v << std::endl;

	return 0;
}
