// garman-klass_volatility_model

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::invalid_argument;

/**
 * @brief Calculate the Garman-Klass volatility.
 * 
 * @param high Vector of high prices.
 * @param low Vector of low prices.
 * @param open Vector of open prices.
 * @param close Vector of close prices.
 * @return double The Garman-Klass volatility.
 */
double calculateGarmanKlassVolatility(const vector<double>& high, const vector<double>& low, const vector<double>& open, const vector<double>& close) 
{
    if (high.size() != low.size() || high.size() != open.size() || high.size() != close.size()) {
        throw invalid_argument("Input vectors must have the same length.");
    }

    int numPrices = high.size();
    double sum = 0.0, logSum = 0.0;

    // Calculate the sum and log sum of the differences between high and low prices
    for (int i = 0; i < numPrices; ++i) 
    {
        sum += std::pow(high[i] - low[i], 2);
        double logReturn = std::log(close[i] / open[i]);
        logSum += logReturn * logReturn;
    }

    // Calculate the Garman-Klass volatility 
    double garmanKlassVolatility = std::sqrt((1.0 / numPrices) * sum - (1.0 / (2.0 * numPrices * numPrices)) * logSum);

    return garmanKlassVolatility;
}

int main() 
{
    vector<double> high = { 11.8, 12.4, 13.2, 11.4, 10.0 };
    vector<double> low = { 10.2, 10.8, 11.6, 9.8, 8.4 };
    vector<double> open = { 10.5, 11.2, 12.0, 10.5, 9.8 };
    vector<double> close = { 11.5, 12.0, 12.8, 10.9, 9.5 };

    try {
        // Calculate the Garman-Klass volatility
        double garmanKlassVolatility = calculateGarmanKlassVolatility(high, low, open, close);

        // Print the result
        cout << "The Garman-Klass volatility is: " << garmanKlassVolatility << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
