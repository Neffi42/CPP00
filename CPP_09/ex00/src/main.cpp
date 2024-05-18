#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>\n";
        return 2;
    }
    try {
        BitcoinExchange btc;
        btc.processInput(argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
