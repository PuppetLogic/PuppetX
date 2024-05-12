
#include <base/Logger.h>

#include <TestFixture.h>

#include <gtest/gtest.h>


class StreamRedirector
{
public:

    void redirectStreams()
    {
        _coutBuffer = std::cout.rdbuf();
        _cerrBuffer = std::cerr.rdbuf();

        std::cout.rdbuf(fakeCout.rdbuf());
        std::cerr.rdbuf(fakeCerr.rdbuf());
    }

    void resetStreams()
    {
        std::cout.rdbuf(_coutBuffer);
        std::cerr.rdbuf(_cerrBuffer);
    }

    std::stringstream fakeCout;
    std::stringstream fakeCerr;

private:
    std::streambuf* _coutBuffer{};
    std::streambuf* _cerrBuffer{};
};

class LoggerTest : public TestFixture
{
public:

    StreamRedirector streamRedirector;
};

TEST_F(LoggerTest, staticLog)
{
    struct TestCase
    {
        std::string name;
        Logger::Level level;
        std::string levelName;
        int id;
        std::string message;

        std::stringstream& streamBuffer;
    };

    std::vector<TestCase> testCases
    {
        {"Log Debug level", Logger::Level::Debug, "DEBUG", 0, "Debug test message", streamRedirector.fakeCout},
        {"Log Info level", Logger::Level::Info, "INFO", 1, "Info test message", streamRedirector.fakeCout},
        {"Log Warning level", Logger::Level::Warning, "WARNING", 2, "Warning test message", streamRedirector.fakeCerr},
        {"Log Error level", Logger::Level::Error, "ERROR", 3, "Error test message", streamRedirector.fakeCerr},
        {"Log Fatal level", Logger::Level::Fatal, "FATAL", 4, "Fatal test message", streamRedirector.fakeCerr}
    };

    streamRedirector.redirectStreams();

    for (auto const& test : testCases)
    {
        STATIC_LOG(test.level, test.message);

        int logLine = 68;
        std::string messageToExpect =
            "#[" + std::to_string(test.id)
            + "][" + std::to_string(Chrono::elapsed())
            + "][" + test.levelName
            + "] " + std::string(__FILE__)
            + " (" + std::string(__func__)
            + ") line: " + std::to_string(logLine)
            + " -> " + test.message
            + "\n";

        ASSERT_EQ(test.streamBuffer.str(), messageToExpect);

        test.streamBuffer.str("");
        test.streamBuffer.clear();
    }

    streamRedirector.resetStreams();
}

TEST_F(LoggerTest, logToFile)
{

}
