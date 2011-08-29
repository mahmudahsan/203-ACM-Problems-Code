/* Problem: Audiophobia UVa 10048
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Floyd Warshall + Minimax
   Compiled: Visual C++ 7.0
   Date: 01-03-06
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 20;
const int MX = 105;

int graph[MX][MX], n;

void init(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			graph[i][j] = INF;
		graph[i][i] = 0;
	}
}

void floydWarshall(){
	int i, j, k;
	for (k = 1; k <= n; ++k){
		for(i = 1; i <= n; ++i){
			for (j = 1; j <= n; ++j)
				graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int s, q, i, j, cases = 0, temp, a, b;
	bool flag = false;

	while (cin >> n >> s >> q){
		if (n == 0 && s == 0 && q == 0) break;

		init();
		for (i = 1; i <= s; ++i){
			cin >> a >> b >> temp;
			graph[a][b] = temp;
			graph[b][a] = temp;
		}
		floydWarshall();

		if (flag)cout << endl; flag = true;
		cout << "Case #" << ++cases << endl;
		
		for (i = 1; i <= q; ++i){
			cin >> a >> b;
			if (graph[a][b] == INF)
				cout << "no path" << endl;
			else
				cout << graph[a][b] << endl;
		}
	}		
	return 0;
}
