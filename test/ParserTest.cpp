#include <gtest/gtest.h>

#include <Parser.h>


TEST(ParserTest, EndOfInput) {
    Parser parser("");
    EXPECT_EQ(parser.nextCommand().commandType, Command::END);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}