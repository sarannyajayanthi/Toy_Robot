// toy_robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ToyRobot
{
    int dimensionX, dimensionY;
    int posX, posY;
    string direction;
    bool isRobotPlaced;

public:
    ToyRobot(int dimX, int dimY);
    int place(int posX, int posY, string direction);
    void move();
    void right();
    void left();
    void report();

};

//Member functions
ToyRobot::ToyRobot(int dimX, int dimY)
{
    dimensionX = dimX;
    dimensionY = dimY;
    isRobotPlaced = false;
}

int ToyRobot::place(int iposX, int iposY, string sdirection)
{
    if (iposX >= 0 && iposX < 5 && iposY >= 0 && iposY < 5)
    {
        posX = iposX;
        posY = iposY;

        if (sdirection == "NORTH" || sdirection == "SOUTH" || sdirection == "EAST" || sdirection == "WEST")
        {
            direction = sdirection;
            isRobotPlaced = true;

            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
        return 0;
}

void ToyRobot::move()
{
    if (isRobotPlaced)
    {
        if (direction == "NORTH" && posY < 4)
            posY++;
        else if (direction == "SOUTH" && posY > 0)
            posY--;
        else if (direction == "WEST"  && posX > 0)
            posX--;
        else if (direction == "EAST"  && posX < 4)
            posX++;
    }
}

void ToyRobot::left()
{
    if (isRobotPlaced)
    {
        if (direction == "NORTH")
            direction = "WEST";
        else if (direction == "WEST")
            direction = "SOUTH";
        else if (direction == "SOUTH")
            direction = "EAST";
        else if (direction == "EAST")
            direction = "NORTH";
    }
}

void ToyRobot::right()
{
    if (isRobotPlaced)
    {
        if (direction == "NORTH")
            direction = "EAST";
        else if (direction == "EAST")
            direction = "SOUTH";
        else if (direction == "SOUTH")
            direction = "WEST";
        else if (direction == "WEST")
            direction = "NORTH";
    }
}

void ToyRobot::report()
{
    if (isRobotPlaced)
    {
        cout << posX << "," << posY << "," << direction << "\n";
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "No input file to process";
        return 0;
    }
    std::string input = argv[1];

    string line,sLine,sKeyword,sXPos,sYPos,sDirection;
    int iXPos, iYPos;
    ifstream myfile;
    myfile.open(input);
    if (myfile.is_open())
    {
        ToyRobot robot(5, 5);
        //Parse the commands from file(one line at a time)
        while (std::getline(myfile, line))
        {
            //cout << line << endl;
            stringstream check1(line);
            while (getline(check1, sKeyword, ' '))
            {
                if (sKeyword == "PLACE")
                {
                    getline(check1, sXPos, ',');
                    getline(check1, sYPos, ',');
                    getline(check1, sDirection);

                    //Convert positions read as strings to integers for position computations.
                    stringstream stoi;
                    stoi << sXPos;
                    stoi >> iXPos;
                    stoi.str("");
                    stoi.clear();

                    stoi << sYPos;
                    stoi >> iYPos;
                    stoi.str("");
                    stoi.clear();

                    if (!robot.place(iXPos, iYPos, sDirection))
                    {
                        //Error placing toy robot
                        cout << "Error Placing Toy Robot in position " << iXPos << "," << iYPos;
                        return 1;
                    }
                }
                else if (sKeyword == "MOVE")
                {
                    robot.move();
                }
                else if (sKeyword == "LEFT")
                {
                    robot.left();
                }
                else if (sKeyword == "RIGHT")
                {
                    robot.right();
                }
                else if (sKeyword == "REPORT")
                {
                    robot.report();
                    return 0;
                }
            }
        }
        myfile.close();
        return 0;
    }
    else
    {
        cout << "Unable to open file";
        return 1;
    }     
}

