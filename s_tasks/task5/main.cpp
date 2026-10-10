#include "hypotenuse.hpp"
#include "modified_hypotenuse.hpp"

#include <iostream>

int main()
{
    int firstSide = 0;
    int secondSide = 0;

    std::cout << "Введите длины двух катетов: ";
    std::cin >> firstSide >> secondSide;

    if (!std::cin || firstSide < 0 || secondSide < 0) {
        std::cerr << "Необходимо ввести два неотрицательных целых числа\n";
        return 1;
    }

    std::cout << "Обычная функция: "
              << Hypotenuse::calculate(firstSide, secondSide) << '\n';
    std::cout << "Модифицированная функция: "
              << ModHypotenuse::calculate(firstSide, secondSide) << '\n';

    return 0;
}
