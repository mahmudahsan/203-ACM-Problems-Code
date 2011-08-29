/* Problem: A Node Too Far UVa 336
   Programmer: Md. Mahmud Ahsan
   Description: DFS
   Compiled: Visual C++ 7.0
   Date: 10-12-05
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MX = 100;
const int INF = 1<<28;

//global declaration
char color[MX];
int dis[MX], graph[100][100];
int nc, id[MX];

//=============================================
int getId(int x){
	int i;
	for (i = 0; i < nc; ++i){
		if (id[i] == x) return i;
	}
	id[nc] = x;
	return nc++;
}	

void init(){
	for (int i = 0; i < MX; ++i){
		for (int j = 0; j < MX; ++j)
			graph[i][j] = 0;	
	}
}

void bfs(int start){
	int i, j, u;
	for (i = 0; i < nc; ++i){
		dis[i] = INF;
		color[i] = 'w';
	}
	queue <int> q;

	color[start] = 'g';
	dis[start] = 0;
	q.push(start);

	while (!q.empty()){
		u = q.front();
		q.pop();
		for (i = 0; i < nc; ++i){
			if ((graph[u][i] == 1) && (color[i] == 'w')){
				color[i] = 'g';
				dis[i] = dis[u]+1;
				q.push(i);
			}
		}
		color[u] = 'b';
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int N, i, cases = 0, a, count, b;
	while (cin >> N){
		if (N == 0) break;
		nc = 0;
		init();

		for (i = 0; i < N; ++i){
			cin >> a >> b;
			a = getId(a);
			b = getId(b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		while (cin >> a >> b){
			if (a == 0 && b == 0) break;

			i = getId(a);
			bfs(i);
			
			count = 0;
 			for (i = 0; i < nc; ++i)
				if (dis[i] > b) ++count;
			
			cout << "Case " << ++cases << ": " << count << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl;

		}

	}

	return 0;
}
