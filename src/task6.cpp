#include <iostream>

void swap_rows(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void task6(int** matrix, int m, int n, int k1, int k2) {
    if (k1 < 1 || k1 >= k2 || k2 > m) {
        std::cerr << "Неверные значения K1 и K2." << std::endl;
        return;
    }

    for (int j = 0; j < n; ++j) {
        swap_rows(matrix[k1 - 1][j], matrix[k2 - 1][j]);
    }
    std::cout << "Строки " << k1 << " и " << k2 << " поменяны местами." << std::endl;

    std::cout << "Измененная матрица:" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}