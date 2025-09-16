#include <iostream>
using namespace std;

//9 boxes labeled from top to bottom, left to right:
//0,0 0,1 0,2 1,0 1,1 1,2 2,0 2,1 2,2

char board[3][3] = {{'1', '2', '3'},{'4','5','6'},{'7','8','9'}};

void drawBoard()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"------------------\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"------------------\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

}
int main()
{
    drawBoard();
}
