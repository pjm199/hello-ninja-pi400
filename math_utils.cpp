#include "math_utils.hpp"

int compute_sum_0_to_9() {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }
    return sum;
}

int sum_range(int a, int b) {
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    long long sum = 0;
    for (int i = a; i <= b; ++i) {
        sum += i;
    }

    // In un progetto serio gestiresti overflow,
    // qui ci fidiamo che rientri in int.
    return static_cast<int>(sum);
}

long long factorial(int n) {
    if (n < 0) {
        return -1; // errore
    }

    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
