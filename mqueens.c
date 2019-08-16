#include <stdio.h>
#define N 2/*Doesn't work yet*/
int main()
{
    /*int n;
    printf("What would you like n to be?\n\t");
    scanf("%d",&n);*/

    int a,b,i,j,x,y,m,
        counter,
        succ=0,
		board[N][N];
    for(a=0;a<N;a++)
    {
        for(b=0;b<N;b++)
        {
            for(x=0;x<N;x++)
            {
                for(y=0;y<N;y++)
                {
                    board[x][y] = 1;
                }
            }
            counter = 0;
            board[a][b] = 0;
            for(m=0;m<N;m++)
            {
                board[m][b]=0;
                board[a][m]=0;
                board[a-m][b+m]=0;
                board[a+m][b-m]=0;
                board[a+m][b+m]=0;
                board[a-m][b+m]=0;
            }
            counter++;
            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    if(board[i][j] == 1)
                    {
                        counter++;
                        for(m=0;m<N;m++)
                        {
                            board[i][j]=0;
                            board[m][j]=0;
                            board[i][m]=0;
                            board[i-m][j+m]=0;
                            board[i+m][j-m]=0;
                            board[i+m][j+m]=0;
                            board[i-m][j+m]=0;
                        }
                    }
                }
            }
            if(counter>=N) succ++;
        }
    }
    if(succ==1) printf("There is %d possible way\n",succ);
    else printf("There are %d possible ways\n",succ);

    return 0;
}
/*No Comment*/