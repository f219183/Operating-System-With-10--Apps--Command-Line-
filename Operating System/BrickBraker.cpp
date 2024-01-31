// including necessary libraries
#include <iostream>				
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

// Declaring and initialising constants, variables, and arrays
const int screenWidth = 52;
const int screenHeight = 20;
int paddlePos[2] = { 22,18 };	// Declaring a 1D array containing the paddle's inital reference position value (coordiantes)
int ballPos[2] = { 27,17 };		// Declaring a 1D array containing the ball's inital reference position value	(coordiantes)	
int bricks_Position[16][2]		// Declaring a 2D array containing the brick's position coordinates 
{
    {3,2},{3,8},{3,14},{3,20},{3,26},{3,32},{3,38},{3,44},{5,2},{5,8},{5,14},{5,20},{5,26},{5,32},{5,38},{5,44}
};
int Bricks_Array[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };		// Declaring a 1D array to store and show the bricks. 
int ballDirection = 1;
int number_Of_Bricks = 16;		// Using 16 bricks in our game
int score = 0;
fstream out_File;		// Score output file


void gotoxy(int x, int y)   //function to move cursor on console
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to draw and output screen borders for the game
void borders()
{
    gotoxy(0, 0);
    for (int i = 0; i < screenWidth; ++i)
        cout << '=';
    gotoxy(0, screenHeight - 1);
    for (int i = 0; i < screenWidth; ++i)
        cout << '=';
    for (int i = 0; i < screenHeight; ++i)
    {
        gotoxy(0, i);
        cout << "|";
        gotoxy(screenWidth, i);
        cout << "|";
    }

}

// Function to display the Main Menu of the game (Initial Display)
void mainMenu()
{
    borders();
    gotoxy(11, 2);
    cout << "++++++++++++++++++++++++++++++";
    gotoxy(11, 3);
    cout << "X                            X";
    gotoxy(11, 4);
    cout << "X       Brick Breaker        X";
    gotoxy(11, 5);
    cout << "X                            X";
    gotoxy(11, 6);
    cout << "++++++++++++++++++++++++++++++";
    gotoxy(6, 12);
    cout << "1) Play";
    gotoxy(6, 13);
    cout << "2) How to play?";
    gotoxy(6, 14);
    cout << "3) Exit";
    cout << endl;
}

// Function to display game instructions
void instructions()
{
    cout << "***************************************************" << endl << endl;
    cout << "WELCOME TO BRICK BREAKER BY ABDULLAH AND RAZEEN" << endl << endl;
    cout << "***************************************************" << endl << endl;
    cout << "The INSTRUCTIONS of this game are very simple: " << endl << endl;
    cout << "You are ONLY allowed to use the left and right arrow keys, unless or otherwise prompted" << endl;
    cout << "You have to slide the paddle accordingly and position the ball, hitting as many bricks as you can" << endl;
    cout << "The more bricks you break, the more you score!" << endl;
    cout << "If the ball falls below the bottom boundary (beneath the paddle) you lose." << endl;
    cout << "To PAUSE/RESUME at any moment during the game, press the space bar key." << endl;
    cout << endl << endl;
    cout << "That is all. GOOD LUCK!!!" << endl << endl;
    cout << "***************************************************" << endl << endl;
    system("pause");
}

// Function to control the difficulty level of the game (Speed of ball varies in different levels)
int difficulty()
{
    while (1)
    {
        system("cls");
        borders();
        gotoxy(6, 12);
        cout << "1) Easy";
        gotoxy(6, 13);
        cout << "2) Medium";
        gotoxy(6, 14);
        cout << "3) Hard";
        gotoxy(6, 9);
        cout << "Select difficulty level: ";
        char input = _getche();
        switch (input)
        {
        case '1':
        {
            return 4;
        }
        case '2':
        {
            return 2;
        }
        case '3':
        {
            return 0;
        }
        default:
        {
            gotoxy(6, 10);
            cout << "INVALID Selection\a";
            Sleep(1000);
            continue;
        }
        }
    }
}

// Function to make the block of bricks disappear as the ball hits them
void breakbrick()
{
    for (int i = 0; i < 16; ++i)
    {
        if (Bricks_Array[i] == 0)
        {
            if (ballPos[0] >= bricks_Position[i][1] && ballPos[0] <= bricks_Position[i][1] + 7)
            {
                if (ballPos[1] == bricks_Position[i][0])
                {
                    Bricks_Array[i] = 1;
                    if (ballDirection == 2)
                    {
                        ballDirection = 3;

                    }
                    else if (ballDirection == 3)
                    {
                        ballDirection = 2;
                    }
                    if (ballDirection == 1)
                    {
                        ballDirection = 4;

                    }
                    else if (ballDirection == 4)
                    {
                        ballDirection = 1;
                    }
                    Beep(400, 500);
                    number_Of_Bricks--;
                    score++;
                }
            }
        }
    }
}

// The main function that controls all the actions performed during run-time
void play()
{
    int speed = difficulty();
    int a = 0;
    int pause = 0;
    while (1)
    {
        if (a < speed)
            ++a;
        else a = 0;

        system("cls");
        borders();
        gotoxy(paddlePos[0], paddlePos[1]);
        cout << "----------";
        gotoxy(ballPos[0], ballPos[1]);
        cout << '0';
        for (int i = 0; i < 16; ++i)
        {
            if (Bricks_Array[i] == 0)
            {
                gotoxy(bricks_Position[i][1], bricks_Position[i][0]);
                cout << "  |//|  " << endl;
            }
        }
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 'd' || ch == 'D' || ch == 77)
            {
                if (pause == 0)
                {
                    if (paddlePos[0] < 44)
                        paddlePos[0] = paddlePos[0] + 2;
                }
            }
            if (ch == 'a' || ch == 'A' || ch == 75)
            {
                if (pause == 0)
                {
                    if (paddlePos[0] > 2)
                        paddlePos[0] = paddlePos[0] - 2;
                }
            }
            if (ch == 27)
            {
                break;
            }
            if (ch == 32)
            {
                if (pause == 0)
                    pause = 1;
                else pause = 0;
            }
        }
        if (pause == 0)
        {
            if (ballDirection == 1 && a == 0)
            {
                ballPos[1] -= 1;
                ballPos[0] += 2;
                if (ballPos[0] > screenWidth - 2)
                    ballDirection = 2;
                if (ballPos[1] < 1)
                    ballDirection = 4;

            }
            else if (ballDirection == 2 && a == 0)
            {
                ballPos[1] -= 1;
                ballPos[0] -= 2;
                if (ballPos[1] < 1)
                    ballDirection = 3;
                if (ballPos[0] < 1)
                    ballDirection = 1;

            }
            else if (ballDirection == 3 && a == 0)
            {
                ballPos[1] += 1;
                ballPos[0] -= 2;
                if (ballPos[0] < 1)
                    ballDirection = 4;

            }
            else if (ballDirection == 4 && a == 0)
            {
                ballPos[1] += 1;
                ballPos[0] += 2;
                if (ballPos[0] > screenWidth)
                    ballDirection = 3;

            }
            if (ballPos[1] == paddlePos[1] - 1)
            {

                if (ballPos[0] >= paddlePos[0] && ballPos[0] <= paddlePos[0] + 10)
                {

                    if (ballDirection == 4)
                    {
                        ballDirection = 1;

                    }
                    else if (ballDirection == 3)
                    {
                        ballDirection = 2;

                    }
                }
            }

            breakbrick();

            if (ballPos[1] > screenHeight)
            {
                system("cls");
                borders();
                gotoxy(12, 7);
                cout << " ********************* ";
                gotoxy(12, 8);
                cout << " ||     YOU LOSE      || ";
                gotoxy(12, 9);
                cout << " ********************* ";

                for (int i = 0; i < 16; ++i)
                {
                    Bricks_Array[i] = 0;
                }
                ballDirection = 1;
                number_Of_Bricks = 16;
                paddlePos[0] = 22;
                paddlePos[1] = 18;
                ballPos[0] = 27;
                ballPos[1] = 17;
                gotoxy(6, 14);
                system("pause");
                break;
                
            }
            if (number_Of_Bricks == 0)
            {
                system("cls");
                gotoxy(12, 7);
                cout << " ********************* ";
                gotoxy(12, 8);
                cout << " ||     YOU WON      || ";
                gotoxy(12, 9);
                cout << " ********************* ";
                for (int i = 0; i < 16; ++i)
                {
                    Bricks_Array[i] = 0;
                }
                ballDirection = 1;
                number_Of_Bricks = 16;
                paddlePos[0] = 22;
                paddlePos[1] = 18;
                ballPos[0] = 27;
                ballPos[1] = 17;
                gotoxy(6, 14);
                system("pause");
                break;
                
            }

            out_File.open("score.txt", ios::out);
            out_File << "*********************" << endl;
            out_File << "CONGRAGULATIONS!!!" << endl;
            out_File << "Your score is: " << score << endl;
            out_File << "*********************" << endl;
        }

    }
}


int main()
{
    while (1)
    {
        system("cls");
        mainMenu();
        char optionSelect;
        gotoxy(6, 9);
        cout << "Select an option: ";
        optionSelect = _getche();

        switch (optionSelect)
        {
        case '1':
        {
            play();
            break;
        }
        case '2':
        {
            system("cls");
            instructions();
            break;
        }
        case '3':
        {
            char ask;
            gotoxy(6, 10);
            cout << "Are you sure you want to exit the game? (Y/N) " << endl;
            ask = _getche();
            if (ask == 'y' || ask == 'Y')
            {
                system("cls");
                borders();
                gotoxy(10, 9);
                cout << "Thank you for playing!";
                gotoxy(10, 10);
                cout << "We hope you liked our game :))";
                gotoxy(80, 25);
                exit(0);
            }
            else
            {
                continue;
            }
        }
        default:
        {
            gotoxy(6, 10);
            cout << "INVALID Selection!\a";
            Sleep(1000);
            continue;
        }
        }
        gotoxy(80, 25);
    }

    return 0;
    system("pause");
}

