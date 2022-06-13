#ifndef __BLACK_SCHOLES_H
#define __BLACK_SCHOLES_H

#include <iostream>
#include <cmath>

using namespace std;

class BlackScholesCall 
{
	public:
		BlackScholesCall(double _S, double _K,
				 double _r, double _T);

		double option_price(double sigma) const;
		double option_vega(double sigma) const;
	
	private:
		double S; 		// Underlying asset price
		double K;		// Strike price
		double r;		// Risk-free rate
		double T; 		// Time to maturity

};
#endif 
