#include "class_Board.h"

class arcade
{
private:
    Board *snakeGame;

public:
    arcade();
    void enter();
    void snakeAndSnack();
};
arcade::arcade()
{
    snakeGame = NULL;
}
void arcade::enter()
{
    int choice;
    system("CLS");
    cout << "\n\n ************************** Welcome to the Arcade **************************\n"
         << endl;
    cout << "\n\n ++ Choose a game to start playing:\n"
         << "\n\n ++ 1. \tSNAKE AND SNACK"
         << "\n\n ++ 2. \tGO BACK TO STORE" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Enter your choice-> ";
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
        snakeAndSnack();
        break;
    case 3:
        return;

    default:
        break;
    }
    return;
}
void arcade::snakeAndSnack()
{
    int choice;
    system("CLS");
    cout << "\n\n--------------- ++ Get Ready to Play! ++ ---------------" << endl;
    cout << "\n\n ++ Welcome to the Snake Game!" << endl;
    cout << "\n\n ++ Control Features are as:\n"
         << "\n\n ++ FOR \'UP\', Press \'W\'"
         << "\n\n ++ FOR \'DOWN\', Press \'S\'"
         << "\n\n ++ FOR \'RIGHT\', Press \'D\'"
         << "\n\n ++ FOR \'LEFT\', Press \'A\'"
         << "\n\n ++ TO  \'QUIT\', Press \'Q\'" << endl;
    cout << "\n\n **************************\n"
         << endl;
    cout << "\n\n ++ Please WAIT, the game will start soon...";
    Sleep(5000);

    srand(time(0));
    initScreen();
    snakeGame = new Board();

    while (snakeGame->update() && !snakeGame->shouldQuit())
    {
        snakeGame->getInput();
        snakeGame->draw();
        Sleep(50);
    }

    Sleep(1000);

    do
    {
        system("CLS");
        cout << "\n\n--------------- ++ Game Over! ++ ---------------\n"
             << endl;
        cout << "\n\n ~-- WELL PLAYED --~" << endl;
        cout << "\n\n ++ Final Score is: " << snakeGame->getScore() << endl;
        cout << "\n\n--------------- ++ Thank You for Playing! ++ ---------------\n"
             << endl;
        cout << "\n\n ++ Press \'1\' to head back to Arcade" << endl;
        cout << "\n\n **************************\n"
             << endl;
        cout << "\n\n ++ Enter your choice-> ";
        cin >> choice;
    } while (choice != 1);
    if (choice == 1)
    {
        enter();
    }

    return;
}