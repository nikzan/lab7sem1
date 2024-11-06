#include <iostream>
#include <vector>

void insert_zero(std::vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it < 0) {
            it = vec.insert(it, 0);
            ++it;
        }
    }
}

void task4(int* arr, int n) {
    std::vector<int> vec(arr, arr + n);
    insert_zero(vec);
    std::cout << "Вектор после вставки 0 перед отрицательными элементами: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}