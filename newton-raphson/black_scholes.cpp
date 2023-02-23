#ifndef __BLACK_SCHOLES_CPP
#define __BLACK_SCHOLES_CPP

#include "black_scholes.h"
#include "bs_prices.h"

BlackScholesCall::BlackScholesCall(double _S, double _K, 
								   double _r, double _T) :
	S(_S), K(_K), r(_r), T(_T) {}

double BlackScholesCall::optionPrice(double sigma) const 
{
	return callPrice(S, K, r, sigma, T);
}

double BlackScholesCall::optionVega(double sigma) const 
{
  return callVega(S, K, r, sigma, T);
}

#endif
