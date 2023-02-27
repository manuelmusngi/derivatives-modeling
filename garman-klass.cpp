// garman-klass_volatility_model

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double calculateGarmanKlassVolatility(double high[], double low[], double open[], double close[], int numPrices) 
{
    double sum = 0.0, logSum = 0.0, garmanKlassVolatility;
    int i;

    // Calculate the sum and log sum of the differences between high and low prices
    for (i = 0; i < numPrices; ++i) 
    {
        sum += pow(high[i] - low[i], 2);
        logSum += log(close[i] / open[i]) * log(close[i] / open[i]);
    }

    // Calculate the Garman-Klass volatility estimator
    garmanKlassVolatility = sqrt((1.0 / numPrices) * sum - (1.0 / (2.0 * numPrices * numPrices)) * logSum);

    return garmanKlassVolatility;
}

int main() 
{
    double high[] = { 11.8, 12.4, 13.2, 11.4, 10.0 };
    double low[] = { 10.2, 10.8, 11.6, 9.8, 8.4 };
    double open[] = { 10.5, 11.2, 12.0, 10.5, 9.8 };
    double close[] = { 11.5, 12.0, 12.8, 10.9, 9.5 };
    int numPrices = 5;
    double garmanKlassVolatility;

    // Calculate the Garman-Klass volatility estimator
    garmanKlassVolatility = calculateGarmanKlassVolatility(high, low, open, close, numPrices);

    // Print the result
    cout << "The Garman-Klass volatility estimator is: " << garmanKlassVolatility << endl;

    return 0;
}
