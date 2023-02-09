/*
	Calculation of Options Sensitivities
*/
#include <iostream>
#include <cmath>
#include "greeks.h"
#include "greeks.cpp"

using namespace std;

int main(int argc, char** argv) 
{
	// Parameter list example
	auto S = 100.0;  // Instrument price
	auto K = 100.0;  // Strike price
	auto r = 0.05;   // Risk-free rate (example 5%)
	auto v = 0.2;    // Volatility of the underlying (example 20%)
	auto T = 1.0;    // One year until expiration

	// Calculate the Call/Put values and Options Greeks
	auto call = callPrice(S, K, r, v, T);
	auto call_delta_v = callDelta(S, K, r, v, T);
	auto call_gamma_v = callGamma(S, K, r, v, T);
	auto call_vega_v = callVega(S, K, r, v, T);
	auto call_theta_v = callTheta(S, K, r, v, T);
	auto call_rho_v = callRho(S, K, r, v, T);

	auto put = putPrice(S, K, r, v, T);
	auto put_delta_v = putDelta(S, K, r, v, T);
	auto put_gamma_v = putGamma(S, K, r, v, T);
	auto put_vega_v = putVega(S, K, r, v, T);
	auto put_theta_v = putTheta(S, K, r, v, T);
	auto put_rho_v = putRho(S, K, r, v, T);

	// Output Greek parameters and Option price
	cout << "Underlying:      " << S << endl;
	cout << "Strike:          " << K << endl;
	cout << "Risk-Free Rate:  " << r << endl;
	cout << "Volatility:      " << v << endl;
	cout << "Expiration:      " << T << endl << endl;

	cout << "Call Price:      " << call << endl;
	cout << "Call Delta:      " << call_delta_v << endl;
	cout << "Call Gamma:      " << call_gamma_v << endl;
	cout << "Call Vega:       " << call_vega_v << endl;
	cout << "Call Theta:      " << call_theta_v << endl;
	cout << "Call Rho:        " << call_rho_v << endl << endl;

	cout << "Put Price:       " << put << endl;
	cout << "Put Delta:       " << put_delta_v << endl;
	cout << "Put Gamma:       " << put_gamma_v << endl;
	cout << "Put Vega:        " << put_vega_v << endl;
	cout << "Put Theta:       " << put_theta_v << endl;
	cout << "Put Rho:         " << put_rho_v << endl;

	return 0;
}
