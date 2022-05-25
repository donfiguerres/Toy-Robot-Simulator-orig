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


TEST(ParserTest, Left) {
    Parser parser("LEFT");
    EXPECT_EQ(parser.nextCommand().commandType, Command::LEFT);
}


TEST(ParserTest, Right) {
    Parser parser("RIGHT");
    EXPECT_EQ(parser.nextCommand().commandType, Command::RIGHT);
}


TEST(ParserTest, Report) {
    Parser parser("REPORT");
    EXPECT_EQ(parser.nextCommand().commandType, Command::REPORT);
}


TEST(ParserTest, ReportLowerCase) {
    Parser parser("report");
    EXPECT_EQ(parser.nextCommand().commandType, Command::REPORT);
}


TEST(ParserTest, Place) {
    Parser parser("PLACE 1,2,NORTH");
    Command nextCommand = parser.nextCommand();
    EXPECT_EQ(nextCommand.commandType, Command::PLACE);
    EXPECT_EQ(nextCommand.position.x, 1);
    EXPECT_EQ(nextCommand.position.y, 2);
    EXPECT_EQ(nextCommand.position.direction, Position::Direction::NORTH);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}