#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("/Users/nikzan/CLionProjects/lab7/input.txt"); // Работает только по абсолютному пути o_0
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }
    inputFile.close();

    std::cout << "Исходный вектор: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it < 0) {
            it = numbers.insert(it, 0);
            ++it; // Пропустить вставленный 0
        }
    }

    std::cout << "Вектор после вставки 0 перед отрицательными элементами: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;

    // input 1 2 3 4 5 -1 -5 3 1 -123 10 98
    // output 1 2 3 4 5 0 -1 0 -5 3 1 0 -123 10 98
}