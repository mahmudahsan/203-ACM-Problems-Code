/* Problem: Minesweeper  UVa 10189 PC 110102
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++  Visual C++ 6.0
   Date: 12-09-04
*/ 

#include <iostream>
using namespace std;

namespace board{
	int row; 
	int col;
	int dr[8] = {-1, -1, -1,  0, +1, +1, +1,  0};
	int dc[8] = {-1,  0, +1, +1, +1,  0, -1, -1};
	char grid[120][120];	
}

// prototypes
bool chkValid(int, int);
int setValue(int, int);

//=========================================================================
int main(){
	int i, j;
	int m, n;
	static int field, flag;
	field = flag = 0;

	while (cin >> m >> n){
		if (m == 0 && n == 0)	break;
		board :: row = m;
		board :: col = n;
		
		// flag for the middle new line
		if (flag == 1)
			cout << endl;
		
		// take input
		for (i = 0; i < board :: row; i++){
			for (j = 0; j < board :: col; j++)
				cin >> board :: grid[i][j];
		}
		
		// set value for the [.]
		for (i = 0; i < board :: row; i++){
			for (j = 0; j < board :: col; j++){
				if (board :: grid[i][j] == '*')
					continue;
				else
					board :: grid[i][j] = setValue(i, j);
			}
		}
		
		cout << "Field #" << ++field << ":" << endl;
		for (i = 0; i < board :: row; i++){
			for (j = 0; j < board :: col; j++)	
				cout << board :: grid[i][j];
			cout << endl;
		}
		flag = 1;
	}
	return 0;
}
//=========================================================================
// is 8 direction is the correct position
bool chkValid(int r, int c){
	if (r < 0 || r >= board :: row || c < 0 || c >= board :: col)
		return false;
	return true;
}

int setValue(int r, int c){
	int count, nr, nc, i;
	count = 0;
	
	for (i = 0; i < 8; i++){
		// nr and nc used for 8 direction around a point
		nr = r + board :: dr[i];
		nc = c + board :: dc[i];
		if ( chkValid(nr, nc) &&  board :: grid[nr][nc] == '*')
			count++;
	}
	return count + 48; // as it will convert digit to char 
}