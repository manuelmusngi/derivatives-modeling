#ifndef OPTIONS_IMPLIED_VOLATILITY_SURFACE_HPP
#define OPTIONS_IMPLIED_VOLATILITY_SURFACE_HPP

#include <vector>

class OptionsImpliedVolatilitySurface 
{
    public:
        OptionsImpliedVolatilitySurface(const std::vector<double>& strikes,
                                        const std::vector<double>& expirations,
                                        const std::vector<std::vector<double>>& volatilities);

        double GetVolatility(double strike, double expiration) const;

    private:
        std::vector<double> k_strikes;
        std::vector<double> k_expirations;
        std::vector<std::vector<double>> k_volatilities;
};

#endif 
