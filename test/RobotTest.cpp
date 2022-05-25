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
    EXPECT_EQ(newPosition.x, 0);
    EXPECT_EQ(newPosition.y, 1);
    EXPECT_EQ(newPosition.direction, Position::Direction::NORTH);
}


TEST(RobotTest, AvoidFalling) {
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 5, Position::Direction::NORTH);
    robot.perform(cmd1);

    Command cmd2(Command::MOVE);
    robot.perform(cmd2);

    Position newPosition = robot.getPosition();
    EXPECT_EQ(newPosition.x, 0);
    EXPECT_EQ(newPosition.y, 5);
    EXPECT_EQ(newPosition.direction, Position::Direction::NORTH);
}


TEST(RobotTest, Rotate) {
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(0, 0, Position::Direction::NORTH);
    robot.perform(cmd1);

    Command cmd2(Command::RIGHT);
    robot.perform(cmd2);

    Position newPosition = robot.getPosition();
    EXPECT_EQ(newPosition.x, 0);
    EXPECT_EQ(newPosition.y, 0);
    EXPECT_EQ(newPosition.direction, Position::Direction::EAST);
}


TEST(RobotTest, Complex) {
    Robot robot;

    Command cmd1(Command::PLACE);
    cmd1.position = Position(1, 2, Position::Direction::EAST);
    robot.perform(cmd1);

    Command moveCmd(Command::MOVE);
    Command leftCmd(Command::LEFT);

    robot.perform(moveCmd);
    robot.perform(moveCmd);
    robot.perform(leftCmd);
    robot.perform(moveCmd);

    Position newPosition = robot.getPosition();
    EXPECT_EQ(newPosition.x, 3);
    EXPECT_EQ(newPosition.y, 3);
    EXPECT_EQ(newPosition.direction, Position::Direction::NORTH);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}