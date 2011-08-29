/* Problem:  Word-Search Wonder   UVa 422
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Modified DFS
   Compiled: Visual C++ 7.0
   Date: 01-01-06
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char grid[500][500], temp[500];
int test, k, row, col;
int startX, startY, endX, endY;

bool dfsVisit(int x, int y, int a, int b){
	for (int j = k+1; j < strlen(temp); ++j){
		x = x + a;
		y = y + b;
		if ( (x >= 0 && x < row) && (y >= 0 && y <col)){
			if (grid[x][y] != temp[j])
				return false;
		}
		else if (x < 0 || y < 0 || x >= row || y >= col){
			return false;
		}
	}
	endX = x+1;
	endY = y+1;
	return true;
}

bool dfs(int x, int y){
	int i, dx, dy, j;
	bool found;

	k = 1;
	for (i = 0; i < 8; ++i){
		dx = x + dr[i];
		dy = y + dc[i];
		if ((dx >= 0 && dx < row) && (dy >= 0 && dy < col) && ( grid[dx][dy] == temp[k])){
			found = dfsVisit(dx, dy, dr[i], dc[i]);
			if (found)
				return true;
		}
	}
	return false;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j;
	bool result;
	
	while (cin >> test){
		cin.getline(temp, sizeof(temp)); // eat blank line
		if (test == 0) break;

		result = false;
		row = col = test;
		for (i = 0; i < test; ++i)
			cin.getline(grid[i], sizeof(grid[i]));

		while (cin.getline(temp, sizeof(temp))){
			if (temp[0] == '0') break;
	
			if (temp[0] > '0' && temp[0] <= '9'){
                sscanf(temp, "%d", &test);
				row = col = test;
				result = false;
				for (i = 0; i < test; ++i)
					cin.getline(grid[i], sizeof(grid[i]));
				continue;
			}

			k = 0;
			for (i = 0; i < row; ++i){
				for (j = 0; j < col; ++j){
					if(grid[i][j] == temp[k]){
						startX = i+1;
						startY = j+1;
						result = dfs(i, j);
						k = 0;
						if (result){
							cout << startX << "," << startY << " " << endX << "," << endY << endl;
							break;
						}
						
					}
				}		
				if (result) break;
			}
			if (result == false)
				cout << "Not found" << endl;
		}
	}

	return 0;
}
