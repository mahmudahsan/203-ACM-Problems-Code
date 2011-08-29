/* Problem: Bicoloring  UVa 10004
   Programmer: Md. Mahmud Ahsan
   Description: Graph + BFS
   Compiled: Visual C++ 7.0
   Date: 14-12-05
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MX = 205;

//global declaration
char color[MX];
int graph[MX][MX];
int id[MX], nc = 0;
bool colorable; // ?is given graph is colorable
char varColor = 'r'; //use to fill color

void changeColor(char c){ 
	if (c == 'r')
		varColor = 'g';
	else
		varColor = 'r';
}

int getId(int x){
	for (int i = 0; i < nc; ++i){
		if (id[i] == x) return i;
	}
	id[nc] = x;
	return nc++;
}

void init(){
	colorable = true;
	varColor = 'r';
	nc = 0;
	for (int i = 0; i < MX; ++i){
		for (int j = 0; j < MX; ++j)
			graph[i][j] = 0;
	}
}

void bfs(int start){
	int i, u;
	for (i = 0; i < nc; ++i)
		color[i] = 'w';

	queue <int > q;
	color[start] = varColor; // varColor is now red color
	q.push(start);
	while (!q.empty()){
		u = q.front(); q.pop();
		changeColor(color[u]); // adjacent nodes are colored that is reverse color of current node

		for (i = 0; i < nc; ++i){
			if ( (u != i) &&(graph[u][i] == 1) && (color[i] == 'w')){
				color[i] = varColor;
				q.push(i);
			}
			//already adjacent are colored so have to check is that the same color of current node
			else if ((u != i) &&(graph[u][i] == 1) && (color[u] == color[i]))
				colorable = false;
		}
	}			
}

int main(){
	//freopen("input.txt", "r", stdin);
	int n, l, a, b, i;

	while (cin >> n){
		if (n == 0) break;
				
		init();
		cin >> l; // number of edges
		for (i = 0; i < l; ++i){
			cin >> a >> b;
			a = getId(a); 
			b = getId(b);
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		bfs(id[0]); //starting from the first node
		if (colorable) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}

	return 0;
}
