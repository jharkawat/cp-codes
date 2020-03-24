
struct Move {
	int x;
	int y;
	uint32_t index;
};

Move m;
using std::cout;
using std::endl;

/* Initialization of 8x8 board, fill the array with -1 */
void initboard() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			board[x][y] = -1;
		}
	}
}


/* Output the current board array */
void printboard(int arr[8][8]) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			cout << std::setw(2) << arr[x][y] << " ";
		}
		cout << endl;
	}
}

  bool constraints(int k, int b) {
	if ((k < 0) || (b < 0) || (k > 7) || (b > 7) ) {
		return true;
	}
	else {
		return false;
	}
}

bool empty(int k, int b) {
	if ((board[k][b] < 0) && !constraints(k,b)) {
		return true;
	}
	else {
		return false;
	}

}


int movesavailable(int a, int b) {
	int count = 0;
	for (int i = 0; i < 8; ++i) {
		if (empty(a, b) == true) {
			count++;
		}
	}
	return count;
}

bool heuristic(Move a) {

	int idx = -1;
	int deg = 9;
	int x, y, c;
	int select = rand() % 8;

	for (int i = 0; i < 8; ++i) {
		int k = (select + i) % 8;
		x = a.x + cx[k];
		y = a.y + cy[k];
		if ((empty(x, y) == true) && (c = movesavailable(x,y)) <  9) {
			idx = k;
			deg = c;
		}
	}

	if (idx == -1) {
		return false;
	}

	x = m.x + cx[idx];
	y = m.y + cy[idx];

	board[x][y] = board[m.x][m.y] + 1;
	printboard(board);

	m.x = x;
	m.y = y;

	return true;
}


bool onedeg(int x, int y, int xx, int yy)
{
	for (int i = 0; i < 8; ++i)
		if (((x + cx[i]) == xx) && ((y + cy[i]) == yy))
			return true;

	return false;
}

bool findpath() {

	for (int i = 0; i < 64 - 1; ++i)
		if (heuristic(m) == 0)
			return false;

	if (!onedeg(m.x, m.y, first.x, first.y))
		return false;

	printboard(board);
	return true;
}

int main()
{
	srand(time(0));

	int m1 = rand()%8;
	int m2 = rand()%8; //random 
	
	m.x = m1;
	m.y = m2;
	m.index = 0;
	
		
	initboard();
	board[m1][m2] = 1;
	
	

	while (!findpath()) {
		;
	}


	printboard(board);

	return 0;

}
