/*
	Calculation of Options Sensitivities
*/
#include <iostream>
#include <cmath>
#include "greeks.h"

// Function to print option details
void printOptionDetails(double S, double K, double r, double v, double T) {
	std::cout << "Underlying:      " << S << std::endl;
	std::cout << "Strike:          " << K << std::endl;
	std::cout << "Risk-Free Rate:  " << r << std::endl;
	std::cout << "Volatility:      " << v << std::endl;
	std::cout << "Expiration:      " << T << std::endl << std::endl;
}

void printCallDetails(double call, double delta, double gamma, double vega, double theta, double rho) {
	std::cout << "Call Price:      " << call << std::endl;
	std::cout << "Call Delta:      " << delta << std::endl;
	std::cout << "Call Gamma:      " << gamma << std::endl;
	std::cout << "Call Vega:       " << vega << std::endl;
	std::cout << "Call Theta:      " << theta << std::endl;
	std::cout << "Call Rho:        " << rho << std::endl << std::endl;
}

void printPutDetails(double put, double delta, double gamma, double vega, double theta, double rho) {
	std::cout << "Put Price:       " << put << std::endl;
	std::cout << "Put Delta:       " << delta << std::endl;
	std::cout << "Put Gamma:       " << gamma << std::endl;
	std::cout << "Put Vega:        " << vega << std::endl;
	std::cout << "Put Theta:       " << theta << std::endl;
	std::cout << "Put Rho:         " << rho << std::endl;
}

int main(int argc, char** argv) {
	// Parameter list example
	double S = 100.0;  // Instrument price
	double K = 100.0;  // Strike price
	double r = 0.05;   // Risk-free rate (example 5%)
	double v = 0.2;    // Volatility of the underlying (example 20%)
	double T = 1.0;    // One year until expiration

	try {
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
		printOptionDetails(S, K, r, v, T);
		printCallDetails(call, call_delta_v, call_gamma_v, call_vega_v, call_theta_v, call_rho_v);
		printPutDetails(put, put_delta_v, put_gamma_v, put_vega_v, put_theta_v, put_rho_v);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
