#ifndef __BLACK_SCHOLES_H
#define __BLACK_SCHOLES_H

class BlackScholesCall 
{
    private:
        double S; 		// Underlying asset price
        double K;		// Strike price
        double r;		// Risk-free rate
        double T; 		// Time to maturity

    public:
        BlackScholesCall(double _S, double _K, double _r, double _T);

        double optionPrice(double sigma) const;
        double optionVega(double sigma) const;
};
#endif 

