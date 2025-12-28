/*
💗💗💗Authorized by Noore Mozassam💗💗💗
      💀💀💀Date :- 17/10/25💀💀💀 
description :- Snake Game 2D (Improved Version).
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class SnakeGame
{
private:
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;
    bool gameOver;
    const int height = 20;
    const int width = 20;
    int headX, headY, fruitX, fruitY, score;
    int tailX[100], tailY[100];
    int tailLen;

public:
    SnakeGame()
    {
        setup();
    }

    void setup()
    {
        gameOver = false;
        dir = STOP;
        headX = width / 2;
        headY = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
        tailLen = 0;
    }

    void draw()
    {
        system("cls");

        // Top Border
        cout << "\n\t\t";
        for (int i = 0; i < width; i++)
        {
            cout << "=";
        }
        cout << endl;

        // Grid
        for (int i = 0; i < height; i++)
        {
            cout << "\t\t";
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                {
                    cout << "|";
                }

                if (i == headY && j == headX)
                {
                    cout << "O"; // Snake head
                }
                else if (i == fruitY && j == fruitX)
                {
                    cout << "*"; // Fruit
                }
                else
                {
                    bool print = false;
                    for (int k = 0; k < tailLen; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o"; // Tail
                            print = true;
                            break;
                        }
                    }
                    if (!print)
                    {
                        cout << " ";
                    }
                }

                if (j == width - 1)
                {
                    cout << "|";
                }
            }
            cout << endl;
        }

        // Bottom Border
        cout << "\t\t";
        for (int i = 0; i < width; i++)
        {
            cout << "=";
        }
        cout << endl;

        cout << "\t\tScore :: " << score << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
            {
                dir = LEFT;
                break;
            }
            case 'd':
            {
                dir = RIGHT;
                break;
            }
            case 'w':
            {
                dir = UP;
                break;
            }
            case 's':
            {
                dir = DOWN;
                break;
            }
            case 'x':
            {
                gameOver = true; // Exit key
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

    void logic()
    {
        // Move tail
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = headX;
        tailY[0] = headY;

        for (int i = 1; i < tailLen; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        // Direction movement
        switch (dir)
        {
        case LEFT:
        {
            headX--;
            break;
        }
        case RIGHT:
        {
            headX++;
            break;
        }
        case UP:
        {
            headY--;
            break;
        }
        case DOWN:
        {
            headY++;
            break;
        }
        default:
        {
            break;
        }
        }

        // Wall wrap
        if (headX >= width)
        {
            headX = 0;
        }
        else if (headX < 0)
        {
            headX = width - 1;
        }

        if (headY >= height)
        {
            headY = 0;
        }
        else if (headY < 0)
        {
            headY = height - 1;
        }

        // Collision with tail
        for (int i = 0; i < tailLen; i++)
        {
            if (tailX[i] == headX && tailY[i] == headY)
            {
                gameOver = true;
            }
        }

        // Eat fruit (increase tail by 1)
        if (headX == fruitX && headY == fruitY)
        {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            tailLen += 1; // increase by exactly one
        }
    }

    void run()
    {
        while (!gameOver)
        {
            draw();
            input();
            logic();
            Sleep(70);
        }

        cout << "\n\t\tGame Over! Final Score : " << score << endl;
    }
};

int main()
{
    int choice;

    cout << "\n\n------------ Welcome to Snake Game -------------" << endl;
    cout << "Press 1 to Start" << endl;
    cout << "Press 2 to Exit" << endl;
    cout << "\nEnter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        SnakeGame game;
        game.run();
        break;
    }
    case 2:
    {
        cout << "Exiting..." << endl;
        break;
    }
    default:
    {
        cout << "Invalid choice!" << endl;
        break;
    }
    }

    return 0;
}
