#include <iostream>

void task5(int** matrix, int m, int n, int k) {
    if (k < 1 || k > m) {
        std::cerr << "Неверное значение K." << std::endl;
        return;
    }

    int sum = 0;
    int product = 1;
    for (int j = 0; j < n; ++j) {
        sum += matrix[k - 1][j];
        product *= matrix[k - 1][j];
    }

    std::cout << "Сумма элементов " << k << "-й строки: " << sum << std::endl;
    std::cout << "Произведение элементов " << k << "-й строки: " << product << std::endl;
}