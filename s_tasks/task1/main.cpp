#include "hypotenuse.hpp"
#include "modified_hypotenuse.hpp"

#include <iostream>

int main()
{
    int firstSide = 0;
    int secondSide = 0;

    std::cout << "Введите длины двух катетов: ";
    std::cin >> firstSide >> secondSide;

    std::cout << Hypotenuse::calculate<int, int>(firstSide, secondSide) << '\n';
    std::cout << ModHypotenuse::calculate<int, int>(firstSide, secondSide) << '\n';

    return 0;
}
