#include <RobotDriver.h>


RobotDriver::RobotDriver(Robot &robot, Parser &parser)
{
    this->robot = robot;
    this->parser = parser;
}


void RobotDriver::run()
{
    Command cmd = parser.nextCommand();

    while (cmd.commandType != Command::CommandType::END)
    {
        robot.perform(cmd);
        cmd = parser.nextCommand();
    }
}
