/* Problem:   All Roads Lead Where?  UVa 10009
   Programmer: Md. Mahmud Ahsan
   Description: Graph + BFS OR Floyd Warshell
   Compiled: Visual C++ 7.0
   Date: 15-12-05
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MX = 300;
const int INF = 1 << 28;

char color[MX];
int dis[MX]; //optional no need in this problem
int graph[MX][MX], nc = 0;
string id[MX]; 
int pi[MX]; //very important for finding shortest path

int getId(string val){
	for (int i = 0; i < nc; ++i)
		if (id[i] == val)
			return i;
	id[nc] = val;
	return nc++;
}	
char getFirstLetter(int i){
	string temp = id[i];
	char c = temp[0];
	return c;
}

void printPath(int s, int v){
	if (s == v)
		cout << getFirstLetter(s);
	else{
		printPath(s, pi[v]);
		cout << getFirstLetter(v);
	}
}

void init(){
	for (int i = 0; i < MX; ++i){
		for (int j = 0; j < MX; ++j)
			graph[i][j] = 0;
	}
}

void bfs(int start){
	int i, u;
	for (i = 0; i < nc; ++i){
		dis[i] = INF;
		color[i] = 'w';
		pi[i] = -1;
	}
	queue<int> q;
	color[start] = 'g';
	dis[start] = 0;
	q.push(start);

	while (!q.empty()){
		u = q.front(); q.pop();

		for (i = 0; i < nc; ++i){
			if ( (graph[u][i] == 1) && (color[i] == 'w')){
				color[i] = 'g';
				dis[i] = dis[u] + 1;
				pi[i] = u;
				q.push(i);
			}
		}
		color[u] = 'b';
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int test, a, b, x, y;
	bool newLine = false;
	char temp[100];
	string first, second;

	cin >> test;
	cin.getline(temp, sizeof(temp)); //eat new line
	cin.getline(temp, sizeof(temp)); // eat blank line
		
	while (test--){
		init();
		cin >> a >> b;
		if (newLine == true) cout << endl; newLine = true;
		
		while (a--){
			cin >> first >> second;
			x = getId(first);
			y = getId(second);

			graph[x][y] = 1;
			graph[y][x] = 1;
		}
		while (b--){
			cin >> first >> second;
			x = getId(first);
			y = getId(second);
			bfs(x);
			printPath(x, y);	
			cout << endl;
		}
	}

	return 0;
}