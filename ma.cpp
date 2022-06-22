/*
	Moving Average modeling for volatility and asset returns
*/
#include <iostream>
#include "StatModel.h"

using namespace std;

vector<double> StatModel::MA(int lag, vector<double>& S)
{
	vector<double>	returns;				// vector of asset returns
	vector<double>	vols;			// vector of volatilities
	vector<double>::iterator iter;		// vector iterator

	double ret = 0.0;			// continuous compound return at time i
	double sum = 0.0;			// total returns added up
	double var = 0.0;			// sum of squared errors
	double ave = 0.0;			// average return
	// double S;				// asset price

	int N = S.size();			// cache sizes of time series
	int A = 252;				// 252 trading days per year
	int i, j;								


	for (i = 0; i < N - 1; i++)
	{
	// calculate compounded return
	ret = log(S[i + 1] / S[i]);
		returns.push_back(ret);
		sum = sum + ret;
	}

	// calculate mean average return
	ave = sum / N;
	
	for (i = 0; i < returns.size() - lag; i++)
	{
		var = 0.0;
		for (j = 0; j < lag; j++) 
		{	
			var += (returns[lag + i - j - 1] - ave) * (returns[lag + i - j - 1] - ave);
		}
		vols.push_back(100 * sqrt(var / ((lag - 1) * (A))));
	}
	i = 0;
	// print of MA volatilites
	for (iter=vols.begin(); iter != vols.end() ; iter++) 
	{
		cout << *iter << endl;
	}
	return returns;
}
