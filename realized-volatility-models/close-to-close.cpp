// close_to_close_volatility_model

#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

double calculateStandardDeviation(const vector<double> &prices) 
{
    double sum = 0.0, mean, variance = 0.0, stdDev;

    if (prices.empty()) {
        return 0.0;
    }

    // Calculate Mean
    for (const auto &price : prices) 
    {
        sum += price;
    }
    mean = sum / prices.size();

    // Calculate Variance
    for (const auto &price : prices) 
    {
        variance += pow(price - mean, 2);
    }
    variance /= prices.size();

    // Calculate Standard Deviation
    stdDev = sqrt(variance);

    return stdDev;
}

double calculateCloseToCloseVolatility(const vector<double> &prices) 
{
    if (prices.size() <= 1) {
        return 0.0;
    }

    double stdDev = calculateStandardDeviation(prices);

    // Calculate the close-to-close volatility
    double closeToCloseVolatility = stdDev * sqrt(static_cast<double>(prices.size()) / (prices.size() - 1));

    return closeToCloseVolatility;
}

int main() 
{
    vector<double> prices = { 10.5, 11.2, 12.8, 10.9, 9.5 };
    double closeToCloseVolatility = calculateCloseToCloseVolatility(prices);

    // Print the result
    cout << "The close-to-close volatility is: " << closeToCloseVolatility << endl;

    return 0;
}
