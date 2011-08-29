/* Problem:  Friends   UVa 10608
   Programmer: Md. Mahmud Ahsan
   Description: SET
   Compiled: Visual C++ 7.0
   Date: 19-02-06
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 500005;
int rank[MX], p[MX], tree[MX];//tree counts the number of elements
int twoD[MX][2], maximum;


void makeSet(int x){
	p[x] = x;
	rank[x] = 0;
}

void link(int x, int y){
	if (rank[x] > rank[y]){
		p[y] = x;
		tree[x] += tree[y];
		tree[y] = 0;
	}
	else{
		p[x] = y;
		if (rank[x] == rank[y]){
			rank[y] = rank[y]+1;
		}
		tree[y] += tree[x];
		tree[x] = 0;
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

int main(){
	//freopen("input.txt", "r", stdin);
	int n, m, test;
	int i, j, a, b;
	
	cin >> test;
	while (test--){
		cin >> m >> n;
		
		for (j = 1; j <= n; ++j){
			cin >> a >> b;
			makeSet(a); makeSet(b);
			twoD[j][0] = a;
			twoD[j][1] = b;
		}
		fill(tree, tree+m+1, 1); //as <=n
	
		for (i = 1; i <= n; ++i){
			if (findSet(twoD[i][0]) != findSet(twoD[i][1]))
				unions(twoD[i][0], twoD[i][1]);
		}
		maximum = 1;
		for (i = 1; i <= n; ++i){
			if (tree[i] > maximum) 
				maximum = tree[i];
		}
		cout << maximum << endl;
	}
	return 0;
}
