#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//9 boxes labeled from top to bottom, left to right:
//0,0 0,1 0,2 1,0 1,1 1,2 2,0 2,1 2,2

char board[3][3] = { {'1', '2', '3'},{'4','5','6'},{'7','8','9'} };

char current_marker;
int current_player;

void resetBoard()
{
    char num = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = num++;
        }
    }
}

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

}

bool placeMarker(int slot, char marker)
{
    int row = (slot-1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = marker;
        return true;
    }
    return false;
}

char checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    return ' ';
}

char winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { return current_player; }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) { return current_player; }

    return 0;
   
}

void swap_player_and_marker()
{
    if (current_marker == 'X') { current_marker = 'O'; }
    else current_marker = 'X';

    if (current_player == 1) { current_player = 2; }
    else current_player = 1;
}

int getComputerMove(char computer_marker)
{
    int slot;
    do {
        slot = rand() % 9 + 1;
    } while (!placeMarker(slot,computer_marker));
    return slot;
}

void singlePlayerGame()
{
    resetBoard();

    cout << "Choose your marker (X or O): ";
    char player_marker;
    cin >> player_marker;

    char computer_marker = (player_marker == 'X') ? 'O' : 'X';

    drawBoard();

    for (int i = 0; i < 9; i++)
    {
        int slot;
        if (i%2==0)
        {
            cout << "Your turn. Enter your slot: ";
            cin >> slot;

            if (slot < 1 || slot>9 || !placeMarker(slot, player_marker))
            {
                cout << "Invalid move! Try again.\n";
                i--;
                continue;
            }
        }
        else
        {
            cout << "Computer's turn...\n";
            slot = getComputerMove(computer_marker);
            cout << "Computer chose slot " << slot << "\n";
        }

        drawBoard();
        char winner = checkWinner();

        if (winner == player_marker)
        {
            cout << "You win! Congratulations!\n";
            return;
        }
        else if (winner == computer_marker)
        {
            cout << "Computer wins! Better luck next time.\n";
            return;
        }
        

    }
    cout << "It's a tie!\n";
}

void game()
{
    resetBoard();
    cout << "Player one, choose your marker: ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;
    drawBoard();
    int player_won;
    for (int i = 0; i < 9; i++)
    {
        cout << "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot< 1 || slot > 9)
        {
            cout << "That slot is invalid! Try another slot numbers 1-9: ";
            i--;
            continue;
        }

        if (!placeMarker(slot,current_marker))
        {
            cout << "That slot is occupied! Try another slot."; 
            i--;
            continue;
        }

        drawBoard();

        player_won = winner();
        if (player_won == 1)
        {
            cout << "Player one won! Congratulations!"; 
            break;
        }
        if (player_won == 2)
        {
            cout << "Player two won! Congratulations!";
            break;
        }

        swap_player_and_marker();
    }
    if (player_won == 0)
    {
        cout << "That is a tie game!";
    }
}
int main()
{
    srand(time(NULL));
    int choice;

    do 
    {
        cout << "\nTic-Tac-Toe Menu: \n";
        cout << "1. Single Player\n";
        cout << "2. Two Player\n";
        cout << "3. Exit\n";
        cout << "Enter Selection: ";
        cin >> choice;

        if (choice == 1)
        {
            singlePlayerGame();
        }

        if (choice == 2)
        {
            game();
        }

        if (choice == 3)
        {
            return 0;
        }
    } while (choice != 3);
}