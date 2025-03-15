// Rogers-Satchell Volatility Model

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

double calculateRogersSatchellVolatility(const vector<double>& high, const vector<double>& low) 
{
    if (high.size() != low.size() || high.size() < 2) 
    {
        throw invalid_argument("Input arrays must have the same length and contain at least two elements.");
    }

    double sum = 0.0;
    size_t numPrices = high.size();

    // Calculate the sum of the logarithmic returns
    for (size_t i = 0; i < numPrices - 1; ++i) 
    {
        if (high[i + 1] <= 0 || low[i] <= 0) 
        {
            throw invalid_argument("All values must be positive for logarithmic calculations.");
        }
        sum += log(high[i + 1] / low[i]);
    }

    // Calculate the Rogers-Satchell volatility 
    double rogersSatchellVolatility = sqrt((1.0 / (numPrices - 1)) * sum * sum - (1.0 / (numPrices * (numPrices - 1))) * sum * sum);

    return rogersSatchellVolatility;
}

int main() 
{
    vector<double> high = { 11.8, 12.4, 13.2, 11.4, 10.0 };
    vector<double> low = { 10.2, 10.8, 11.6, 9.8, 8.4 };

    try 
    {
        // Calculate the Rogers-Satchell volatility 
        double rogersSatchellVolatility = calculateRogersSatchellVolatility(high, low);

        // Print the result
        cout << "The Rogers-Satchell volatility is: " << rogersSatchellVolatility << endl;
    } 
    catch (const invalid_argument& e) 
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
