#include <iostream>
#include <bits/stdc++.h>
#include <conio.h> // key press kbhit
#include <windows.h>

using namespace std;

#define MAX_LENGTH 1000

// Directions
const char DIR_UP = 'U';
const char DIR_DOWN = 'D';
const char DIR_LEFT = 'L';
const char DIR_RIGHT = 'R';

int consoleWidth, consoleHeight;

void initScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

struct Point
{
    int xCoord;
    int yCoord;
    Point()
    {
    }
    Point(int x, int y)
    {
        xCoord = x;
        yCoord = y;
    }
};

class Snake
{
    int length;
    char direction;

public:
    Point body[MAX_LENGTH];
    Snake(int x, int y)
    {
        length = 1;
        body[0] = Point(x, y);
        direction = DIR_RIGHT;
    }

    int getLength()
    {
        return length;
    }

    void changeDirection(char newDirection)
    {
        if (newDirection == DIR_UP && direction != DIR_DOWN)
        {
            direction = newDirection;
        }
        else if (newDirection == DIR_DOWN && direction != DIR_UP)
        {
            direction = newDirection;
        }
        else if (newDirection == DIR_LEFT && direction != DIR_RIGHT)
        {
            direction = newDirection;
        }
        else if (newDirection == DIR_RIGHT && direction != DIR_LEFT)
        {
            direction = newDirection;
        }
    }

    bool move(Point food)
    {

        for (int i = length - 1; i > 0; i--)
        {
            body[i] = body[i - 1];
        }

        switch (direction)
        {
            int val;
        case DIR_UP:
            val = body[0].yCoord;
            body[0].yCoord = (val - 1 + consoleHeight) % consoleHeight;
            break;
        case DIR_DOWN:
            val = body[0].yCoord;
            body[0].yCoord = (val + 1) % consoleHeight;
            break;
        case DIR_RIGHT:
            val = body[0].xCoord;
            body[0].xCoord = (val + 1) % consoleWidth;
            break;
        case DIR_LEFT:
            val = body[0].xCoord;
            body[0].xCoord = (val - 1 + consoleWidth) % consoleWidth;
            break;
        }

        // Snake bites itself
        for (int i = 1; i < length; i++)
        {
            if (body[0].xCoord == body[i].xCoord && body[0].yCoord == body[i].yCoord)
            {
                return false;
            }
        }

        // Snake eats food
        if (food.xCoord == body[0].xCoord && food.yCoord == body[0].yCoord)
        {
            body[length] = Point(body[length - 1].xCoord, body[length - 1].yCoord);
            length++;
        }

        return true;
    }
};