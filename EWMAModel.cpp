/*
	Exponentially Weighted Moving Average of volatility of asset returns
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "EWMAModel.h"

using namespace std;

vector<double> EWMAModel::EWMAModel(double lambda, vector<double>& S)
{
	vector<double> returns;			// vector returns
	vector<double> vols;			// vector of volatilities
	vector<double> ::iterator iter;		// vector of iterator

	double ret = 0.0;					
	double sum = 0.0; 					
	double var = 0.0;					
	double ave = 0.0;
	int N = S.size();
	int i, j;
	const int lag = 100;
	const int A = 252;

	for (i = 0; i < N-1; i++) 
	{
		// calculate compound return
		ret = log(S[i + 1]/S[i]);
		returns.push_back(ret);
		sum = sum + ret;
	}
	// calculate mean average return
	ave = sum/N;

	for (i = 0; i < returns.size() - lag; i++) 
	{
		var = 0.0;
		for (j = 1; j < lag; j++) 
		{
			var +=(lambda, j - 1)*(returns[lag + i - j -1] - ave) * (returns[lag + i - j - 1]) - ave;
		}
		var = (1 - lambda) * var;
		// annualize volatility
		vols. push_back(100 * sqrt(var/A));
	}
	// printout of EWMA volatilities
	for (iter = vols.begin(); iter != vols.end(); iter++)
	{
		cout << *iter << endl;
		i++;
	}
	return returns;
};
