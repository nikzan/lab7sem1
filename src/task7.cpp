#include <iostream>

void task7(int** matrix, int n, int k1, int k2) {
    if (k1 < 1 || k2 > n || k1 > k2) {
        std::cerr << "Неверные значения K1 и K2." << std::endl;
        return;
    }

    int S1 = 0, S2 = 0, S3 = 0, S4 = 0;

    for (int i = k1 - 1; i < k2; ++i) {
        for (int j = 0; j < n; ++j) {
            S1 += matrix[i][j];
        }
    }

    for (int j = k1 - 1; j < k2; ++j) {
        for (int i = 0; i < n; ++i) {
            S2 += matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        S3 += matrix[i][i];
    }

    for (int i = 0; i < n; ++i) {
        S4 += matrix[i][n - i - 1];
    }

    std::cout << "Сумма элементов в строках с " << k1 << "-й по " << k2 << "-ю: " << S1 << std::endl;
    std::cout << "Сумма элементов в столбцах с " << k1 << "-го по " << k2 << "-й: " << S2 << std::endl;
    std::cout << "Сумма элементов главной диагонали: " << S3 << std::endl;
    std::cout << "Сумма элементов побочной диагонали: " << S4 << std::endl;
}