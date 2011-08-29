/* Problem: Minesweeper  UVa 10189 PC 110102
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++  Visual C++ 6.0
   Date: 23-07-04
*/ 

#include <iostream>
using namespace std;

// typedef
typedef struct{
	int m;
	int n;
	char grid[105][105];
}field;

// prototypes
void show(field, int);

//===============================================================
int main(){
	int m, n, fieldcount = 0; 
	int i, j; 			// for loop counter
	field board;	 // declare a board
	
	// enter the board
	while (cin >> m >> n){
		if (m == 0 && n == 0) break;	// terminate the program
			
		board.m = m;
		board.n = n;
		// initialize the board
		for (i = 0; i < m; i++){  	
			for (j = 0; j < n; j++){
				cin >> board.grid[i][j];
				if (board.grid[i][j] == '.') board.grid[i][j] = '0';
			}
		}
		
		// parse and generate the hints
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				if (board.grid[i][j] == '*'){
					// generate the range
					for (int p = i - 1; p <= i + 1; p++){
						for (int q = j - 1; q <= j + 1; q++){
							if ((p >= 0) && (p <= m) && (q >= 0) && (q <= n)){
								if (board.grid[p][q] != '*'){
									board.grid[p][q] += 1;
								}
							}
						}
					}
				}
			}
		}
		
		// increase the field
		++fieldcount;
		
		// show the board
		show (board, fieldcount);
	} // end the while loop
	return 0;
}
//====================================================================

void show(field board, int count){
	// show the m * n matrix of the board
	int i, j;
	
	cout << endl << "Field #" << count << ":" << endl;
	for (i = 0; i < board.m; i++){
		for (j = 0; j < board.n; j++){
			cout << board.grid[i][j];
		}
		cout << endl;
	}
}
	