#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void drawBoard() 
{
    cout << "    ������� �����:\n";
    cout << "  ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << "   " << i << "";
    }
    cout << "\n";

    for (int i = 0; i < SIZE; ++i) 
    {
        cout << " " << i << " ";
        for (int j = 0; j < SIZE; ++j) 
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "  ";
        for (int j = 0; j < SIZE; ++j) 
        {
            cout << " --- ";
        }
        cout << "\n";
    }
}

bool isValidMove(int row, int col) 
{
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

bool checkWin(char player)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }
    return false;
}

void computerMove() 
{
    int row, col;
    do
    {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isValidMove(row, col));
    board[row][col] = 'O';
}

int main()
{
    setlocale(LC_ALL, "ru");

    srand(static_cast<unsigned int>(time(0)));
    int moveCount = 0;
    char currentPlayer = 'X';

    while (true)
    {
        drawBoard();

        if (currentPlayer == 'X') 
        {
            int row, col;
            cout << "\n����� " << currentPlayer << ", ������� ���� ���������� (��� � �������, ������: 1 2): ";
            cin >> row >> col;
            cout << "\n |����� ������� �����| \n";

            if (isValidMove(row, col)) 
            {
                board[row][col] = currentPlayer;
                moveCount++;
                if (checkWin(currentPlayer)) 
                {
                    drawBoard();
                    cout << "\n�����������! ����� " << currentPlayer << " �������!\n";
                    break;
                }
                currentPlayer = 'O';
            }
            else 
            {
                cout << "���������������� ���! ���������� ��� ���.\n";
            }
        }
        else
        {
            cout << " |��� ����������...|\n";
            computerMove();
            moveCount++;
            if (checkWin(currentPlayer)) 
            {
                drawBoard();
                cout << "\n��������� �������!\n";
                break;
            }
            currentPlayer = 'X';
        }

        if (moveCount == SIZE * SIZE)
        {
            drawBoard();
            cout << "\n���� ����������� ������!\n";;
            break;
        }
    }

    return 0;
}
