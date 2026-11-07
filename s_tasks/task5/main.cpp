#include "my_lib.h"

#include <iostream>
#include <limits>

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Введите длины двух катетов: ";
    if (!(std::cin >> a >> b) || a < 0 || b < 0) {
        std::cerr << "Необходимо ввести два неотрицательных целых числа\n";
        return 1;
    }

    if (normal::f<int, double>(a, b) > std::numeric_limits<int>::max() - 10) {
        std::cerr << "Результат с возможной добавкой должен помещаться в int\n";
        return 1;
    }

    std::cout << "Обычная функция (int): "
              << normal::f<int>(a, b) << '\n';

    std::cout << "Модифицированная функция (int): "
              << randomized::f<int>(a, b) << '\n';

    std::cout << "Обычная функция (double): "
              << normal::f<double>(1.5, 2.0) << '\n';

    std::cout << "Целые аргументы, результат double: "
              << normal::f<int, double>(a, b) << '\n';

    return 0;
}
