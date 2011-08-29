/* Problem:   Knight Moves UVa 439
   Programmer: Md. Mahmud Ahsan
   Description: Graph + BFS
   Compiled: Visual C++ 7.0
   Date: 02-01-06
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MX = 100;
const int INF = 999999;
char graph[MX][MX];
char color[MX][MX];
char id[] = {'a','b','c','d','e','f','g','h'}; 
int dist[MX][MX];

int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};

void init(){
	for (int i = 0; i < MX; ++i){
		for (int j = 0; j < MX; ++j)
			graph[i][j] = '1';
	}
}

int getId(char c){
	for (int i = 0; i < 8; ++i)
		if (id[i] == c) return i;
	
	//never executed last return
	return 0;
}


int bfs(int fromCol, int fromRow, int toCol, int toRow){
	int i, j, cl, ro, r, c;
	for (i = 0; i < 8; ++i){
		for (j = 0; j < 8; ++j){
			color[i][j] = 'w';
			dist[i][j] = INF;
		}
	}
	color[fromRow][fromCol] = 'g';
	dist[fromRow][fromCol] = 0;
	queue <int> col;
	queue <int> row;

	col.push(fromCol);
	row.push(fromRow);

	while (!col.empty()){
		cl = col.front(); col.pop();
		ro = row.front(); row.pop();

		for (int i = 0; i < 8; ++i){
			r = ro + dr[i];
			c = cl + dc[i];
			
			if (r >= 0 && r < 8 && c >= 0 && c < 8){
				if (color[r][c] == 'w'){
					color[r][c] = 'g';
					dist[r][c] = dist[ro][cl] + 1;
					row.push(r);
					col.push(c);
				}
			}				
		}
		color[ro][cl] = 'b';
	}
	return dist[toRow][toCol];
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j, final;
	char a, b;
	int _a, _b;
	string from, to;
	
	while (cin >> from >> to){
		init();
		a = from[0];
		_a = from[1]-48;
		b = to[0];
		_b = to[1]-48;

		//as array index start with 0
		_a = _a-1;
		_b = _b-1; 

		final = bfs(getId(a), _a, getId(b), _b);
		cout << "To get from " << from << " to " << to << " takes " << final << " knight moves." << endl;
	}

	return 0;
}
