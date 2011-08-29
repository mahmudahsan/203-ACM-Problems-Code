/* Problem:  Il Gioco dell'X   UVa 260
   Programmer: Md. Mahmud Ahsan
   Description: Graph + DFS
   Compiled: Visual C++ 7.0
   Date: 14-02-06
*/

#include <iostream>
#include <string>
using namespace std;

const int MX = 500;

int n;
string graph[MX];

int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 0, -1, 1, 0, 1};

void dfsVisit(int u, int v, char ch, char replac){
	int i, j, r, c;
	graph[u][v] = replac;
	
	for (i = 0; i < 6; ++i){
		r = u + dr[i];
		c = v + dc[i];
		if (r >= 0 && r < n && c >= 0 && c < n){
			if (graph[r][c] == ch){
				dfsVisit(r, c, ch, replac);
			}
		}
	}
}

void dfs(){
	int i, j, k;
	for (i = 0; i < n;++i){
		if (graph[0][i] == 'b')
			dfsVisit(0, i, 'b', 'B');
		if (graph[i][0] == 'w')
			dfsVisit(i, 0, 'w', 'W');
	}
}


int main(){
	int cases = 0;
	//freopen("input.txt", "r", stdin);
	int i;
	while (cin >> n){
		if (n == 0) break;
		++cases;
		for (i = 0; i < n; ++i)
			cin >> graph[i];
		
		dfs();
		for (i = 0; i < n; ++i){
			if (graph[i][n-1] == 'W'){
				cout << cases << " " << "W" << endl;
				break;
			}
			else if (graph[n-1][i] == 'B'){
				cout << cases << " " << "B" << endl;
				break;
			}
		}
	}
	return 0;
}
