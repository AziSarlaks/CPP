#include "hypotenuse.hpp"

#include <cmath>

namespace Hypotenuse
{

int calculate(int firstSide, int secondSide)
{
    return static_cast<int>(std::hypot(firstSide, secondSide));
}

}
