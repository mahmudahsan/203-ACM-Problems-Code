/* Problem: Vertex UVa 280
   Programmer: Md. Mahmud Ahsan
   Description: Graph + DFS
   Compiled: Visual C++ 7.0
   Date: 24-03-06
*/
#include <iostream>
#include <string>
using namespace std;

const int MX = 105;

int graph[MX][MX], n;
char color[MX];

void init(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			graph[i][j] = 0;
	}
}

void dfsVisit(int i){
	color[i] = 'g';
	for (int j = 1; j <= n; ++j){
		if (graph[i][j] == 1 && color[j] == 'w'){
			dfsVisit(j);
		}
	}
	color[i] = 'b';
}

void dfs(int start){
	for (int i = 1; i <= n; ++i)
		color[i] = 'w';
	
	for (int i = 1; i <= n; ++i){
		if (graph[start][i] == 1 && color[i] == 'w')
			dfsVisit(i);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int start, next, test, total = 0, j, arr[MX];

	while (cin >> n){
		if (n == 0) break;
		
		init();
		while (cin >> start){
			if (start == 0) break;
			
			while (cin >> next){
				if (next == 0) break;
				graph[start][next] = 1;
			}
		}
		cin >> test;
		while (test--){
			cin >> start;
			dfs(start);
			total = j = 0;
			for (int i = 1; i <= n;++i){
				if (color[i] == 'w'){
					++total;
					arr[j++] = i; 
				}
			}
			cout << total;
			for (int i = 0; i < j; ++i)
				cout << " " << arr[i];
			cout << endl;
		}
	}
	return 0;
}
