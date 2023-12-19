#include "class_Snake.h"

class Board
{
    Snake *snake;
    const char SNAKE_BODY = 'O';
    Point food;
    const char FOOD = 'o';
    int score;
    bool quitGame;

public:
    Board()
    {
        spawnFood();
        snake = new Snake(10, 10);
        score = 0;
        quitGame = false;
    }

    ~Board()
    {
        delete snake;
    }

    int getScore()
    {
        return score;
    }

    void spawnFood()
    {
        int x = rand() % consoleWidth;
        int y = rand() % consoleHeight;
        food = Point(x, y);
    }

    void displayCurrentScore()
    {
        gotoxy(consoleWidth / 2, 0);
        cout << "Current Score : " << score;
    }

    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void draw()
    {
        system("cls");
        for (int i = 0; i < snake->getLength(); i++)
        {
            gotoxy(snake->body[i].xCoord, snake->body[i].yCoord);
            cout << SNAKE_BODY;
        }

        gotoxy(food.xCoord, food.yCoord);
        cout << FOOD;

        displayCurrentScore();
    }

    bool update()
    {
        if (quitGame)
        {
            return false;
        }

        bool isAlive = snake->move(food);
        if (!isAlive)
        {
            return false;
        }

        if (food.xCoord == snake->body[0].xCoord && food.yCoord == snake->body[0].yCoord)
        {
            score++;
            spawnFood();
        }

        return true;
    }
    bool shouldQuit()
    {
        return quitGame;
    }

    void getInput()
    {
        if (kbhit())
        {
            int key = getch();
            if (key == 'w' || key == 'W')
            {
                snake->changeDirection(DIR_UP);
            }
            else if (key == 'a' || key == 'A')
            {
                snake->changeDirection(DIR_LEFT);
            }
            else if (key == 's' || key == 'S')
            {
                snake->changeDirection(DIR_DOWN);
            }
            else if (key == 'd' || key == 'D')
            {
                snake->changeDirection(DIR_RIGHT);
            }
            else if (key == 'q' || key == 'Q')
            {
                quitGame = true;
            }
        }
    }
};