#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char PLAYER2 = 'O';

void reset_board();
void print_board();
int check_free_spaces();
void player_move();
void player2_move();
char check_winner();
void print_winner(char winner);


int main()
{
    char winner = ' ';
    reset_board();
    while(winner == ' ' && check_free_spaces() != 0)
    {
        print_board();
        player_move();
        winner = check_winner();
        if (winner != ' ' || check_free_spaces() == 0)
        {
            break;
        }
        print_board();
        player2_move();
        winner = check_winner();
        if (winner != ' ' || check_free_spaces() == 0)
        {
            break;
        }
    }
    print_board();
    print_winner(winner);
    return (0);
}
void reset_board()
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void print_board()
{
    printf("   1   2   3\n");
    printf("1  %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n  ---|---|---\n");
    printf("2  %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n  ---|---|---\n");
    printf("3  %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int check_free_spaces()
{
    int free_spaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                free_spaces--;
            }
        }
    }

    return (free_spaces);
}
void player_move()
{
    int x, y;
    printf("Player 1 turn\n");
    do
    {
        printf("Enter row number from 1 to 3: ");
        scanf("%d", &x);
        x--;

        printf("Enter column number from 1 to 3: ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
            printf("This cell is occupied!\n");
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while(board[x][y] != ' ');
}

void player2_move()
{
    int x, y;
    printf("Player 2 turn\n");
    do
    {
        printf("Enter row number from 1 to 3: ");
        scanf("%d", &x);
        x--;

        printf("Enter column number from 1 to 3: ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
            printf("This cell is occupied!\n");
        else
        {
            board[x][y] = PLAYER2;
            break;
        }
    }
    while(board[x][y] != ' ');
}
char check_winner()
{
    //row check
    for(int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //column check
    for(int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //diagonal check
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return (' ');
}
void print_winner(char winner)
{
    if (winner == 'X')
        printf ("\nPlayer 1 won!\n");
    if (winner == 'O')
        printf ("\nPlayer 2 won!\n");
    if (winner == ' ') 
        printf("\nDraw!\n");
}
