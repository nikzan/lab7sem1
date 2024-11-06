#include <iostream>

int main() {
    int A[10] = {5, 3, 8, 6, 2, 7, 4, 9, 1, 4};
    int result = 0;

    for (int i = 0; i < 9; ++i) {
        if (A[i] < A[9]) {
            result = A[i];
            break;
        }
    }

    std::cout << result << std::endl;
    return 0;
}