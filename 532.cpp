/* Problem: Dungeon Master  UVa 532
   Programmer: Md. Mahmud Ahsan
   Description: 3d BFS
   Compiled: Visual C++ 7.0
   Date: 12-09-06
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int INF = 1 << 28;
const int MX = 50;

char graph[MX][MX][MX];
int dist[MX][MX][MX];
char color[MX][MX][MX];

int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
int dl[] = {0, 0, 0, 0, 1, -1};

int l, r, c;
int startL, startR, startC;
int endL, endR, endC;

void bfs(){
	int i, j, k, _l, _r, _c;
	int level, row, col;

	for (i = 0; i < l; ++i){
		for (j = 0; j < r; ++j){
			for (k = 0; k < c; ++k){
				dist[i][j][k] = INF;
				color[i][j][k] = 'w';
			}
		}
	}

	color[startL][startR][startC] = 'g';
	dist[startL][startR][startC] = 0;

	queue <int> q;
	q.push(startL);
	q.push(startR);
	q.push(startC);

	while (!q.empty()){
		_l = q.front(); q.pop();
		_r = q.front(); q.pop();
		_c = q.front(); q.pop();

		for (j = 0; j < 6; ++j){
			level = _l + dl[j];
			row = _r + dr[j];
			col = _c + dc[j];

			if (level >= 0 && level < l && row >= 0 && row < r && col >= 0 && col < c){
				if (color[level][row][col] == 'w' && (graph[level][row][col] == '.' || graph[level][row][col] == 'E')){
					
					color[level][row][col] = 'g';
					dist[level][row][col] = dist[_l][_r][_c] + 1;
						
					q.push(level);
					q.push(row);
					q.push(col);
				}
			}
		}
		
		color[_l][_r][_c] = 'b';
	}
	
}

int main(){
	//freopen("input.txt", "r", stdin);
	
	while (cin >> l >> r >> c){
		if (!l && !r && !c) break;
		
		for (int i = 0; i < l; ++i){
			for (int j = 0; j < r; ++j){
				for (int k = 0; k < c; ++k){
					cin >> graph[i][j][k];
					if (graph[i][j][k] == 'S'){
						startL = i;
						startR = j;
						startC = k;
					}
					if (graph[i][j][k] == 'E'){
						endL = i;
						endR = j;
						endC = k;
					}
				}
			}
		}
		bfs();
		if (dist[endL][endR][endC] == INF)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << dist[endL][endR][endC] << " minute(s)." << endl;


	}	

	return 0;
}
