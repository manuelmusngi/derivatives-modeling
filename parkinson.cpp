// parkinson volatility model

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double calculateParkinsonVolatility(double highs[], double lows[], int numPrices) 
{
    double sum = 0.0, parkinsonVolatility;
    int i;

    // Calculate the Parkinson volatility 
    for (i = 0; i < numPrices; ++i) {
        sum += log(highs[i] / lows[i]);
    }
    parkinsonVolatility = sqrt((1.0 / (4.0 * numPrices * log(2.0))) * sum * sum);

    return parkinsonVolatility;
}

int main() 
{
    double highs[] = { 11.5, 12.3, 13.8, 11.9, 10.5 };
    double lows[] = { 9.5, 10.3, 11.8, 9.9, 8.5 };
    int numPrices = 5;
    double parkinsonVolatility;

    // Calculate the Parkinson volatility 
    parkinsonVolatility = calculateParkinsonVolatility(highs, lows, numPrices);

    // Print the result
    cout << "The Parkinson volatility is: " << parkinsonVolatility << endl;

    return 0;
}
