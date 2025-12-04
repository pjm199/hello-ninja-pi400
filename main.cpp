#include <iostream>
#include <string>

int main() {
    std::string name = "Pi 400";
    std::cout << "Hello from " << name << " with C++ and Ninja!" << std::endl;

    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        sum += i;
        printf("i = %d, sum = %d\n", i, sum);
        std::cout << "i = " << i << ", cout-sum = " << sum << std::endl;
        fflush(stdout);
    }
    printf("Sum 0..9 = %d\n", sum);
    std::cout << "Sum 0..9 = " << sum << std::endl;

    return 0;
}
