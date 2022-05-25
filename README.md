# Toy Robot Simulator

This is a simulation of a robot toy moving on a square table top with a size of
5 units x 5 units.

## Prerequisites

 - CMake
 - Google Test

### Installation of Prerequisites

#### Linux

Run the command below to install CMake and Google Test.

    sudo apt install cmake libgtest-dev


## Building the Application

Once you have cloned the project to your working environment, go to the
project directory and run the following commands.


    cd /path/to/Toy-Robot-Simulator
    cmake .
    make

## Running the Tests

To run the tests, simply run the test target of the generated makefile.

    make test

## Running the Command Line Application

After building the project, the executable should be available in src/robot.
To run the application, execute the generated robot binary.

    ./src/robot


The application will wait for commands via the standard input. Type your command
in the terminal then press enter.

> **_NOTE:_** The input is case sensitive so all commands should be in uppercase.

### Examples

#### Example 1
    PLACE 0,0,NORTH
    MOVE
    REPORT

stdout:

    0,1,NORTH

#### Example 2
    PLACE 0,0,NORTH
    LEFT
    REPORT

stdout:

    0,0,WEST

#### Example 3
    PLACE 1,2,EAST
    MOVE
    MOVE
    LEFT
    MOVE
    REPORT

stdout:

    3,3,NORTH


