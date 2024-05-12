
#include "utils/Chrono.h"

#include <iostream>

int main()
{
    Chrono time;
    time.start();

    std::cout << "Hello, World! " << time.elapsed() << std::endl;
    return 0;
}
