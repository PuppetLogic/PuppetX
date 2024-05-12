
#include "base/Chrono.h"
#include "base/Logger.h"

#include <iostream>

int main()
{
    Chrono::start();

    STATIC_LOG(Logger::Level::Info, "Puppet started");

    return 0;
}
