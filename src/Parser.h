#ifndef PARSER

#include <string>

#include <Command.h>


class Parser
{
public:
    // Input reading can be abstracted to a separate class later.
    // For now, I've included it here for simplicity.
    Parser();
    Parser(std::string input);
    Command nextCommand();

private:
    std::string nextLineStdin();
    std::string nextLineString();

    bool isStdin;
    const char *currentPos;
};

#endif