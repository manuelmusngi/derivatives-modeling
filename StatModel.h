#ifndef STATMODEL_H
#define STATMODEL_H

#include <vector>
#include <utility>
#include <cmath>
#include <numeric>

using namespace std;

class StatModel
{
	protected:
		vector<double> returns;
		int T;

	public:
		StatModel() {}
		virtual ~StatModel() {};
		vector<double> MA(int lag, vector<double>& S);
		vector<double> MA(int lag);
};

#endif

