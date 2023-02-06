/*
	normalCalc: Computes cumulative normal distribution probabilities
*/
#ifndef NORMALCALC_H
#define NORMALCALC_H

#define _USE_MATH_DEFINES

#include <cmath>


double normalCalc(double d)
{
	const auto a1 = 0.319381530;
	const auto a2 = -0.356563782;
	const auto a3 = 1.781477937;
	const auto a4 = -1.821255978;
	const auto a5 = 1.330274429;
	const auto gamma = 0.2316419;
	const auto PI = 3.14159;
	const auto k1 = 1 / (1 + gamma * d);
	const auto k2 = 1 / (1 - gamma * d);
	const auto normalprime = (1 / (sqrt(2 * PI))) * exp(-d * d / 2);
	auto value = 0.0;
	auto h = 0.0;
	
	if (d >= 0)
		value = 1 - normalprime * (a1 * k1 + a2 * pow(k1, 2) + a3 * pow(k1, 3) + a4 * pow(k1, 4) +
			a5 * pow(k1, 5));
	else
		value = normalprime * (a1 * k2 + a2 * pow(k2, 2) + a3 * pow(k2, 3) + a4 * pow(k2, 4) +
			a5 * pow(k2, 5));
	return value;
};
	
#endif
