#pragma once

void fill_array_random(int* arr, int n);
void fill_array_console(int* arr, int n);
void fill_array_file(int* arr, int n, const std::string& filename);

void fill_matrix_random(int** matrix, int m, int n);
void fill_matrix_console(int** matrix, int m, int n);
void fill_matrix_file(int** matrix, int m, int n, const std::string& filename);