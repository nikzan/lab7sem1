#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "/Users/nikzan/CLionProjects/lab7/include/fill_array.h"

void fill_array_random(int* arr, int n) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 100 - 50;
    }
}

void fill_array_console(int* arr, int n) {
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

void fill_array_file(int* arr, int n, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!(inputFile >> arr[i])) break;
    }
    inputFile.close();
}