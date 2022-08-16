/*
    BSPutPrice : calculates Black Scholes put price
*/

#include <iostream>
#include <cmath>
#include "normalCalc.h"

using namespace std;

double BSPutPrice(double vol, double rate, double strike, double price, double T)
{
    double proba1;
    double proba2;
    double putprice;
    double d1;
    double d2;
    
    d1 = (log(price/strike) + (rate + (vol)*(vol)/2)*T)/(vol*sqrt(T));
    d2 = d1 - vol*sqrt(T);
    proba1 = normalCalc(-d1);
    proba2 = normalCalc(-d2);
    putprice = strike*exp(-rate*T) * proba2 - price * exp(T) * proba1;
    
    return putprice;
}
