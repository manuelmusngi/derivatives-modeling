/**********************************************************************************/
#ifndef CALCULATEVEGA_H
#define CALCULATEVEGA_H

#include "normalCalc.h"

using namespace std;

double calculateVega(double price,double strike, double rate, double vol, double T)
{
	double d1 = (log(price/strike) + (rate + (vol)*(vol)/2)*T)/(vol*sqrt(T));
	return price*sqrt(T)*normalCalc(d1);
}

#endif