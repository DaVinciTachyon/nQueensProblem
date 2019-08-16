#include<stdio.h>
#define N 1

int queen(int, int, int, int);

int main()
{
    int board[N][N],
        counter,
        succ,
        res,
        x,
        y;
    counter = 0;
    succ = 0;
    for(x = 0; x < N; x++)
    {
        for(y = 0; y < N; y++)
        {
            board[x][y] = 1;
        }
    }
    res = queen(N, board[N][N], counter, succ);
    printf("There are %d possible ways.",res);
    return 0;
}

int queen(int n, int board[n][n], int counter, int succ)
{
    int a,
        b,
        m;
    for(a = 0; a < N; a++)
    {
        for(b = 0; b < N; b++)
        {
            counter = 0;
            if(board[a][b] == 1)
            {
                board[a][b] = 0;
                for(m = 0; m < N; m++)
                {
                    board[m][b] = 0;
                    board[a][m] = 0;
                    if(a-m>=0&&b+m<=n) board[a-m][b+m] = 0;
                    if(a+m<=n&&b-m>=0) board[a+m][b-m] = 0;
                    if(a+m<=n&&b+m<=n) board[a+m][b+m] = 0;
                    if(a-m>=0&&b-m>=0) board[a-m][b-m] = 0;
                }
                counter++;
                succ += n>0?queen(n-1, board[N][N], counter, succ):0;
                if(counter>=N) succ++;
            }
        }
    }
    return succ;
}

/*No Comment*/
