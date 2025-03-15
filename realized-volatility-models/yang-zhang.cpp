// yang-zhang volatility model

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using std::vector;
using std::log;
using std::abs;
using std::sqrt;
using std::cout;
using std::endl;
using std::invalid_argument;

/**
 * @brief Computes the Yang-Zhang volatility of a series of prices.
 *
 * @param prices Vector of prices.
 * @param delta Time interval (e.g., 1.0 for daily data).
 * @return The Yang-Zhang volatility.
 * @throws invalid_argument if the input data is invalid.
 */
double yang_zhang_volatility(const vector<double>& prices, double delta) 
{
    int n = prices.size();
    if (n < 2) 
    {
        throw invalid_argument("Prices vector must contain at least two elements.");
    }
    if (delta <= 0) 
    {
        throw invalid_argument("Delta must be positive.");
    }

    double log_return_sum = 0.0;
    double absolute_return_sum = 0.0;
    double beta_sum = 0.0;

    for (int i = 1; i < n; ++i) 
    {
        double log_return = log(prices[i] / prices[i-1]);
        log_return_sum += log_return;
        absolute_return_sum += abs(log_return);
        beta_sum += (i - 1) * log_return * log_return;
    }

    double sigma_sq = (n - 1) * (log_return_sum * log_return_sum - beta_sum) / ((n - 2) * (n - 3) * delta) + 2.0 * absolute_return_sum / ((n - 1) * delta);

    return sqrt(sigma_sq);
}

int main() 
{
    vector<double> prices = {100.0, 110.0, 120.0, 115.0, 125.0, 130.0};
    double delta = 1.0; // assume daily data
    try 
    {
        double volatility = yang_zhang_volatility(prices, delta);
        cout << "Yang-Zhang volatility: " << volatility << endl;
    } 
    catch (const invalid_argument& e) 
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
