#include <gtest/gtest.h>

#include <Parser.h>


TEST(ParserTest, EndOfInput) {
    Parser parser("");
    EXPECT_EQ(parser.nextCommand().commandType, Command::END);
}


TEST(ParserTest, Move) {
    Parser parser("MOVE");
    EXPECT_EQ(parser.nextCommand().commandType, Command::MOVE);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}