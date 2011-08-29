/* Problem: Graph Connectivity  UVa 459
   Programmer: Md. Mahmud Ahsan
   Description: Graph + BFS
   Compiled: Visual C++ 7.0
   Date: 14-12-05
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MX = 200;

//global declaration
char color[MX];
int graph[MX][MX];
char id[MX];
int nc = 0;

int getId(char x){
	for (int i = 0; i < nc; ++i){
		if (id[i] == x) return i;
	}
	id[nc] = x;
	return nc++;
}

void init(){
	nc = 0;
	for (int i = 0; i < MX; ++i){
		for (int j = 0; j < MX; ++j)
			graph[i][j] = 0;
	}
}

void bfs(int start){
	int i, u;

	queue <int > q;
	color[start] = 'g';
	q.push(start);
	while (!q.empty()){
		u = q.front(); q.pop();
		
		for (i = 0; i < nc; ++i){
			if ((graph[u][i] == 1) && (color[i] == 'w')){
				color[i] = 'g';
				q.push(i);
			}
		}
		color[u] = 'b';
	}			
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, N, a, b, j,flag = 1, total;
	char temp[120];
	cin >> N;
	cin.getline(temp, sizeof(temp)); // eat new line

	cin.getline(temp, sizeof(temp)); // eat blank line

	while (N--){		
		i = 0;
		init();
		for (i = 0; i < MX; ++i)
			color[i] = 'w';
		
		if (flag == 0) cout << endl; flag = 0;

		cin.getline(temp, sizeof(temp)); // largest node
		// if only one node but no edge
		for (i = 'A'; i <= 'Z'; ++i){
			getId((char) i);
			if (i == temp[0]) break;
		}

		while (cin.getline(temp, sizeof(temp))){
			if (strlen(temp) == 0) break;

			a = getId(temp[0]);
			b = getId(temp[1]);

			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		total = 0;
		for (i = 0; i < nc; ++i){
			if (color[i] == 'w'){
				++total;
				bfs(i);
			}

		}

		cout << total << endl;
		
	}
	return 0;
}