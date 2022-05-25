#include <iostream>

#include <Parser.h>


Parser::Parser()
{
    this->isStdin = true;
}


Parser::Parser(std::string input)
{
    this->input = input;
    this->currentPosition = 0;
    this->isStdin = false;
}


Command Parser::nextCommand()
{
    std::string line = this->isStdin ? nextLineStdin() : nextLineString();
    
    if (line.size() == 0)
        return Command(Command::END);

    if (line == "MOVE")
        return Command(Command::MOVE);

    if (line == "LEFT")
        return Command(Command::LEFT);

    if (line == "RIGHT")
        return Command(Command::RIGHT);
    
    if (line == "REPORT")
        return Command(Command::REPORT);

    // Assume it is a PLACE command
    std::vector<std::string> tokens = tokenize(line, " ");
    if (tokens.front() == "PLACE")
    {
        std::vector<std::string> params = tokenize(tokens[1], ",");
        Command result(Command::PLACE);
        auto dir = direction(params[2]);
        Position position(std::stoi(params[0]),
                            std::stoi(params[1]),
                            dir);
        result.position = position;
        return result;
    }

    return Command(Command::ERROR);
}


std::string Parser::nextLineStdin()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}


std::string Parser::nextLineString()
{
    int start = this->currentPosition;
    int end = input.find("\n", start);

    if (end = -1)
    {
        if (start < input.length())
            end = input.length();
        else
            return std::string("");
    }

    if (end + 1 < input.size())
        this->currentPosition = end + 1;
    else
        this->currentPosition = end;

    std::string result = input.substr(start, end - start);

    return result;
}


std::vector<std::string> Parser::tokenize(std::string input, std::string delimiter)
{
    std::vector<std::string> result;
    int start = 0;
    int end = input.find(delimiter, start);

    while (end != -1)
    {
        std::string sub = input.substr(start, end - start);
        result.push_back(sub);
        start = end + 1;
        end = input.find(delimiter, start);
    }

    // append last token
    std::string sub = input.substr(start, end - start);
    result.push_back(sub);

    return result;
}


Position::Direction Parser::direction(std::string input)
{
    if (input == "NORTH")
        return Position::Direction::NORTH;
    if (input == "SOUTH")
        return Position::Direction::SOUTH;
    if (input == "EAST")
        return Position::Direction::EAST;
    if (input == "WEST")
        return Position::Direction::WEST;
    // Default if can't parse
    return Position::Direction::NORTH;
}