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

void fill_matrix_random(int** matrix, int m, int n) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = std::rand() % 100 - 50;
        }
    }
}

void fill_matrix_console(int** matrix, int m, int n) {
    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void fill_matrix_file(int** matrix, int m, int n, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(inputFile >> matrix[i][j])) break;
        }
    }
    inputFile.close();
}