#include <gtest/gtest.h>

#include <Robot.h>


TEST(RobotTest, MoveNorth) {
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 0, Position::Direction::NORTH);
    robot.perform(cmd1);

    Command cmd2(Command::MOVE);
    robot.perform(cmd2);

    Position newPosition = robot.getPosition();
    EXPECT_EQ(newPosition.x, 1);
    EXPECT_EQ(newPosition.y, 0);
    EXPECT_EQ(newPosition.direction, Position::Direction::NORTH);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}