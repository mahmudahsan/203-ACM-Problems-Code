/* Problem:  Word Transformation  UVa 429
   Programmer: Md. Mahmud Ahsan
   Description: Graph + BFS
   Compiled: Visual C++ 7.0
   Date: 15-02-06
*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 100000;
const int MX = 210;

string id[MX];
int dist[MX], graph[MX][MX], nc, dictSize;
char color[MX];

int getId(string a){
	for(int i = 0; i < nc; ++i){
		if (id[i] == a) return i;
	}
	id[nc] = a;
	return nc++;
}

void init(){
	for (int i = 0; i < nc; ++i){
		for (int j = 0; j < nc; ++j)
			graph[i][j] = INF;
	}	
}

void bfs(int s){
	int u, i;
	
	for (int i = 0; i < nc; ++i){
		dist[i] = INF;
		color[i] = 'w';
	}
	dist[s] = 0;
	color[s] = 'g';

	queue <int> q;
	q.push(s);
	while (!q.empty()){
		u = q.front(); q.pop();
		for (i = 0; i < nc; ++i){
			if (graph[u][i] == 1 && color[i] == 'w'){
				dist[i] = dist[u] + 1;
				color[i] = 'g';
				q.push(i);
			}
		}
		color[u] = 'b';
	}
}

int differ(string a, string b){
	int counter = 0;
	
	for (int i = 0; i < a.size(); ++i){
		if (a[i] != b[i])
			++counter;
	}
	return counter;
}

int main(){
	//freopen("input.txt", "r", stdin);
	
	char temporary[50];
	string str[210], temp;
	int i, j, test;
	bool newLine = false;

	cin >> test;
	while (test--){
		dictSize = nc = 0;
		while (cin >> temp){
			if (temp == "*") break;
			j = getId(temp);
			str[dictSize++] = temp;
		}
		init();
		sort(str, str+dictSize);

		for (i = 0; i < dictSize; ++i){
			for (j = 0; j < dictSize; ++j){
				if (str[i].size() == str[j].size() && i != j){
					if (differ(str[i], str[j]) == 1)
						graph[getId(str[i])][getId(str[j])] = 1;
				}
			}
		}
		if (newLine) cout << endl; newLine = true;
		
		int len; char *p;
		cin.getline(temporary, sizeof(temporary)); // eat new line
		while (cin.getline(temporary, sizeof(temporary))){
			len = strlen(temporary);
			if (len == 0) break;

			p = strtok(temporary, " \n\t");
			string start(p);
			p = strtok(NULL, " \n\t");
			string end(p);
			bfs(getId(start));
			cout << start << " " << end << " " << dist[getId(end)] << endl;
		}
	
	}
	return 0;
}
