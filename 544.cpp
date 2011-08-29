/* Problem: Heave Cargo UVa 544
   Programmer: Md. Mahmud Ahsan
   Description: Graph + Floyd Warshall + Maximini
   Compiled: Visual C++ 7.0
   Date: 01-03-06
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MX = 205;

int graph[MX][MX], n;
string id[MX];

int getId(string x){
	for (int i = 0; i < n; ++i)
		if (id[i] == x) return i;
	id[n] = x;
	return n++;
}

void init(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			graph[i][j] = 0;
	}
}

void floydWarshall(){
	int i, j, k;
	for (k = 0; k < n; ++k){
		for(i = 0; i < n; ++i){
			for (j = 0; j < n; ++j)
				graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int r, i, j, cases = 0, temp;
	int id1, id2;
	string a, b;

	while (cin >> n >> r){
		if (n == 0 && r == 0) break;

		init();
		n = 0;
		for (i = 0; i < r; ++i){
			cin >> a >> b >> temp;
			id1 = getId(a);
			id2 = getId(b);
			graph[id1][id2] = temp;
			graph[id2][id1] = temp;
		}

		floydWarshall();
		
		cout << "Scenario #" << ++cases << endl;
		cin >> a >> b;
		id1 = getId(a); id2 = getId(b);
		cout << graph[id1][id2] << " tons" << endl;
		cout << endl;
	}		
	return 0;
}
