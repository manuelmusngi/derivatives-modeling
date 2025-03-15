#ifndef __MAIN_CPP
#define __MAIN_CPP

#include "black_scholes.h"
#include "newton_raphson.h"
#include <iostream>
#include <stdexcept>
#include <string>

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
}

int main(int argc, char **argv) 
{
    try {
        // Parameters
        double S, K, r, T, C_M;

        // Parse command-line arguments
        parseArguments(argc, argv, S, K, r, T, C_M);

        // Create the Black-Scholes Call functor
        BlackScholesCall bsc(S, K, r, T);

        // Newton Raphson parameters
        double init = 0.3;  // Our guess impl. vol of 30%
        double epsilon = 0.001;

        // Calculate the implied volatility
        double sigma = newton_raphson<BlackScholesCall, &BlackScholesCall::optionPrice, 
                                      &BlackScholesCall::optionVega>(C_M, init, epsilon, bsc);

        // Output the values
        std::cout << "Implied Vol: " << sigma << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#endif
