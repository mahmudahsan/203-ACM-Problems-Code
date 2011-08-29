/* Problem: Where's Woldorf UVa 10010
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Modified DFS
   Compiled: Visual C++ 7.0
   Date: 08-12-05
*/
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char grid[100][100], temp[200];
int test, row, col, query, k;

bool dfsVisit(int x, int y, int a, int b){
	for (int j = k+1; j < strlen(temp); ++j){
		x = x + a;
		y = y + b;
		if ( (x >= 0 && x < row) && (y >= 0 && y <col)){
			if (tolower(grid[x][y]) != tolower(temp[j]))
				return false;
		}
		else if (x < 0 || y < 0 || x >= row || y >= col){
			return false;
		}
	}
	return true;
}

bool dfs(int x, int y){
	int i, dx, dy, j;
	bool found;

	k = 1;
	for (i = 0; i < 8; ++i){
		dx = x + dr[i];
		dy = y + dc[i];
		if ((dx >= 0 && dx < row) && (dy >= 0 && dy < col) && ( tolower(grid[dx][dy]) == tolower(temp[k]))){
			found = dfsVisit(dx, dy, dr[i], dc[i]);
			if (found) return true;
		}
	}
	return false;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j;
	bool result, newLine = false;
	cin >> test;
	
	while (test--){
		cin >> row >> col;
		cin.getline(temp, sizeof(temp)); // eat new line

		for (i = 0; i < row; ++i){
			cin.getline(temp, sizeof(temp));
			strcpy(grid[i], temp);
		}
		if (newLine) cout << endl; newLine = true;

		cin >> query;
		cin.getline(temp, sizeof(temp));
		while (query--){
			cin.getline(temp, sizeof(temp));
			
			k = 0;
			result = false;
			for (i = 0; i < row; ++i){
				for (j = 0; j < col; ++j){
					if(tolower(grid[i][j]) == tolower(temp[k])){
						result = dfs(i, j);
						k = 0;
						if (result){
							cout << ++i << " " << ++j << endl;
							break;
						}
					}
				}
				if (result) break;
			}
		}
	}

	return 0;
}