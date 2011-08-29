/* Problem:   Shipping Routes  UVa 383
   Programmer: Md. Mahmud Ahsan
   Description: Graph + BFS
   Compiled: Visual C++ 7.0
   Date: 02-01-06
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int LIMIT = 99999999;
const int MX = 400;

//global data
char graph[MX][MX];
int nc;
string id[MX];
char color[MX];
int dist[MX];

int  m, n, p, ship;
string temp, first, second;

int getId(string m){
	for (int i = 0; i < nc; ++i)
		if (id[i] == m) return i;
	id[nc] = m;
	return nc++;
}

void init(){
	for (int i = 0; i < MX; ++i){
		for (int j = 0; j < MX; ++j)
			graph[i][j] = '0';
	}
}

int bfs(int start, int end){
	int i, j, u;
	for (i = 0; i < nc; ++i){
		color[i] = 'w';
		dist[i] = LIMIT;
	}
	
	color[start] = 'g';
	dist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()){
		u = q.front(); q.pop();

		for (i = 0; i < nc; ++i){
			if ( (graph[u][i] == '1') && (color[i] == 'w')){
				color[i] = 'g';
				dist[i] = dist[u] + 1;
				q.push(i);
			}
		}
		color[u] = 'b';
	}
	if (dist[end] == LIMIT) return -1;
	return dist[end];
}	

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int test, i, j, a, b, cases = 0;
	cin >> test;
	
	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
	while (test--){
		nc = 0;
		init();

		cin >> m >> n >> p;
		for (i = 0; i < m; ++i){
			cin >> temp;
			j = getId(temp);
		}

		for (i = 0; i < n; ++i){
			cin >> first >> second;
			a = getId(first);
			b = getId(second);
			graph[a][b] = '1';
			graph[b][a] = '1';
		}
		cout << "DATA SET  " << ++cases << endl << endl;

		for (i = 0; i < p; ++i){
			cin >> ship >> first >> second;
			a = getId(first);
			b = getId(second);
			j = bfs(a, b);
			
			if (j == -1)
				cout << "NO SHIPMENT POSSIBLE" << endl;
			else{
				cout << "$" << (j * ship*100) << endl;
			}				
		}
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}
