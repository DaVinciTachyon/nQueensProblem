#include <stdio.h>
/*The objective of the program is to calculate the number of possible arrangements of n queens on a nxn chessboard,
so that the do not intersect each other on the horizontal axis, diagonal axes and vertical axis*/
/*Additional Requirements
1: Display the number of calculations required for the answer
  a: Full calculations
  b: the calculation until a certain point
2: Display the amount of time take for the calculations
  a: Full calculations (done)
  b: the calculation until a certain point
3: Program set up for batch processing
4: Set up a forcasting for number of calculations and timing for batch work
5: Parallelize the program*/

int calc //Performs the calculations, branching out for each possibility
(
  int n,                      //counter for number of iterations
  int numSquares,             //The length of the side of the board (not used for number of queens)
  int board[],                //The board horizontal positions
  int horizontalPos,          //tracking the horizontal position in the board
  unsigned long success   //The number of successful arrangements
)
{
  int verticalPos,      //Track the vertical position in the board
      verticalVar,      //Variation from a potential position for checking previous positions for queens
      posCheck,         //Position on the board being checked
      intersectFlag;    //flag for checking whether there is a queen intersecting a possible new position

  for(verticalPos = 0; verticalPos < numSquares; verticalPos++)
  {
    intersectFlag = 1;
    for(verticalVar = 1, posCheck = horizontalPos - 1; posCheck >= 0; posCheck--, verticalVar++)
    {
     if(board[posCheck] == verticalPos                ||
        board[posCheck] == verticalPos - verticalVar  ||
        board[posCheck] == verticalPos + verticalVar)
      intersectFlag = 0;
    }
    if(intersectFlag)
    {
      board[horizontalPos] = verticalPos;
      if(n == 0)
        success++;
      else
        success = n>0?calc
          (
            n - 1,
            numSquares,
            board,
            horizontalPos + 1,
            success
          ):0;
    }//end of if successful
  }//end of for loop
  return success;
}

int numSquaresFunc()
{
  int numSquares;
  printf("What would you like n to be? ");
  scanf("%d",&numSquares);
  return numSquares;
}

int main()
{
  int numSquares,
      horizontalPos;
  unsigned long success;

  numSquares = numSquaresFunc();

  int board[numSquares];

  horizontalPos = 0;
  success = 0;

  success = calc
    (
      numSquares - 1,
      numSquares,
      board,
      horizontalPos,
      success
    );

  printf("The number of arrangements of queens is %d\n", success);

  return 0;
}
