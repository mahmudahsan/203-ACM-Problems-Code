/* Problem: Wetlands of Florida UVa 469
   Programmer: Md. Mahmud Ahsan
   Description: DFS
   Compiled: Visual C++ 7.0
   Date: 08-12-05
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//global declaration
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int N, row, col;
char grid[105][105];
char tempGrid[105][105];

int dfs(int x, int y){
	int dx, dy, i, total = 1;
	
	grid[x][y] = '2'; // 2 for gray
	for (i = 0; i < 8; ++i){
		dx = dr[i] + x;
		dy = dc[i] + y;
		if ((dx >=0 && dx < row) && (dy >= 0 && dy < col)){
			if (grid[dx][dy] == 'W'){
				total += dfs(dx, dy);
			}
		}
	}
	grid[x][y] = '3'; // 3 for black
	return total;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, x, y, j,flag = 1, total;
	char temp[120];
	cin >> N;
	cin.getline(temp, sizeof(temp)); // eat new line
	cin.getline(temp, sizeof(temp)); // eat blank line

	while (N--){		
		i = 0;
		if (flag == 0) cout << endl; flag = 0;

		while(cin.getline(temp, sizeof(temp))){
			if (strlen(temp) == 0) break;
			if (temp[0] >= 'A' && temp[0] <= 'Z'){
				strcpy(grid[i], temp);
				strcpy(tempGrid[i], temp);
				++i;
				continue;
			}
			col = strlen(grid[0]);
			row = i; 
			sscanf(temp, "%d%d", &x, &y);
			--x;
			--y;
			if (grid[x][y] == 'W'){
				total = dfs(x, y);
			}
			else{
				cout << "0" << endl;
				continue;
			}
			cout << total << endl;
			//rebuild the grid again
			for (i = 0; i < row; ++i)
				strcpy(grid[i], tempGrid[i]);
		};		
	}
	return 0;
}