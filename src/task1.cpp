#include <iostream>

void task1(int* arr, int n) {
    int result = 0;
    for (int i = 0; i < 9; ++i) {
        if (arr[i] < arr[9]) {
            result = arr[i];
            break;
        }
    }
    std::cout << result << std::endl;
}