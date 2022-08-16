/*
	BSCallPrice : calculates Black Scholes call price 
*/
#include <iostream>
#include <cmath>
#include "normalCalc.h"



double vol;     //volatility
double rate;    // interest rate
double strike;  // strike price
double price;   // instrument price
double T;       // time to maturity or expirations
double proba1;
double proba2;
double d1;
double d2;
double callprice;

double BSCallPrice(double vol, double rate, double strike, double price, double T)
{
	proba1 = normalCalc(d1);
	proba2 = normalCalc(d2);
	d1 = (log(price / strike) + (rate + (vol) * (vol) / 2) * T) / (vol * sqrt(T));
	d2 = d1 -  (vol * sqrt(T));
	callprice = price * exp(T) * proba1 - strike * exp(-rate * T) * proba2;
	return callprice;
};
