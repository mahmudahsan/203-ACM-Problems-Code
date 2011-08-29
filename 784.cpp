/* Problem: Maze Exploration UVa 784
   Programmer: Md. Mahmud Ahsan
   Description: Graph + DFS
   Compiled: Visual C++ 7.0
   Date: 08-12-05
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char grid[100][100];
int rowLimit, colLimit;

void dfs(int x, int y){
	int dx, dy, i;
	for (i = 0; i < 8; ++i){
		dx = x + dr[i];
		dy = y + dc[i];

		colLimit = strlen(grid[x]);
		if ((dx >= 0 && dx < rowLimit) && (dy >= 0 && dy < colLimit)){
			if (grid[dx][dy] == ' '){
				grid[dx][dy] = '#';
				dfs(dx, dy);
			}
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	char temp[100];
	int N, i, j, row, col;
	cin >> N;
	cin.getline(temp, sizeof(temp)); // eat new line 

	while (N--){
		i = -1;
		while (cin.getline(temp, sizeof(temp))){
			if (temp[0] == '_') break;
			
			strcpy(grid[++i], temp);
			for (j = 0; temp[j]; ++j){ //search for '*' 's location
				if (temp[j] == '*'){
					row = i;
					col = j;
					grid[row][col] = '#';
				}
			}
		}
		rowLimit = i+1; 
		dfs(row, col);
		
		//output
		for (i = 0; i < rowLimit; ++i){
			col = strlen(grid[i]);
			for (j = 0; j < col; ++j)
				cout << grid[i][j];
			cout << endl;
		}
		cout << temp << endl;
	}
	return 0;
}