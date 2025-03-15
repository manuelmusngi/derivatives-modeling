#include "OptionsImpliedVolatilitySurface.hpp"
#include <stdexcept>
#include <algorithm>
#include <map>

// Constructor for OptionsImpliedVolatilitySurface
OptionsImpliedVolatilitySurface::OptionsImpliedVolatilitySurface(
    const std::vector<double>& strikes,
    const std::vector<double>& expirations,
    const std::vector<std::vector<double>>& volatilities) 
    : k_strikes(strikes),
      k_expirations(expirations),
      k_volatilities(volatilities) 
{
    if (k_strikes.empty() || k_expirations.empty() || k_volatilities.empty()) {
        throw std::invalid_argument("Input vectors must not be empty");
    }
    if (k_volatilities.size() != k_expirations.size()) {
        throw std::invalid_argument("Volatilities matrix row size must match the number of expirations");
    }
    for (const auto& row : k_volatilities) {
        if (row.size() != k_strikes.size()) {
            throw std::invalid_argument("Each row in volatilities matrix must match the number of strikes");
        }
    }
}

// Function to get the volatility for a given strike and expiration
double OptionsImpliedVolatilitySurface::GetVolatility(double strike, double expiration) const 
{
    // Find the index of the strike and expiration
    auto strike_it = std::find(k_strikes.begin(), k_strikes.end(), strike);
    auto exp_it = std::find(k_expirations.begin(), k_expirations.end(), expiration);

    // Check if the strike or expiration is out of range
    if (strike_it == k_strikes.end() || exp_it == k_expirations.end()) {
        throw std::out_of_range("Invalid strike or expiration");
    }

    size_t strike_idx = std::distance(k_strikes.begin(), strike_it);
    size_t exp_idx = std::distance(k_expirations.begin(), exp_it);

    return k_volatilities[exp_idx][strike_idx];
}
