/* Problem: Robot Motion UVa 10116
   Programmer: Md. Mahmud Ahsan
   Description: Graph
   Compiled: Visual C++ 7.0
   Date: 17-08-06
*/
#include <iostream>
#include <string>
using namespace std;

const int MX = 100;
char grid[MX][MX];
int gridValue[MX][MX];

void init(int row, int col){
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			gridValue[i][j] = -1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int row, col, pos;
	int a, b, path, exit, b4Loop;
	char ch;
	bool found;

	while (cin >> row >> col >> pos){
		if (!row && !col && !pos) break;
		
		for (int i = 0; i < row; ++i)
			cin >> grid[i];
		
		init(row, col);
		found = false;
		a = 0;
		b = --pos;
		path = 0;

		while (true){
			ch = grid[a][b];
			gridValue[a][b] = path++;
			
			switch (ch){
				case 'N': --a; break;
				case 'S': ++a; break;
				case 'E': ++b; break;
				case 'W': --b; break;
			}
			if (a < 0 || a >= row || b < 0 || b >= col){
				found = true;
				exit = path;
				break;
			}
			else if (gridValue[a][b] != -1){
				found = false;
				exit = path - gridValue[a][b];
				b4Loop = gridValue[a][b];
				break;
			}
		}
		if (found)
			cout << exit << " step(s) to exit" << endl;
		else
			cout << b4Loop << " step(s) before a loop of " << exit << " step(s)" << endl;
	}

	return 0;
}
