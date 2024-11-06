#include <iostream>

void remove_duplicates(int* arr, int& n) {
    if (n == 0) return;

    int new_index = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            arr[new_index++] = arr[i];
        }
    }

    n = new_index;
}

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    remove_duplicates(arr, n);

    std::cout << "Массив после удаления дубликатов: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}