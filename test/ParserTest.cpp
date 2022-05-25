#include <gtest/gtest.h>

#include <Parser.h>


TEST(ParserTest, Place) {
    Parser parser;
    EXPECT_STRNE("hello", "world");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}