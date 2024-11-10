#include <iostream>

void task8(int** matrix, int m, int n) {
    int max_value = matrix[0][0];
    int max_i = 0, max_j = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    std::cout << "Первый максимальный элемент: " << max_value << std::endl;
    std::cout << "Индексы: (" << max_i << ", " << max_j << ")" << std::endl;
}