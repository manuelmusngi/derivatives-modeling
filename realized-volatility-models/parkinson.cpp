// parkinson volatility model

#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::log;
using std::sqrt;
using std::invalid_argument;

// Function to calculate Parkinson volatility
double calculateParkinsonVolatility(const vector<double>& highs, const vector<double>& lows) 
{
    if (highs.size() != lows.size() || highs.empty()) {
        throw invalid_argument("Highs and lows must have the same non-zero size.");
    }

    double sum = 0.0;
    int numPrices = highs.size();

    // Calculate the Parkinson volatility 
    for (int i = 0; i < numPrices; ++i) {
        sum += log(highs[i] / lows[i]);
    }
    double parkinsonVolatility = sqrt((1.0 / (4.0 * numPrices * log(2.0))) * sum * sum);

    return parkinsonVolatility;
}

int main() 
{
    vector<double> highs = { 11.5, 12.3, 13.8, 11.9, 10.5 };
    vector<double> lows = { 9.5, 10.3, 11.8, 9.9, 8.5 };

    try {
        // Calculate the Parkinson volatility 
        double parkinsonVolatility = calculateParkinsonVolatility(highs, lows);

        // Print the result
        cout << "The Parkinson volatility is: " << parkinsonVolatility << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
