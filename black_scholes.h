#ifndef __BLACK_SCHOLES_H
#define __BLACK_SCHOLES_H

class BlackScholesCall {
private:
  double S;  // Underlying asset price
  double K;  // Strike price
  double r;  // Risk-free rate
  double T;  // Time to maturity

public:
  BlackScholesCall(double _S, double _K, 
                   double _r, double _T);

  // This is the modified section. operator()
  // has been replaced with option_price and
  // we have added option_vega (both const)
  double option_price(double sigma) const;
  double option_vega(double sigma) const;
};
#endif