#include <stdbool.h>
#include <stdio.h>
#define N 10
int prev_col[N] = {0};
int count = 0; // to keep track of number of solutions
void printSolution(int board[][N], int n)
{
    printf("Solution %d:\n", ++count);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[][N], int n, int row, int col)
{
    int i, j;
    if (prev_col[col])
        return false;
        
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; i >= 0 && j < n; j++, i--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQUtil(int board[][N], int n, int row)
{
    if (row >= n)
    {
        printSolution(board, n);
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, n, row, i))
        {
            board[row][i] = 1;
            prev_col[i] = 1;
            res = solveNQUtil(board, n, row + 1) || res;
            prev_col[i] = 0;
            board[row][i] = 0; // backtrack
        }
    }
    return res;
}
bool solveNQ(int n)
{
    int board[N][N] = {{0}};
    count = 0;
    return solveNQUtil(board, n, 0);
}
int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    if (!solveNQ(n))
    {
        printf("Solution does not exist");
    }
    return 0;
}
