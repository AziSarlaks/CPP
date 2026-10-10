#include "../task1/modified_hypotenuse.hpp"

#include <array>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    using T1 = int;
    using T2 = double;

    const int M = 7;
    const int N = 20;

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(-N, N);

    std::array<T1, M> originalArray;
    std::vector<T1> originalVector(M);
    std::list<T1> originalList(M);
    std::deque<T1> originalDeque(M);

    // Классическая форма цикла for
    for (int i = 0; i < M; ++i) {
        originalArray[i] = distribution(generator);
        originalVector[i] = distribution(generator);
        originalDeque[i] = distribution(generator);
    }

    // Цикл for с итераторами
    for (auto iterator = originalList.begin(); iterator != originalList.end(); ++iterator) {
        *iterator = distribution(generator);
    }

    const T1 secondArgument = distribution(generator);

    std::vector<T2> resultFromArray;
    std::list<T2> resultFromVector;
    std::deque<T2> resultFromList;
    std::array<T2, M> resultFromDeque;

    // Классическая форма цикла for
    for (int i = 0; i < M; ++i) {
        resultFromArray.push_back(
            ModHypotenuse::calculate<T1, T2>(originalArray[i], secondArgument));
    }

    // Цикл for с итераторами
    for (auto iterator = originalVector.begin(); iterator != originalVector.end(); ++iterator) {
        resultFromVector.push_back(
            ModHypotenuse::calculate<T1, T2>(*iterator, secondArgument));
    }

    // Range-based цикл for
    for (T1 value : originalList) {
        resultFromList.push_back(
            ModHypotenuse::calculate<T1, T2>(value, secondArgument));
    }

    int index = 0;
    for (T1 value : originalDeque) {
        resultFromDeque[index] =
            ModHypotenuse::calculate<T1, T2>(value, secondArgument);
        ++index;
    }

    std::vector<std::string> rows;
    auto originalListIterator = originalList.begin();
    auto resultVectorIterator = resultFromVector.begin();
    auto resultListIterator = resultFromList.begin();

    // Все строки таблицы создаются одним циклом for
    for (int i = 0; i < M; ++i) {
        std::ostringstream row;
        row << std::fixed << std::setprecision(2)
            << "| " << originalArray[i]
            << " | " << resultFromArray[i]
            << " | " << originalVector[i]
            << " | " << *resultVectorIterator
            << " | " << *originalListIterator
            << " | " << *resultListIterator
            << " | " << originalDeque[i]
            << " | " << resultFromDeque[i] << " |";
        rows.push_back(row.str());

        ++originalListIterator;
        ++resultVectorIterator;
        ++resultListIterator;
    }

    std::ofstream file("result.md");
    file << "# Результаты работы\n\n";
    file << "Второй аргумент: " << secondArgument << "\n\n";
    file << "| array | результат vector | vector | результат list | list | результат deque | deque | результат array |\n";
    file << "|---:|---:|---:|---:|---:|---:|---:|---:|\n";

    for (const std::string& row : rows) {
        file << row << '\n';
    }

    file.close();

    std::cout << "Таблица записана в файл result.md\n";

    return 0;
}
