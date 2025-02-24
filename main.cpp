#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void drawBoard() 
{
    cout << "    Текущая доска:\n";
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
            cout << "\nИгрок " << currentPlayer << ", введите ваши координаты (ряд и колонка, пример: 1 2): ";
            cin >> row >> col;
            cout << "\n |Новый игровой раунд| \n";

            if (isValidMove(row, col)) 
            {
                board[row][col] = currentPlayer;
                moveCount++;
                if (checkWin(currentPlayer)) 
                {
                    drawBoard();
                    cout << "\nПоздравляем! Игрок " << currentPlayer << " выиграл!\n";
                    break;
                }
                currentPlayer = 'O';
            }
            else 
            {
                cout << "Недействительный ход! Попробуйте еще раз.\n";
            }
        }
        else
        {
            cout << " |Ход компьютера...|\n";
            computerMove();
            moveCount++;
            if (checkWin(currentPlayer)) 
            {
                drawBoard();
                cout << "\nКомпьютер выиграл!\n";
                break;
            }
            currentPlayer = 'X';
        }

        if (moveCount == SIZE * SIZE)
        {
            drawBoard();
            cout << "\nИгра завершилась ничьей!\n";;
            break;
        }
    }

    return 0;
}
