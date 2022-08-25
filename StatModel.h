#ifndef MOVING_AVERAGE_MODEL_H
#define MOVING_AVERAGE_MODEL_H

#include <vector>
#include <utility>
#include <cmath>
#include <numeric>

using namespace std;

class MovingAverageModel
{
	protected:
		vector<double> returns;
		vector<double> S; // price of instrument
		int T;
		int i;

	public:
		MovingAverageModel() {}
		virtual ~MovingAverageModel() {};
		vector<double> MA(int lag, vector<double>& S);
		vector<double> MA(int lag);		
};

#endif

