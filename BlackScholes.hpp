//
//  BlackScholes.hpp

#ifndef BlackScholes_hpp
#define BlackScholes_hpp

#include <vector>

class BlackScholesMethod {
public:
    BlackScholesMethod(double expiration, double maxPrice, double strike, double intRate);
    BlackScholesMethod(const BlackScholesMethod &p);
    ~BlackScholesMethod();
    BlackScholesMethod &operator=(const BlackScholesMethod &p);

    std::vector<double> solve(double volatility, int nx, int timeSteps);
private:
    double b_expiration;
    double b_maxPrice;
    double b_strike;
    double b_intRate;
};
#endif /* BlackScholes_hpp */
