/* Problem:  Wormholes  UVa 558
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Bellman Ford
   Compiled: Visual C++ 7.0
   Date: 14-02-06
*/
#include <iostream>
using namespace std;

const int INF = 10000000;
const int MX = 2050;

struct Node{
	int u, v, weight;
}nodes[MX];

int d[MX];
int m, n, t;

void initializeSingleSource(int s){
	for (int i = 0; i < n; ++i)
			d[i]= INF;	
	d[s] = 0;
}	

void relax(int u, int v, int w){
	if (d[v] > d[u] + w)
		d[v] = d[u] + w;
}

bool bellmanFord(int s){
	//initializeSingleSource(s);
	int i, j;
	for (i = 0; i < n-1; ++i){
		for (j = 0; j < m; ++j){
			relax(nodes[j].u, nodes[j].v, nodes[j].weight);
		}
	}
	for (j = 0; j < m; ++j){
		if (d[nodes[j].v] > d[nodes[j].u] + nodes[j].weight)
			return false;
	}
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int c, x, y, z, i;
	cin >> c;

	while (c--){
		cin >> n >> m;
		for (i = 0; i < m; ++i){
			cin >> x >> y >> z;
			nodes[i].u = x;
			nodes[i].v = y;
			nodes[i].weight = z;
		}
		if (!bellmanFord(0))
			cout << "possible" << endl;
		else
			cout << "not possible" << endl;

	}
	return 0;
}
