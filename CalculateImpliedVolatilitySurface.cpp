/*
	CalculateImpliedVolatilitySurface: Computes the volatility surface of an option chain
	Modified model versions and referenced: Modeling Derivatives in C++ by Justin London
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <ios>
#include <map>
#include "calculateVega.h"
#include "normalCalc.h"
#include "BSCallPrice.h"
#include "BSPutPrice.h"

using namespace std;

map<pair<double, int>, double> calculateImpliedVolatilitySurface(double price,
								 vector<double> optionPrices, 
								 vector<int> strikes, 
								 vector<double> maturities,
								 map<double, double> rates)
{
	map<pair<double, int>, double> surfaceMap;		// map strike and maturity to implied volatility
	pair<double, int> TXPair; 				// time (expiration)  - strike pair
	vector<pair<double, int> > vecPair; 			// vector of TXPairs
	vector<pair<double, int> >::iterator vecPairIter; 	// vector map iterator
	vector<double>::iterator priceIter; 			// vector price iterator
	int j = 0;
	int cnt = 0;
	const double epsilon = 0.000001; 			// error tolerance
	double error = 0.0; 					// error between market and model prices
	double vol1 = 0.0; 					// implied volatility
	double vol2 = 0.0; 					// temporary volatility
	double vega = 0.0; 					// option vega
	double BSPrice = 0.0; 					// black scholes pricing
	double marketPrice = 0.0; 				// market price of instrument
	int* strike = new int[strikes.size()]; 			// array of strikes
	double* maturity = new double[maturities.size()]; 	// array of maturities or expiration
	double* call = new double[optionPrices.size()]; 	// array of call prices
	
	cout.setf(ios::showpoint);
	cout.precision(3);

	copy(strikes.begin(), strikes.end(), strike);
	copy(optionPrices.begin(), optionPrices.end(), call);
	copy(maturities.begin(), maturities.end(), maturity);


	if (type == "C")   // "C" for Call
	{
		for (priceIter = optionPrices.begin(); priceIter != optionPrices.end(); priceIter++)
		{
			marketPrice = *priceIter;
			vol1 = 0.65; // initial assumed volatility for Newton-Raphson
			do
			{
				BSPrice = BSCallPrice(vol1, rates[maturity[cnt]], strike[cnt], price, T);
				vega = calculateVega(price, strike[cnt], rates[maturity[cnt]], vol1, T);
				vol2 = vol1 - (BSPrice - marketPrice) / (vega);
				error = vol2 - vol1;
				vol1 = vol2;
			} while (abs(error) > epsilon);
				TXPair.first = maturity[cnt];
				TXPair.second = strike[cnt];
				vecPair.push_back(TXPair);
				surfaceMap[TXPair] = vol1;
				cnt++;
		}
	}
	else
	{
		for (priceIter = optionPrices.begin(); priceIter != optionPrices.end(); priceIter++)
		{
			marketPrice = *priceIter;
			vol1 = 0.55; 	// initial assumed volatility for Newton-Raphson
			do
			{
			  	BSPrice = BSPutPrice(vol1, rates[maturity[cnt]], strike[cnt], price, T);
				vega = calculateVega(price, strike[cnt], rates[maturity[cnt]], vol1, T);
				vol2 = vol1 - (BSPrice - marketPrice) / (vega);
				error = vol2 - vol1;
				vol1 = vol2;
			} while (abs(error) > epsilon);
				TXPair.first = maturity[cnt];
				TXPair.second = strike[cnt];
				surfaceMap[TXPair] = vol1;
				cnt++;
		}
	}
		// printout of implied volatility surface
		for (vecPairIter = vecPair.begin(); vecPairIter != vecPair.end(); vecPairIter++)
			cout << surfaceMap[*vecPairIter] << endl;

		return surfaceMap;
};

