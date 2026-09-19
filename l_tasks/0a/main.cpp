#include "module1.h"
#include "module2.h"
#include "module3.h"

#include <iostream>
using std::cout;

int main() {
    cout << "Hello world!\n";

    cout << Module1::getMyName() << '\n';
    cout << Module2::getMyName() << '\n';

    using namespace Module1;
    cout << getMyName() << '\n';  // (A): John
    cout << Module2::getMyName() << '\n';

    // Если раскомментировать обе следующие строки, вызов станет неоднозначным:
    // using namespace Module2;          // (B)
    // cout << getMyName() << '\n'; // (C): compilation error

    using Module2::getMyName;
    cout << getMyName() << '\n';  // (D): James

    cout << Module3::getMyName() << '\n';
    return 0;
}
