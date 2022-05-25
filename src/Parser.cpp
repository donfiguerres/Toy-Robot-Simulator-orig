#include <iostream>

#include <Parser.h>


Parser::Parser()
{
    this->isStdin = true;
}


Parser::Parser(std::string input)
{
    this->input = input;
    this->isStdin = false;
}


Command Parser::nextCommand()
{
    std::string line;

    if (this->isStdin)
        line = nextLineStdin();
    else
        line = nextLineString();

    if (line.size() == 0)
        return Command::END;
}


std::string Parser::nextLineStdin()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

std::string Parser::nextLineString()
{
    std::string string("");
    return string;
}