#pragma once

#include <cmath>
#include <random>

namespace normal {

    template <typename T, typename R = T>
    R f(T x, T y) {
        return static_cast<R>(std::hypot(x, y));
    }

}

namespace randomized {

    template <typename T, typename R = T>
    R f(T x, T y) {
        static std::mt19937 generator(std::random_device{}());
        R result = normal::f<T, R>(x, y);

        if (std::uniform_int_distribution<int>(0, 1)(generator)) {
            result += static_cast<R>(
                std::uniform_int_distribution<int>(1, 10)(generator));
        }

        return result;
    }

}
