// Rogers-Satchell Volatility Model

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double calculateRogersSatchellVolatility(double high[], double low[], int numPrices) 
{
    double sum = 0.0, rogersSatchellVolatility;
    int i;

    // Calculate the sum of the logarithmic returns
    for (i = 0; i < numPrices - 1; ++i) 
    {
        sum += log(high[i + 1] / low[i]);
    }

    // Calculate the Rogers-Satchell volatility 
    rogersSatchellVolatility = sqrt((1.0 / (numPrices - 1)) * sum * sum - (1.0 / (numPrices * (numPrices - 1))) * sum * sum);

    return rogersSatchellVolatility;
}

int main() 
{
    double high[] = { 11.8, 12.4, 13.2, 11.4, 10.0 };
    double low[] = { 10.2, 10.8, 11.6, 9.8, 8.4 };
    int numPrices = 5;
    double rogersSatchellVolatility;

    // Calculate the Rogers-Satchell volatility 
    rogersSatchellVolatility = calculateRogersSatchellVolatility(high, low, numPrices);

    // Print the result
    cout << "The Rogers-Satchell volatility is: " << rogersSatchellVolatility << endl;

    return 0;
}
