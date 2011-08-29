/* Problem: MPI Maelstrom UVa 423 
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Floyd Warshall
   Compiled: Visual C++ 7.0
   Date: 28-02-06
*/
#include <iostream>
#include <string>
using namespace std;

const int MX = 105;
const int INF = 1 << 20;

int graph[MX][MX], n;

void init(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			graph[i][j] = INF;
		}
		graph[i][i] = 0;
	}
}

void floydWarshall(){
	int i, j, k;
	for (k = 1; k <= n; ++k){
		for (i = 1; i <= n; ++i){
			for (j = 1; j <= n; ++j){
				if (graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j, k, temp;
	char str[100];

	while (cin >> n){
		init();
		for (i = 1; i <= n; ++i){
			for (j = 1; j < i; ++j){
				cin >> str;
				if (str[0] == 'x') continue;

				temp = atoi(str);
				graph[i][j] = temp;
				graph[j][i] = temp;
			}
		}
		floydWarshall();
			
		int maxi = 0;
		for (i = 2; i <= n; ++i){
			if (graph[1][i]>maxi)
				maxi = graph[1][i];
		}
		cout << maxi << endl; 
	}
	return 0;
}
