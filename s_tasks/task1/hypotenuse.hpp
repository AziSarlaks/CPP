#ifndef HYPOTENUSE_HPP
#define HYPOTENUSE_HPP

#include <cmath>

namespace Hypotenuse
{

    template <typename T, typename R>
    R calculate(const T &firstSide, const T &secondSide)
    {
        return static_cast<R>(std::hypot(firstSide, secondSide));
    }

}

#endif
