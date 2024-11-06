#include <iostream>
#include <climits>

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* X = new int[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> X[i];
    }

    int Min = INT_MAX;
    int Kol = 0;

    for (int i = 0; i < n; ++i) {
        if (X[i] > 0) {
            if (X[i] < Min) {
                Min = X[i];
                Kol = 1;
            } else if (X[i] == Min) {
                Kol++;
            }
        }
    }

    std::cout << "Минимальный положительный элемент: " << Min << std::endl;
    std::cout << "Количество таких элементов: " << Kol << std::endl;

    delete[] X;
    return 0;
}