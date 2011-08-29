/* Problem: Frogger UVa 534
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Floyd Warshall + Minimax
   Compiled: Visual C++ 7.0
   Date: 01-03-06
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int MX = 205;
const int INF = 1 << 20;

struct Node{
	int x, y;
}nodes[MX];

double graph[MX][MX];
int n;

double getWeight(Node a, Node b){
	return  sqrt ((double) ((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

void init(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			graph[i][j] = INF;
	}
}

void floydWarshall(){
	int i, j, k;
	for (k = 0; k < n; ++k){
		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
			}
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j, cases = 0, a, b;
	double temp;

	while (cin >> n){
		if (n == 0) break;
		
		init();
		for (i = 0; i < n; ++i){
			cin >> a >> b;
			nodes[i].x = a;
			nodes[i].y = b;
		}

		//compute edges
		for (i = 0; i < n; ++i){
			for (j = i + 1; j < n; ++j){
				temp = getWeight(nodes[i], nodes[j]);
				graph[i][j] = temp;
				graph[j][i] = temp;
			}
		}
		floydWarshall();
		cout << "Scenario #" << ++cases << endl;
		printf("Frog Distance = %.3lf\n", graph[0][1]); //graph[0][1] is fiona's stone
		cout << endl;
	}

	return 0;
}
