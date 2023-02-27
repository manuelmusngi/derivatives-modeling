#include <iostream>
#include <cmath>

using namespace std;

double calculateStandardDeviation(double prices[], int numPrices) 
{
    double sum = 0.0, mean, variance = 0.0, stdDev;
    int i;

    // Calculate Mean
    for (i = 0; i < numPrices; ++i) 
    {
        sum += prices[i];
    }
    mean = sum / numPrices;

    // Calculate Variance
    for (i = 0; i < numPrices; ++i) 
    {
        variance += pow(prices[i] - mean, 2);
    }
    variance /= numPrices;

    // Calculate Standard Deviation
    stdDev = sqrt(variance);

    return stdDev;
}

double calculateCloseToCloseVolatility(double prices[], int numPrices) 
{
    double stdDev, closeToCloseVolatility;
    int i;

    // Calculate the standard deviation of the closing prices
    stdDev = calculateStandardDeviation(prices, numPrices);

    // Calculate the close-to-close volatility
    closeToCloseVolatility = stdDev * sqrt(numPrices / (numPrices - 1));

    return closeToCloseVolatility;
}

int main() 
{
    double prices[] = { 10.5, 11.2, 12.8, 10.9, 9.5 };
    int numPrices = 5;
    double closeToCloseVolatility;

    // Calculate the close-to-close volatility
    closeToCloseVolatility = calculateCloseToCloseVolatility(prices, numPrices);

    // Print the result
    cout << "The close-to-close volatility is: " << closeToCloseVolatility << endl;

    return 0;
}
