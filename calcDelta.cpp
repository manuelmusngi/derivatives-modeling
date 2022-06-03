/*
calcDelta                :Delta calculation of an Option

[in>>]   double price    :underlying price
         double strike   :strike price
         double rate     :interest rate
         double div      :dividend yield
         double T        :time to maturity or days until expiration
         char type       :Call Option 'C' or Put Option 'P'
[out<<]  double          :Delta
*/
#include <cmath>
#include <string>

double calcDelta(double price,
                 double strike,
                 double rate,
                 double div,
                 double vol,
                 double T,
                 char type)
{
    double d1, delta;
    
    d1 = (log(price) + (rate - div + (vol*vol/2))*T) / (vol*sqrt(T));
    
    if (type == 'C')
        delta = exp(-div*T)*util.normalCalcPrime(d1);
    else
        delta = exp(-div*T)*(util.normalCalc(d1) - 1);
    
    return delta;
}
