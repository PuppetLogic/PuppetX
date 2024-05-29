
#include "TestFixture.h"


TEST(ChronoTest, elapsedTime)
{
    Chrono time;
    time.start();

    TestFixture::wait(1000);

    auto elapsed = time.elapsed();

    ASSERT_TRUE(elapsed > 900 && elapsed < 1100);
}
