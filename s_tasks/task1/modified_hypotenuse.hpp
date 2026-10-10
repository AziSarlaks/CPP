#ifndef MODIFIED_HYPOTENUSE_HPP
#define MODIFIED_HYPOTENUSE_HPP

#include "hypotenuse.hpp"
#include <random>

namespace ModHypotenuse
{

    template <typename T, typename R>
    R calculate(const T &firstSide, const T &secondSide)
    {
        static std::mt19937 generator(std::random_device{}());
        R result = Hypotenuse::calculate<T, R>(firstSide, secondSide);

        if (std::uniform_int_distribution<int>(0, 1)(generator))
        {
            result += static_cast<R>(
                std::uniform_int_distribution<int>(1, 10)(generator));
        }

        return result;
    }

}

#endif
