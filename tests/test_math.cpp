#include <iostream>
#include "math_utils.hpp"

bool test_compute_sum_0_to_9() {
    int expected = 45;
    int actual = compute_sum_0_to_9();
    if (actual != expected) {
        std::cerr << "[FAIL] compute_sum_0_to_9: expected "
                  << expected << " but got " << actual << "\n";
        return false;
    }
    std::cout << "[PASS] compute_sum_0_to_9\n";
    return true;
}

bool test_sum_range() {
    bool ok = true;

    struct Case {
        int a, b;
        int expected;
    };

    Case cases[] = {
        {0, 0, 0},
        {1, 3, 6},      // 1+2+3
        {-2, 2, 0},     // -2 -1 +0 +1 +2
        {5, 5, 5},
        {7, 3, 25}      // ordine invertito: 3+4+5+6+7 = 25
    };

    for (const auto& c : cases) {
        int actual = sum_range(c.a, c.b);
        if (actual != c.expected) {
            std::cerr << "[FAIL] sum_range(" << c.a << ", " << c.b
                      << "): expected " << c.expected
                      << " but got " << actual << "\n";
            ok = false;
        } else {
            std::cout << "[PASS] sum_range(" << c.a << ", " << c.b << ")\n";
        }
    }

    return ok;
}

bool test_factorial() {
    bool ok = true;

    struct Case {
        int n;
        long long expected;
    };

    Case cases[] = {
        {0, 1},
        {1, 1},
        {5, 120},
        {10, 3628800},
        {-1, -1}   // errore
    };

    for (const auto& c : cases) {
        long long actual = factorial(c.n);
        if (actual != c.expected) {
            std::cerr << "[FAIL] factorial(" << c.n << "): expected "
                      << c.expected << " but got " << actual << "\n";
            ok = false;
        } else {
            std::cout << "[PASS] factorial(" << c.n << ")\n";
        }
    }

    return ok;
}

int main() {
    bool ok = true;

    ok = test_compute_sum_0_to_9() && ok;
    ok = test_sum_range() && ok;
    ok = test_factorial() && ok;

    if (!ok) {
        std::cerr << "Some tests FAILED\n";
        return 1;
    }

    std::cout << "All tests PASSED\n";
    return 0;
}
