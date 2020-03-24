#include <iostream>
using std::cout;
using std::cin;

#include <ctime>

#include <cstdlib>

void testmove( int [][8], int [][3][64],int [][8], int );
void findleast( int [][3][64],int, bool&, int);

int main()
{
	
//	cout << "Please enter starting square x vlaue then y vlaue: ";
//	cin >> i >> j;

	//start in top tight corner

	int i=0; 
	int j=0;

	const int size =8;
	
	int board[size][size] = {0};
	int moves[size][3][64] = {0};
	bool test= 0;  // used to test whether there are muliple least accessibe squares
	int counter=0;

	board[i][j] = 1;
	moves[counter][0][0]=board[i][j];
	moves[counter][0][1]= i;
	moves[counter][0][2]= j;


int access[8][8] = {2,3,4,4,4,4,3,2,
				   3,4,6,6,6,6,4,3,
				   4,6,8,8,8,8,6,4,
				   4,6,8,8,8,8,6,4,
				   4,6,8,8,8,8,6,4,
				   4,6,8,8,8,8,6,4,
				   3,4,6,6,6,6,4,3,
				   2,3,4,4,4,4,3,2,};

					
		do {
			testmove( access, moves, board, counter);	
			counter++;
			findleast( moves, size, test, counter );
			
		} while ( test == 1);

return 0;
}


void testmove( int access[][8],int moves[][3][64],int board[][8], int counter)
{
	const int horizontal[8] ={2,1,-1,-2,-2,-1,1,2};
	const int vertical[8] = {-1,-2,-2,-1,1,2,2,1};
	
	for ( int k = 0; k < 8; k++)
	{if ( moves[counter][k][1]+ horizontal[k] < 0 || moves[counter][k][1] + horizontal[k] > 7 )
			continue;
		if ( moves[counter][k][2]+ vertical[k] < 0 || moves[counter][k][2] + vertical[k] > 7 )
			continue;
			if (board[moves[counter][k][1]+ horizontal[k]][moves[counter][k][2] + vertical[k]] =! 0)
				continue;
	
		moves[counter+1][k][0]= access[moves[counter][k][1]+horizontal[k]][moves[counter][k][2]+vertical[k]];
		moves[counter+1][k][1]= moves[counter][k][1]+horizontal[k];
		moves[counter+1][k][2]= moves[counter][k][2]+vertical[k];
	}
	
}


	
void findleast ( int moves[][3][64], int size, bool& test, int counter)
{
	int least=9;
	
	
	for ( int k =0; k < size; k++)
		if ( moves[counter][k][0] < least	)
			least = moves[counter][k][0];
	
	int sort = 0;

	for (int k = 0; k < size; k++)
	{if ( moves[counter][k][0] == least )
	{ if (k == sort)
			{continue;}
			 else
			 {moves[counter][sort][0] = moves[counter][k][0];
			  moves[counter][sort][1] = moves[counter][k][1];
			  moves[counter][sort][2] = moves[counter][k][2];
			  sort++;
			  if (sort > 1)
			  test=1;}
	}
	moves[counter][k][0] = 0;
	moves[counter][k][1] = 0;
	moves[counter][k][2] = 0;
	}
}
