/* Problem: Grid Colouring UVa 785
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Flood Fill
   Compiled: Visual C++ 7.0
   Date: 20-02-06
*/
#include <iostream>
#include <string>
using namespace std;

char str[2000], grid[2000][2000];
int rowLen, colLen;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfsVisit(int x, int y, char mark, char print){
	int r, c, i;
	
	for (i = 0; i < 4; ++i){
		r = x + dr[i];
		c = y + dc[i];
		if (r >= 0 && r < rowLen && c >= 0 && c < colLen && grid[r][c] == ' ' && grid[r][c] != mark ){
			grid[r][c] = print;
			dfsVisit(r, c, mark, print);
		}
	}
}

void dfs(){
	char mark, print;
	bool markFound;
	int i, j;
	
	markFound = false;
	for (i = 0; i < rowLen; ++i){
		colLen = strlen(grid[i]);
        for (j = 0; j < colLen; ++j){
			if (grid[i][j] != '_' && grid[i][j] != ' ' && !markFound){
				mark = grid[i][j];
				markFound = true;
			}
			if (markFound && grid[i][j] != mark && grid[i][j] != ' ' && grid[i][j] != '_'){
				print = grid[i][j];
				dfsVisit(i, j, mark, print);				
			}
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j, k, len;
	
	i = colLen = 0;
	while (cin.getline(str, sizeof(str))){
		if (str[0] == '_'){
			//output
			rowLen = i;
			dfs();
			for (j = 0; j < rowLen; ++j){
				colLen = strlen(grid[j]);
				for (k = 0; k < colLen; ++k)
					cout << grid[j][k];
				cout << endl;
			}
			cout << str << endl;
			i = colLen = 0;
			continue;
		}
		strcpy(grid[i], str);
		len = strlen(grid[i]);
		if (len > colLen)
			colLen = len;
		++i;
	}	


	return 0;
}
