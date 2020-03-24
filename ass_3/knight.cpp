// C++ program to for Kinight's tour problem 

#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std;

// Move pattern on basis of the change of x coordinates and y coordinates respectively 
static int cx[] = {1,1,2,2,-1,-1,-2,-2}; 
static int cy[] = {2,-2,1,-1,2,-2,1,-1}; 

// function restricts the knight to remain within the 8x8 chessboard 
bool limits(int x, int y, int size ) 
{ 
    return ((x >= 0 && y >= 0) && (x < size && y < size)); 
} 

/* Checks whether a square is valid and empty or not */
bool isempty(int a[], int x, int y, int size) 
{ 
    return (limits(x, y, size)) && (a[y*(size)+x] < 0); 
} 

/* Returns the number of empty squares adjacent to (x, y) */
//warnsdorff specific
int getDegree(int a[], int x, int y, int size) 
{ 
    int count = 0; 
    for (int i = 0; i < size; ++i) 
        if (isempty(a, (x + cx[i]), (y + cy[i]), size)) 
            count++; 
  
    return count; 
} 

/* Picks next point using Warnsdorff's heuristic. Returns false if it is not possible to pick next point */ 
// Warnsdroff specific
bool nextMove(int a[], int *x, int *y, int size) 
{ 
    int min_deg_idx = -1, c, min_deg = (9), nx, ny; 
  
    // Try all 8 adjacent of (*x, *y) starting 
    // from a random adjacent. Find the adjacent 
    // with minimum degree. 
    int start = rand()%size; 
    for (int count = 0; count < 8; ++count) 
    { 
        int i = (start + count)%8; 
        nx = *x + cx[i]; 
        ny = *y + cy[i]; 
        if ((isempty(a, nx, ny, size)) && 
           (c = getDegree(a, nx, ny, size)) < min_deg) 
        { 
            min_deg_idx = i; 
            min_deg = c; 
        } 
    } 
  
    // IF we could not find a next cell 
    if (min_deg_idx == -1) 
        return false; 
  
    // Store coordinates of next point 
    nx = *x + cx[min_deg_idx]; 
    ny = *y + cy[min_deg_idx]; 
  
    // Mark next move 
    a[ny*size + nx] = a[(*y)*size + (*x)]+1; 
  
    // Update next point 
    *x = nx; 
    *y = ny; 
  
    return true; 
}

/* displays the chessboard with all the legal knight's moves */
void print(int a[], int size) 
{ 
    for (int i = 0; i < size; ++i) 
    { 
        for (int j = 0; j < size; ++j) 
            printf("%d\t",a[j*size+i]); 
        printf("\n"); 
    } 
} 

/* checks its neighbouring sqaures */
/* If the knight ends on a square that is one 
   knight's move from the beginning square, 
   then tour is closed */
bool neighbour(int x, int y, int xx, int yy, int size) 
{ 
    for (int i = 0; i < 8; ++i) 
        if (((x+cx[i]) == xx)&&((y + cy[i]) == yy)) 
            return true; 
  
    return false; 
} 

/* Generates the legal moves using warnsdorff's 
  heuristics. Returns false if not possible */
bool findClosedTour(int size) 
{ 
    // Filling up the chessboard matrix with -1's 
    int a[(size)*(size)]; 
    for (int i = 0; i< (size)*(size); ++i) 
        a[i] = -1; 
  
    // Randome initial position 
    int sx = rand() % size; 
    int sy = rand() % size; 
  
    // Current points are same as initial points 
    int x = sx, y = sy; 
    a[y*size+x] = 1; // Mark first move. 
  
    // Keep picking next points using 
    // Warnsdorff's heuristic 
    for (int i = 0; i < (size)*(size)-1; ++i) 
        if (nextMove(a, &x, &y, size) == true ) 
            return false; 
  
    // Check if tour is closed (Can end 
    // at starting point) 
    if (!neighbour(x, y, sx, sy,size)) 
        return false; 
  
    print(a, size); 
    return true; 
} 
  
int main ()
{	
	int n;
	cout<< "Enter the dimension of the chess board : ";
	cin >> n ;
	// To make sure that different random 
	// initial positions are picked. 
	srand(time(NULL)); 
  
	// While we don't get a solution 
	while (!findClosedTour(n)) 
	{ 
	; 
	} 
  
	return 0;

}
