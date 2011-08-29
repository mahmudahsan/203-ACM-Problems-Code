/* Problem: Freckles UVa 10034
   Programmer: Md. Mahmud Ahsan
   Description: MST + Kruskal's Algorithm
   Compiled: Visual Studio .Net
   Date: 31-12-05
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

/*
	1+2+3+(n-1) = n(n-1)/2; edges could be made of n vertices
*/

struct Vertex{
	int id;
	double x, y;
}v[104];

struct Edge{
	int id1, id2;
	double distance;
}e[52*103];

int vertices, edges;
int p[104], rank[104];

void makeSet(int x){
	p[x] = x;
	rank[x] = 0;
}

void link(int x, int y){
	if (rank[x] > rank[y])
		p[y] = x;
	else{
		p[x] = y;
		if (rank[x] == rank[y])
			rank[y] = rank[y]+1;
	}
}

int findSet(int x){
	if (x != p[x])
		p[x] = findSet(p[x]);
	return p[x];
}

void unions(int x, int y){
	link(findSet(x), findSet(y));
}

//return the weight
double getWeight(Vertex a, Vertex b){
	return  sqrt ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

inline bool comp(Edge a, Edge b){
	return a.distance < b.distance;
}

double kruskal(){
	int i;
	double mstValue;
	for (i = 0; i < vertices; ++i)
		makeSet(v[i].id);

	//sort the edges of E
	sort(e, e+edges, comp);
	
	mstValue = 0.0;
	for (i = 0; i < edges; ++i){
		if (findSet(e[i].id1) != findSet(e[i].id2)){
			mstValue += e[i].distance;
			unions(e[i].id1, e[i].id2);
		}
	}
	return mstValue;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int test, i, j, flag = 0;
	double x, y, mstValue;
	cin >> test;

	while(test--){
		cin >> vertices;
		for (i = 0; i < vertices; ++i){
			cin >> x >> y;
			v[i].id = i;
			v[i].x = x;
			v[i].y = y;
		}
		//define weights of each edge
		edges = 0; //global variable
		for (i = 0; i < vertices; ++i){
			for (j = i+1; j < vertices; ++j){
				e[edges].id1 = v[i].id;
				e[edges].id2 = v[j].id;
				e[edges].distance = getWeight(v[i], v[j]);
				++edges;
			}
		}
		
		mstValue = kruskal();
		if (flag == 1) cout << endl; flag = 1;
		printf("%.2lf\n", mstValue);
	}

	return 0;
}