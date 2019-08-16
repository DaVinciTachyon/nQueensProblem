#include <stdio.h>
#define N 2

int main()
{
  int board[N];
  int i, j, l, a, b,
      succ,
      flag;

  for(i = 0, succ = 0; i < N; i++)
  {
    board[0] = i;
    if(N == 1)
      succ++;
    else if(N > 1)
    {
      for(j = 0; j < N; j++)
      {
        for (a = 1, b = 0, flag = 0; b >= 0; b--, a++)
        {
          if(j - a >= 0)
          {
            if(board[b] == j || board[b] == j-a || board[b] == j+a)
              flag = 1;
          }
          else
          {
           if(board[b] == j || board[b] == j+a)
             flag = 1;
          }
        }
        if(flag == 0)
        {
          board[1] = j;
          if(N == 2)
            succ++;
          else if(N > 2)
          {
            for(l = 0; l < N; l++)
            {
              for (a = 1, b = 1, flag = 0; b >= 0; b--, a++)
              {
                if(l - a >= 0)
                {
                  if(board[b] == l || board[b] == l-a || board[b] == l+a)
                    flag = 1;
                }
                else
                {
                 if(board[b] == l || board[b] == l+a)
                   flag = 1;
                }
              }
              if(flag == 0)
              {
                board[2] = l;
                if(N == 3)
                  succ++;
              }//end of if(N > 2) is successful
            }//end of if(N > 2) for loop
          }//end of if(N > 2)
        }//end of if(N > 1) is successful
      }//end of if(N > 1) for loop
    }//end of if(N > 1)
  }//end of biggest for loop

  printf("The number of arrangements of queens is %d\n", succ);

  return 0;
}
