#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> readNumbers(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::string text((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    std::replace(text.begin(), text.end(), ',', ' ');

    std::istringstream input(text);
    return {std::istream_iterator<int>(input), std::istream_iterator<int>()};
}

std::map<int, int> countWithFor(const std::vector<int>& numbers)
{
    std::map<int, int> counts;
    for (int number : numbers) {
        ++counts[number];
    }
    return counts;
}

std::map<int, int> countWithAlgorithm(const std::vector<int>& numbers)
{
    std::map<int, int> counts;
    std::for_each(numbers.begin(), numbers.end(),
                  [&counts](int number) { ++counts[number]; });
    return counts;
}

void printCounts(const std::map<int, int>& counts)
{
    for (const auto& item : counts) {
        std::cout << item.first << " встречается " << item.second << " раз\n";
    }
}

long double conditionalProduct(const std::vector<int>& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 1.0L,
        [](long double result, int number) {
            return number != 0 && std::abs(number) < 50
                ? result * number
                : result;
        });
}

int main()
{
    std::vector<int> first = readNumbers("s04_v1_45_1.txt");
    std::vector<int> second = readNumbers("s04_v1_45_2.txt");

    if (first.size() < second.size()) {
        first.swap(second);
    }

    std::cout << "Количество чисел в первом векторе: " << first.size() << '\n';
    std::cout << "Количество чисел во втором векторе: " << second.size() << '\n';

    const auto firstFor = countWithFor(first);
    const auto secondFor = countWithFor(second);
    const auto firstAlgorithm = countWithAlgorithm(first);
    const auto secondAlgorithm = countWithAlgorithm(second);

    std::cout << "\nПервый вектор, подсчет циклом for\n";
    printCounts(firstFor);
    std::cout << "\nПервый вектор, подсчет алгоритмом\n";
    printCounts(firstAlgorithm);
    std::cout << "\nВторой вектор, подсчет циклом for\n";
    printCounts(secondFor);
    std::cout << "\nВторой вектор, подсчет алгоритмом\n";
    printCounts(secondAlgorithm);

    const long long firstSum = std::accumulate(first.begin(), first.end(), 0LL);
    const long long secondSum = std::accumulate(second.begin(), second.end(), 0LL);

    long long firstSum2 = 0;
    long long secondSum2 = 0;
    std::for_each(first.begin(), first.end(),
                  [&firstSum2](int number) { firstSum2 += number; });
    std::for_each(second.begin(), second.end(),
                  [&secondSum2](int number) { secondSum2 += number; });

    std::cout << "\nСумма через accumulate: " << firstSum
              << " и " << secondSum << '\n';
    std::cout << "Сумма через for_each: " << firstSum2
              << " и " << secondSum2 << '\n';

    const long long firstTen = std::accumulate(first.begin(), first.begin() + 10, 0LL);
    const long long secondTen = std::accumulate(second.begin(), second.begin() + 10, 0LL);

    std::cout << "Сумма первых десяти элементов: " << firstTen
              << " и " << secondTen << '\n';
    std::cout << "Условное произведение: " << conditionalProduct(first)
              << " и " << conditionalProduct(second) << '\n';

    std::set<int> repeatedInSecond;
    std::set<int> frequentInFirst;

    for (const auto& item : secondFor) {
        if (item.second >= 2) {
            repeatedInSecond.insert(item.first);
        }
    }
    for (const auto& item : firstFor) {
        if (item.second > 3) {
            frequentInFirst.insert(item.first);
        }
    }

    std::set<int> commonNumbers;
    std::set_intersection(repeatedInSecond.begin(), repeatedInSecond.end(),
                          frequentInFirst.begin(), frequentInFirst.end(),
                          std::inserter(commonNumbers, commonNumbers.begin()));

    std::cout << "\nПодсчет общих чисел циклом for\n";
    for (int number : commonNumbers) {
        int firstCount = 0;
        int secondCount = 0;

        for (int value : first) {
            firstCount += value == number;
        }
        for (int value : second) {
            secondCount += value == number;
        }

        std::cout << number << " в первом: " << firstCount
                  << " во втором: " << secondCount << '\n';
    }

    std::cout << "Подсчет алгоритмом и лямбда-функцией\n";
    std::for_each(commonNumbers.begin(), commonNumbers.end(),
        [&first, &second](int number) {
            std::cout << number << " в первом: "
                      << std::count(first.begin(), first.end(), number)
                      << " во втором: "
                      << std::count(second.begin(), second.end(), number) << '\n';
        });

    return 0;
}
