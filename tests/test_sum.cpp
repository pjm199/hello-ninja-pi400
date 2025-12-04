#include <iostream>

// Simple function under test (we'll later move logic here)
int compute_sum_0_to_9() {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int expected = 45;
    int actual = compute_sum_0_to_9();

    if (actual != expected) {
        std::cerr << "[FAIL] compute_sum_0_to_9: expected "
                  << expected << " but got " << actual << "\n";
        return 1; // non-zero = test failed
    }

    std::cout << "[PASS] compute_sum_0_to_9\n";
    return 0;
}
