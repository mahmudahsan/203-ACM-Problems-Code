/* Problem: Ubiquitous Religions UVa 10583
   Programmer: Md. Mahmud Ahsan
   Description: Set Data Structure
   Compiled: Visual C++ 7.0
   Date: 18-02-06
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 50005;

int p[MX], rank[MX], tree[MX]; // tree for counting each set's elements
int n, m;

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
		if (rank[x] == rank[y])
			rank[y] = rank[y] + 1;
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
	//link(findSet(x), findSet(y));
	link(x, y); // because findSet() is called in the main function
}

int main(){
	//freopen("input.txt", "r", stdin);
    	int i, j, a, b, maximum, fA, fB, cases = 0;
	
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		for (i = 1; i <= n; ++i)
			makeSet(i);

		fill(tree, tree+n+1, 1); // as <= n
		for (i = 0; i < m; ++i){
			cin >> a >> b;
			
			fA = findSet(a); 
			fB = findSet(b);
			if (fA != fB)
				unions(fA, fB);
		}

		maximum = 0;
		for (i = 1; i <= n; ++i)
			if (tree[i] == 0) // zero means no religion
				++maximum;
		maximum = n - maximum; //total religion - how many zero religion
		cout << "Case " << ++cases << ": " << maximum << endl;
	}

	return 0;
}
