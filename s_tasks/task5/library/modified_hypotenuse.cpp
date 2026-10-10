#include "modified_hypotenuse.hpp"

#include "hypotenuse.hpp"

#include <random>

namespace ModHypotenuse
{

int calculate(int firstSide, int secondSide)
{
    static std::mt19937 generator(std::random_device{}());
    int result = Hypotenuse::calculate(firstSide, secondSide);

    if (std::uniform_int_distribution<int>(0, 1)(generator)) {
        result += std::uniform_int_distribution<int>(1, 10)(generator);
    }

    return result;
}

}
