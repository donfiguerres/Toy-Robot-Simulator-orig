#include <iostream>

#include <RobotDriver.h>


int main(int argc, char** argv)
{
    Robot robot;
    Parser parser;
    RobotDriver driver(robot, parser);
    driver.run();
    return 0;
}