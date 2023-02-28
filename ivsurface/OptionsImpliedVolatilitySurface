#include "OptionsImpliedVolatilitySurface.hpp"
#include <stdexcept>
#include <algorithm>

OptionsImpliedVolatilitySurface::OptionsImpliedVolatilitySurface(
    const std::vector<double>& strikes,
    const std::vector<double>& expirations,
    const std::vector<std::vector<double>>& volatilities) : k_strikes(strikes),
                                                            k_expirations(expirations),
                                                            k_volatilities(volatilities) {}

double OptionsImpliedVolatilitySurface::GetVolatility(double strike, double expiration) const 
{
    // Find the index of the strike and expiration
    auto strike_it = std::find(k_strikes.begin(), k_strikes.end(), strike);
    auto exp_it = std::find(k_expirations.begin(), k_expirations.end(), expiration);

    if (strike_it == k_strikes.end() || exp_it == k_expirations.end()) 
    {
        throw std::out_of_range("Invalid strike or expiration");
    }

    size_t strike_idx = strike_it - k_strikes.begin();
    size_t exp_idx = exp_it - k_expirations.begin();
    
    return k_volatilities[exp_idx][strike_idx];
}


