#include <iostream>
#include <vector>
#include <algorithm>

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Исходная матрица
    std::vector<std::vector<int>> matrix = { {2, 3, 5},
                                           {4, 7, 11},
                                           {1, 8, 15} };

    // Поиск максимального элемента в матрице
    int maxElement = matrix[0][0];
    for (const auto& row : matrix) {
        for (int num : row) {
            if (num > maxElement) {
                maxElement = num;
            }
        }
    }

    // Подсчет простых чисел в каждой строке
    std::vector<std::pair<int, int>> primeCount;  // Вектор для хранения пар (номер строки, количество простых чисел)
    for (int i = 0; i < matrix.size(); ++i) {
        int count = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (isPrime(matrix[i][j])) {
                count++;
            }
        }
        primeCount.emplace_back(i, count);
    }

    // Упорядочивание строк по невозрастанию количества простых чисел
    std::sort(primeCount.begin(), primeCount.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second >= b.second;
        });

    // Новая упорядоченная матрица
    std::vector<std::vector<int>> sortedMatrix(matrix.size(), std::vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < primeCount.size(); ++i) {
        sortedMatrix[i] = matrix[primeCount[i].first];
    }

    // Вывод результата
    for (const auto& row : sortedMatrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}