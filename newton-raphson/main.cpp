#include "black_scholes.h"
#include "newton_raphson.h"
#include <iostream>
#include <stdexcept>
#include <string>

const double INITIAL_GUESS = 0.3; // Initial guess for implied volatility
const double EPSILON = 0.001;     // Convergence criterion

// Function to parse command-line arguments
void parseArguments(int argc, char **argv, double &S, double &K, double &r, double &T, double &C_M) {
    if (argc != 6) {
        throw std::invalid_argument("Usage: <program> <S> <K> <r> <T> <C_M>");
    }
    S = std::stod(argv[1]);
    K = std::stod(argv[2]);
    r = std::stod(argv[3]);
    T = std::stod(argv[4]);
    C_M = std::stod(argv[5]);

    if (S <= 0 || K <= 0 || r < 0 || T <= 0 || C_M <= 0) {
        throw std::invalid_argument("All input values must be positive.");
    }
}

// Function to calculate implied volatility
double calculateImpliedVolatility(double S, double K, double r, double T, double C_M) {
    BlackScholesCall bsc(S, K, r, T);
    return newton_raphson<BlackScholesCall, &BlackScholesCall::optionPrice, 
                          &BlackScholesCall::optionVega>(C_M, INITIAL_GUESS, EPSILON, bsc);
}

int main(int argc, char **argv) {
    try {
        double S, K, r, T, C_M;

        // Parse command-line arguments
        parseArguments(argc, argv, S, K, r, T, C_M);

        // Calculate the implied volatility
        double sigma = calculateImpliedVolatility(S, K, r, T, C_M);

        // Output the values
        std::cout << "Implied Vol: " << sigma << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Argument Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
