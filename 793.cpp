/* Problem:  Network Connection  UVa 793
   Programmer: Md. Mahmud Ahsan
   Description: Data Structure + Set
   Compiled: Visual C++ 7.0
   Date: 15-02-06
*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int MX = 1000000;
int p[MX], rank[MX];

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
			rank[y] = rank[y] + 1;
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
	int test, i, computers, a, b, success, unsuccess;
	char c, temp[100];
	bool newLine = false;
	
	cin >> test;
	while (test--){
		cin >> computers;
		cin.getline(temp, sizeof(temp)); // eat blank line
		
		success = unsuccess = 0;
		for (i = 1; i <= computers; ++i)
			makeSet(i);

		while (cin.getline(temp, sizeof(temp))){
			if (strlen(temp) == 0) break;
			sscanf(temp, "%c%d%d", &c, &a, &b);
			if (c == 'c')
				unions(a,b);
			else if (c == 'q'){
				if (findSet(a) == findSet(b))
					++success;
				else
					++unsuccess;
			}
		}
		if (newLine) cout << endl; newLine = true;
		cout << success << "," << unsuccess << endl;
	}

	return 0;
}
