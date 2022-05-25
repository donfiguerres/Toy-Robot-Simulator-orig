#ifndef COMMAND

#include <Position.h>

class Command
{
public:
    enum CommandType {
        PLACE,
        MOVE,
        LEFT,
        RIGHT,
        REPORT,
        END // end of input
    };

    Command(CommandType commandType);
    CommandType commandType;
    Position position;
};

#endif