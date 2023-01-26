/*
	normalCalc: Computes cumulative normal distribution probabilities
*/
#ifndef NORMALCALC_H
#define NORMALCALC_H

#define _USE_MATH_DEFINES

#include <cmath>


double normalCalc(double d)
{
	const double a1 = 0.319381530;
	const double a2 = -0.356563782;
	const double a3 = 1.781477937;
	const double a4 = -1.821255978;
	const double a5 = 1.330274429;
	const double gamma = 0.2316419;
	const double PI = 3.14159;
	const double k1 = 1 / (1 + gamma * d);
	const double k2 = 1 / (1 - gamma * d);
	const double normalprime = (1 / (sqrt(2 * PI))) * exp(-d * d / 2);
	double value = 0.0;
	double h = 0.0;
	if (d >= 0)
		value = 1 - normalprime * (a1 * k1 + a2 * pow(k1, 2) + a3 * pow(k1, 3) + a4 * pow(k1, 4) +
			a5 * pow(k1, 5));
	else
		value = normalprime * (a1 * k2 + a2 * pow(k2, 2) + a3 * pow(k2, 3) + a4 * pow(k2, 4) +
			a5 * pow(k2, 5));
	return value;
};
	
#endif
