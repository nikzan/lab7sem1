#include <iostream>
#include <climits>

void task3(int* arr, int n) {
    int Min = INT_MAX;
    int Kol = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            if (arr[i] < Min) {
                Min = arr[i];
                Kol = 1;
            } else if (arr[i] == Min) {
                Kol++;
            }
        }
    }

    std::cout << "Минимальный положительный элемент: " << Min << std::endl;
    std::cout << "Количество таких элементов: " << Kol << std::endl;
}