#include "OptionsImpliedVolatilitySurface.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    // Example usage
    std::vector<double> strikes{100, 110, 120};
    std::vector<double> expirations{0.25, 0.5, 1.0};
    std::vector<std::vector<double>> volatilities{{0.2, 0.18, 0.16}, {0.18, 0.16, 0.14}, {0.16, 0.14, 0.12}};

    OptionsImpliedVolatilitySurface surface(strikes, expirations, volatilities);
    std::cout << "Volatility at (110, 0.5): " << surface.GetVolatility(110, 0.5) << std::endl;

    return 0;
}
