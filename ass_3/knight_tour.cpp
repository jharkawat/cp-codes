//c++ program to implement knight tour

#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct neighbor {
  // c = count, i = moves index
  int c, i;

  bool operator > (neighbor const& n) const {
    return c > n.c;
  }
};

int main()
{
	int n;
	cout<< "********************************************************************************"<< endl;
	cout<< "Enter the dimension of the chess board : ";
	cin >> n;

	// Chessboard first initialization
	vector<vector<int>> board (n, vector<int>(n, 0));

	// Knight's legal moves
	vector<vector<int>> moves = {
	{1, 2}, {2, 1}, {-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}
	};

	/*! Knight's move checker
	* I.S: -
	* F.S: Return true if the Knight could be moved to (x, y) point.
	*      Otherwise, false.
	*/
	function<bool(int, int)> moveable = [n](int x, int y) {
	return x > -1 && y > -1 && x < n && y < n;
	};
	 
	/*! Chessboard visits checker
	* I.S: -
	* F.S: Return true if the board at the (x, y) point has been visited.
	*      Otherwise, false.
	*/
	function<bool(int, int)> visited = [&board](int x, int y) {
	return board[x][y] > 0;
	};


	/*! Warnsdorff's rule implementation with Backtracking method
	* I.S: Blank state chessboard.
	* F.S: Return true if the Knight's tour could be performed.
	*      Otherwise, false. Chessboard has been filled out.
	*/
	function<bool(int, int, int)> tourable =
	[
	moves,
	n,
	&board,
	&moveable,
	&tourable,
	&visited
	](int x, int y, int p) {
	// Mark the chessboard
	board[x][y] = p;

	// Found a solution
	if (p == n * n) return true;

	// Min Heap for the available neighbors
	priority_queue<neighbor, vector<neighbor>, greater<neighbor>> heap;

	// Check all possible moves
	for (int i = 0; i < moves.size(); i++) {
	// Next moves
	int nx = x + moves[i][0];
	int ny = y + moves[i][1];

	if (moveable(nx, ny) && !visited(nx, ny)) {
	int count = 0;

	// Check all possible neighbors
	for (int j = 0; j < moves.size(); j++) {
	  int mx = nx + moves[j][0];
	  int my = ny + moves[j][1];

	  if (moveable(mx, my) && !visited(mx, my)) count++;
	}

	neighbor ne;
	ne.c = count;
	ne.i = i;

	heap.push(ne);
	}
	}

	// If there is at least one possible move exists
	if (heap.size() > 0) {
	neighbor ne = heap.top();
	int nx = moves[ne.i][0];
	int ny = moves[ne.i][1];

	if(tourable(x + nx, y + ny, p + 1)) return true;
	}

	// No solution
	return false;
	};

	/*! Common backtracking approach.
	* I.S: Blank state chessboard.
	* F.S: Return true if the Knight's tour could be performed.
	*      Otherwise, false. Chessboard has been filled out.
	*/
	function<bool(int, int, int)> tourable_2 =
	[
	n,
	moves,
	&board,
//	&isTimeout,
//	&limit,
	&moveable,
//	&start,
//	&toSecs,
	&tourable,
	&visited
	](int x, int y, int i) {
	if (i == (n * n)) return true;

//	if (isTimeout(start, limit)) return false;

	for (int k = 0; k < 8; k++) {
	int nx = x + moves[k][0];
	int ny = y + moves[k][1];

	if (moveable(nx, ny) && !visited(nx, ny)) {
	board[nx][ny] = i + 1;

	if (tourable(nx, ny, i + 1))
	  return true;
	else
	  board[nx][ny] = 0;
	}
	}

	return false;
	};

	/*! Chessboard printer
	* I.S: -
	* F.S: Print out the chessboard state with a pretty print format.
	*/
	function<void()> printBoard = [n, &board]() {
	int maxdigit = log10(n * n);

	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	int step = board[i][j];
	int digit = log10(step);

	for (int k = 0; k < maxdigit - digit; k++)
	  printf(" ");

	printf(" %d", step);

	if (j < n - 1) printf(" ");
	}

	printf("\n");
	}
	};

	/*! Chessboard initialization helper
	* I.S: Current chessboard state
	* F.S: Reset the chessboard and fill `0` on the each grid.
	*/
	function<void()> initializeBoard = [n, &board]() {
	vector<vector<int>> v (n, vector<int>(n, 0));

	board = v;
	};


	function<void()> findRandomSolution =
	[
	n,
	&initializeBoard,
	&printBoard,
//	&toSecs,
	&tourable
//	&start
	]() {
	srand(time(0));

	int x = rand() % n;
	int y = rand() % n;
	int tries = 0;

	printf(" Finding a random solution from the %dx%d chessboard.\n", n, n);
	printf("\n");

	while (!tourable(x, y, 1) && tries < n * n) {
	tries++;

	x = rand() % n;
	y = rand() % n;

	initializeBoard();
	}

	if (tries >= n * n)
	printf(" The solution doesn't exist.\n");
	else {
	printf(" Found a solution at starting point");
	printf(" (%d, %d).\n", x, y);
	printBoard();
	}

//	printf("\n");
//	printf(" Took about %.2f seconds", toSecs(start));
//	printf(" after %d", ++tries);

	if (tries < 2)
	printf(" try");
	else
	printf(" tries");

	printf(".\n");
	};

	function<void()> findRandomSolution_2 =
	[
	n,
//	limit,
	&board,
	&initializeBoard,
//	&isTimeout,
	&printBoard,
//	&start,
//	&toSecs,
	&tourable_2
	]() {
	srand(time(0));

	int x, y;
	int tries = 0;
	clock_t total = clock();

	printf(" Finding a random solution from the %dx%d chessboard.\n", n, n);
	printf("\n");

	do {
	tries++;
	x = rand() % n;
	y = rand() % n;

	initializeBoard();

//	start = clock();
	board[x][y] = 1;
	} while (!tourable_2(x, y, 1) && tries < n * n);

	if (tries >= n * n) {
//	if (isTimeout(start, limit))
//	printf(" Timeout for each possible solution.\n");
//	else
	printf(" The solution doesn't exist.\n");
	}
	else {
	printf(" Found a solution at starting point");
	printf(" (%d, %d).\n", x, y);
	printBoard();
	}

	printf("\n");
//	printf(" Took about %.2f seconds", toSecs(total));
	printf(" after %d", tries);

	if (tries < 2)
	printf(" try");
	else
	printf(" tries");

	printf(".\n");
	};

	int a;
	cout << "Which kind of algorithm you want to use for generating knight's tour:"<< endl;
	cout << "For Brute Force : 1"<<endl;
 	cout << "For Warnsdorff's rule : 2"<<endl;
 	cout << "For Polynomial time : 3"<<endl;

	cout << "Please Enter Your choice : ";
	cin >> a;
	
	if(a == 1)
	{
		findRandomSolution_2();
	}
	else if (a == 2)
	{
		findRandomSolution();
	}
	else if (a == 3 )
	{
		cout<<"Unable to code segmentation error was coming"<< endl;
	}
	else
	{
		cout<<"Wrong input run again"<< endl;
	}
	cout<<"********************************************************************************";
	return 0;
}
