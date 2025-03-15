#pragma once

#include <vector>
#include <stdexcept>

/**
 * @class OptionsImpliedVolatilitySurface
 * @brief Represents a surface of implied volatilities for options.
 */
class OptionsImpliedVolatilitySurface 
{
public:
    /**
     * @brief Constructs the implied volatility surface.
     * @param strikes A vector of strike prices.
     * @param expirations A vector of expiration times.
     * @param volatilities A matrix of volatilities corresponding to the strikes and expirations.
     */
    OptionsImpliedVolatilitySurface(const std::vector<double>& strikes,
                                    const std::vector<double>& expirations,
                                    const std::vector<std::vector<double>>& volatilities)
        : k_strikes(strikes), k_expirations(expirations), k_volatilities(volatilities)
    {
    }

    /**
     * @brief Gets the implied volatility for a given strike price and expiration time.
     * @param strike The strike price.
     * @param expiration The expiration time.
     * @return The implied volatility.
     * @throws std::out_of_range if the strike or expiration is not found.
     */
    double GetVolatility(double strike, double expiration) const
    {
        auto strikeIt = std::find(k_strikes.begin(), k_strikes.end(), strike);
        auto expIt = std::find(k_expirations.begin(), k_expirations.end(), expiration);

        if (strikeIt == k_strikes.end() || expIt == k_expirations.end())
        {
            throw std::out_of_range("Strike price or expiration not found.");
        }

        size_t strikeIndex = std::distance(k_strikes.begin(), strikeIt);
        size_t expIndex = std::distance(k_expirations.begin(), expIt);

        return k_volatilities[strikeIndex][expIndex];
    }

private:
    std::vector<double> k_strikes;
    std::vector<double> k_expirations;
    std::vector<std::vector<double>> k_volatilities;
};
