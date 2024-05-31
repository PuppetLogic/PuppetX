
#include <base/Chrono.h>

#include <TestFixture.h>

#include <gtest/gtest.h>


TEST(ChronoTest, elapsedTime)
{
    Chrono::start();

    TestFixture::wait(1000);

    auto elapsed = Chrono::elapsed();

    ASSERT_TRUE(elapsed > 900 && elapsed < 1100);
}
