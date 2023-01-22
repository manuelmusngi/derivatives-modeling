#ifndef EWMAMODEL_H
#define EWMAMODEL_H

#include <vector>
#include <utility>
#include <cmath>
#include <numeric>

using namespace std;

class EWMAModel
{
	protected:
		vector<double> returns;
		vector<double> S; // price of instrument
		int T;
		int i;

	public:
		int EWMA() {};
		virtual ~EWMAModel() {};
		vector<double> EWMA(double // computes exponential moving average
			lambda, vector<double>& prices);
};

#endif
