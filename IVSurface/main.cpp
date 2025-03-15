#include "OptionsImpliedVolatilitySurface.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept> // For exception handling

int main() 
{
    // Example usage
    std::vector<double> strikes{100, 110, 120};
    std::vector<double> expirations{0.25, 0.5, 1.0};
    std::vector<std::vector<double>> volatilities{{0.2, 0.18, 0.16}, {0.18, 0.16, 0.14}, {0.16, 0.14, 0.12}};

    try {
        OptionsImpliedVolatilitySurface surface(strikes, expirations, volatilities);
        std::cout << "Volatility at (110, 0.5): " << surface.GetVolatility(110, 0.5) << std::endl;

        // Additional example usage
        std::cout << "Volatility at (100, 0.25): " << surface.GetVolatility(100, 0.25) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Return non-zero value to indicate error
    }

    return 0;
}
