#include <iostream>
#include <string>
#include <stdexcept>

#include "math_utils.hpp"

void print_usage(const char* progName) {
    std::cerr << "Usage:\n"
              << "  " << progName << "                # demo output\n"
              << "  " << progName << " sum0to9        # compute sum 0..9\n"
              << "  " << progName << " sumrange A B   # sum from A to B (inclusive)\n"
              << "  " << progName << " fact N         # factorial of N (N >= 0)\n";
}

int main(int argc, char** argv) {
    // Nessun argomento: demo
    if (argc == 1) {
        std::cout << "Hello from Pi 400 with C++ and Ninja!" << std::endl;

        int sum = compute_sum_0_to_9();
        std::cout << "Sum 0..9 = " << sum << std::endl;

        std::cout << "Sum range 3..7 = " << sum_range(3, 7) << std::endl;
        std::cout << "factorial(5) = " << factorial(5) << std::endl;

        return 0;
    }

    std::string cmd = argv[1];

    try {
        if (cmd == "sum0to9") {
            int sum = compute_sum_0_to_9();
            std::cout << "Sum 0..9 = " << sum << std::endl;
            return 0;
        } else if (cmd == "sumrange") {
            if (argc < 4) {
                std::cerr << "Error: sumrange requires 2 integer arguments\n";
                print_usage(argv[0]);
                return 1;
            }
            int a = std::stoi(argv[2]);
            int b = std::stoi(argv[3]);
            int sum = sum_range(a, b);
            std::cout << "Sum range " << a << ".." << b << " = " << sum << std::endl;
            return 0;
        } else if (cmd == "fact" || cmd == "factorial") {
            if (argc < 3) {
                std::cerr << "Error: fact requires 1 integer argument\n";
                print_usage(argv[0]);
                return 1;
            }
            int n = std::stoi(argv[2]);
            long long f = factorial(n);
            if (f < 0) {
                std::cerr << "Error: factorial not defined for negative numbers\n";
                return 1;
            }
            std::cout << "factorial(" << n << ") = " << f << std::endl;
            return 0;
        } else {
            std::cerr << "Unknown command: " << cmd << "\n";
            print_usage(argv[0]);
            return 1;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error parsing arguments: " << ex.what() << "\n";
        print_usage(argv[0]);
        return 1;
    }
}
