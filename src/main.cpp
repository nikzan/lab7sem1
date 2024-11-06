#include <iostream>
#include <fstream>
#include "/Users/nikzan/CLionProjects/lab7/include/fill_array.h"
#include "/Users/nikzan/CLionProjects/lab7/include/tasks.h"

int countNumbersInFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return -1;
    }
    int count = 0;
    int number;
    while (inputFile >> number) {
        ++count;
    }
    inputFile.close();
    return count;
}

int main() {
    int n = 0;
    int fillChoice;
    std::cout << "==================================" << std::endl;
    std::cout << "Выберите метод заполнения массива:\n1. Рандом\n2. С консоли\n3. Из файла\n";
    std::cout << "==================================" << std::endl;
    std::cin >> fillChoice;

    if (fillChoice == 1 || fillChoice == 2) {
        std::cout << "==================================" << std::endl;
        std::cout << "Введите размер массива: ";
        std::cin >> n;
    } else if (fillChoice == 3) {
        n = countNumbersInFile("/Users/nikzan/CLionProjects/lab7/input.txt");
        if (n <= 0) {
            std::cerr << "Ошибка при определении размера массива из файла." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Неверный выбор." << std::endl;
        return 1;
    }

    int* arr = new int[n];

    switch (fillChoice) {
        case 1:
            fill_array_random(arr, n);
            std::cout << "Массив: ";
            for (int i = 0; i < n; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            break;
        case 2:
            fill_array_console(arr, n);
            break;
        case 3:
            fill_array_file(arr, n, "/Users/nikzan/CLionProjects/lab7/input.txt");
            break;
        default:
            std::cerr << "Неверный выбор." << std::endl;
            delete[] arr;
            return 1;
    }

    int taskChoice;
    std::cout << "==================================" << std::endl;
    std::cout << "Выберите задание (1 - 4): ";
    std::cin >> taskChoice;
    std::cout << "==================================" << std::endl;

    switch (taskChoice) {
        case 1:
            if (n != 10) {
                std::cerr << "Для задания 1 размер массива должен быть равен 10." << std::endl;
                delete[] arr;
                return 1;
            }
            task1(arr, n);
            break;
        case 2:
            task2(arr, n);
            break;
        case 3:
            task3(arr, n);
            break;
        case 4:
            task4(arr, n);
            break;
        default:
            std::cerr << "Неверный выбор." << std::endl;
            delete[] arr;
            return 1;
    }
    std::cout << "==================================" << std::endl;

    delete[] arr;
    return 0;
}