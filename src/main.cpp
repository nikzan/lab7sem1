#include <iostream>
#include <fstream>
#include "/Users/nikzan/CLionProjects/lab7/include/fill_array.h"
#include "/Users/nikzan/CLionProjects/lab7/include/tasks.h"

int count_numbers_in_file(const std::string& filename) {
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
    int task_choice;
    std::cout << "==================================" << std::endl;
    std::cout << "Выберите задание (1 - 8): ";
    std::cin >> task_choice;

    int m = 0, n = 0;

    int fill_choice;
    std::cout << "==================================" << std::endl;
    std::cout << "Выберите метод заполнения массива:\n1. Рандом\n2. С консоли\n3. Из файла\n";
    std::cout << "==================================" << std::endl;
    std::cin >> fill_choice;

    if (task_choice >= 1 && task_choice <= 4) {
        if (fill_choice == 1 || fill_choice == 2) {
            std::cout << "==================================" << std::endl;
            std::cout << "Введите размер массива: ";
            std::cin >> n;
        } else if (fill_choice == 3) {
            n = count_numbers_in_file("/Users/nikzan/CLionProjects/lab7/input.txt");
            if (n <= 0) {
                std::cerr << "Ошибка при определении размера массива из файла." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Неверный выбор." << std::endl;
            return 1;
        }

        int* arr = new int[n];

        switch (fill_choice) {
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

        switch (task_choice) {
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
        delete[] arr;

    } else if (task_choice >= 5 && task_choice <= 8) {

        if (fill_choice == 1 || fill_choice == 2) {
            if (task_choice == 7) {
                std::cout << "==================================" << std::endl;
                std::cout << "Введите N: ";
                std::cin >> n;
                m = n;
            } else {
                std::cout << "==================================" << std::endl;
                std::cout << "Введите число строк M: ";
                std::cin >> m;
                std::cout << "Введите число столбцов N: ";
                std::cin >> n;
            }
        } else if (fill_choice == 3) {
            n = count_numbers_in_file("/Users/nikzan/CLionProjects/lab7/input.txt");
            if (m*n <= 0) {
                std::cerr << "Ошибка при определении размера массива из файла." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Неверный выбор." << std::endl;
            return 1;
        }

        int** matrix = new int*[m];
        for (int i = 0; i < m; ++i) {
            matrix[i] = new int[n];
        }

        switch (fill_choice) {
            case 1:
                fill_matrix_random(matrix, m, n);
                std::cout << "Матрица: " << std::endl;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            case 2:
                fill_matrix_console(matrix, m, n);
                break;
            case 3:
                fill_matrix_file(matrix, m, n, "/Users/nikzan/CLionProjects/lab7/input.txt");
                break;
            default:
            std::cerr << "Неверный выбор." << std::endl;
            for (int i = 0; i < m; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            return 1;
        }
        std::cout << "==================================" << std::endl;

        int k, k1, k2;

        switch (task_choice) {
        case 5:
            std::cout << "Введите номер строки K (1 <= K <= M): ";
            std::cin >> k;
            task5(matrix, m, n, k);
            break;
        case 6:
            std::cout << "Введите номера строк K1 и K2 (1 <= K1, K2 <= M): ";
            std::cin >> k1 >> k2;
            task6(matrix, m, n, k1, k2);
            break;
        case 7:
            std::cout << "Введите номера строк K1 и K2 (1 <= K1, K2 <= M): ";
            std::cin >> k1 >> k2;
            task7(matrix, n, k1, k2);
            break;
        case 8:
            task8(matrix, m, n);
            break;
        default:
            std::cerr << "Неверный выбор." << std::endl;
            for (int i = 0; i < m; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            return 1;
        }
        for (int i = 0; i < m; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

    } else {
        std::cerr << "Неверный выбор." << std::endl;
        return 1;
    }

    std::cout << "==================================" << std::endl;
    return 0;
}

