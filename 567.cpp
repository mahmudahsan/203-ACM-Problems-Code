/* Problem: Risk UVa 567
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Floyd Warshall
   Compiled: Visual C++ 7.0
   Date: 28-02-06
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int MX = 30;
const int INF = 1 << 20;

int graph[MX][MX];
int parent[MX][MX], counter;

void init(){
	for (int i = 1; i < MX; ++i){
		for (int j = 1; j < MX; ++j){
			graph[i][j] = INF;
			parent[i][j] = i;
		}
		graph[i][i] = 0;
	}
}

void floydWarshall(int n){
	int i,j ,k;
	for (k = 1; k <= n; ++k){
		for (i = 1; i <= n; ++i){
			for (j = 1; j <= n; ++j){
				if (graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
}

void getCountries(int i, int j){
	if (i == j)
		return;
	else{
		getCountries(i, parent[i][j]);
		++counter;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j, k, temp, m, cases = 0;
	bool exit = false;

	while (!cin.eof()){
		init();
		for (i = 1; i <= 19; ++i){
			cin >> m;
			if (cin.eof()){
				exit = true;	
				break;
			}
			for (j = 1; j <= m; ++j){
				cin >> temp;
				graph[i][temp] = 1;
				graph[temp][i] = 1;
				
				parent[i][temp] = i;
				parent[temp][i] = temp;
			}
		}
		if (exit) break;
		floydWarshall(20);
		
		cout << "Test Set #" << ++cases << endl;
		cin >> m;
		for (i = 1; i <= m; ++i){
			counter = 0;
			cin >> j >> k;
			getCountries(j, k);
			printf("%2d", j);
			cout << " to ";
			printf("%2d", k);
			cout << ": ";
			printf("%-2d\n", counter); 
		}
		cout << endl;
	}    
	return 0;
}
