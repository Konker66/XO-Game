#include <iostream>
using namespace std;

char Matrix[3][3] = {{'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'}};
char Player = 'X';

void Draw()
{

    cout << "-----------------" << endl;
    for (int r = 0; r < 3; r++)
    {
        cout << "|   ";
        for (int c = 0; c < 3; c++)
        {
            cout << Matrix[r][c] << "   ";
        }
        cout << "|" << endl;
    }
    cout << "-----------------" << endl;
}

void Replace()
{
    int pos;
    cout << "Enter your position (" << Player << ") : ";
    cin >> pos;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Matrix[r][c] == char(pos + '0'))
            {
                Matrix[r][c] = Player;
            }
        }
    }
}

bool CheckWin()
{
    // Check rows for a win
    for (int r = 0; r < 3; r++)
    {
        if (Matrix[r][0] == Matrix[r][1] && Matrix[r][1] == Matrix[r][2])
        {
            return true;
        }
    }

    // Check columns for a win
    for (int c = 0; c < 3; c++)
    {
        if (Matrix[0][c] == Matrix[1][c] && Matrix[1][c] == Matrix[2][c])
        {
            return true;
        }
    }

    // Check diagonals for a win
    if (Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2])
    {
        return true;
    }
    if (Matrix[0][2] == Matrix[1][1] && Matrix[1][1] == Matrix[2][0])
    {
        return true;
    }

    // No winner found
    return false;
}

void Reset()
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            Matrix[r][c] = char((r * 3) + c + '1');
        }
    }
    Player = 'X';
}

int main()
{
    bool playAgain = true;
    while (playAgain)
    {
        Reset();
        while (true)
        {
            Draw();
            Replace();
            if (CheckWin())
            {
                Draw(); // draw the board one final time
                cout << "Player " << Player << " wins!" << endl;
                break;
            }
            if (Matrix[0][0] != '1' && Matrix[0][1] != '2' && Matrix[0][2] != '3' &&
                Matrix[1][0] != '4' && Matrix[1][1] != '5' && Matrix[1][2] != '6' &&
                Matrix[2][0] != '7' && Matrix[2][1] != '8' && Matrix[2][2] != '9')
            {
                Draw(); // draw the board one final time
                cout << "Tie game!" << endl;
                break;
            }
            if (Player == 'X')
            {
                Player = 'O';
            }
            else
            {
                Player = 'X';
            }
        }
        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }
    return 0;
}