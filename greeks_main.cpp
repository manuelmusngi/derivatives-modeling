/*
	Calculation of Options Sensitivities
*/
#include <iostream>
#include <cmath>
#include "greeks.h"

using namespace std;

int main(int argc, char** argv) 
{
	// Parameter list as for example
	double S = 100.0;  // Instrument price
	double K = 100.0;  // Strike price
	double r = 0.05;   // Risk-free rate (example 5%)
	double v = 0.2;    // Volatility of the underlying (example 20%)
	double T = 1.0;    // One year until expiration

	// Calculate the Call/Put values and Options Greeks
	double call = call_price(S, K, r, v, T);
	double call_delta_v = call_delta(S, K, r, v, T);
	double call_gamma_v = call_gamma(S, K, r, v, T);
	double call_vega_v = call_vega(S, K, r, v, T);
	double call_theta_v = call_theta(S, K, r, v, T);
	double call_rho_v = call_rho(S, K, r, v, T);

	double put = put_price(S, K, r, v, T);
	double put_delta_v = put_delta(S, K, r, v, T);
	double put_gamma_v = put_gamma(S, K, r, v, T);
	double put_vega_v = put_vega(S, K, r, v, T);
	double put_theta_v = put_theta(S, K, r, v, T);
	double put_rho_v = put_rho(S, K, r, v, T);

	// Output Greek parameters and Option price
	cout << "Underlying:      " << S << endl;
	cout << "Strike:          " << K << endl;
	cout << "Risk-Free Rate:  " << r << endl;
	cout << "Volatility:      " << v << endl;
	cout << "Expiration:        " << T << endl << endl;

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
