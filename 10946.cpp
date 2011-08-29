/* Problem:  You want what filled? UVa 10946
   Programmer: Md. Mahmud Ahsan
   Description: Graph + DFS
   Compiled: Visual C++ 7.0
   Date: 19-08-06
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dr[] = {-1, 0, 1, 0}; 
int dc[] = { 0, 1, 0, -1};

const int MX = 100;

struct Data{
	char ch;
	int count;
}datas[5000];

int x, y, counter, temp;
char grid[MX][MX];
char ch;

void dfsVisit(int a, int b){
	int r, c;
	grid[a][b] = '.';
	for (int i = 0; i < 4; ++i){
		r = a + dr[i];
		c = b + dc[i];
		if (grid[r][c] == ch){
			++temp;
			dfsVisit(r, c);
		}
	}
}
void dfs(){
	for (int i = 0; i < x; ++i){
		for (int j = 0; j < y; ++j){
			temp = 0; // temp for how many holes of a character
			if (grid[i][j] != '.'){
				++temp;
				ch = grid[i][j];
				dfsVisit(i, j);
				datas[counter].ch = ch;
				datas[counter++].count = temp;
			}
		}
	}
}

inline bool comp(const Data &a, const Data &b){
	if (a.count != b.count)
		return a.count > b.count;
	return a.ch < b.ch;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, cases = 0;

	while (cin >> x >> y){
		if (!x && !y) break;
		
		for (i = 0; i < x; ++i)
			cin >> grid[i];
			
		counter = 0;
		dfs();
		sort(datas, datas+counter, comp);

		cout << "Problem " << ++cases << ":" << endl;
		for (i = 0; i < counter; ++i)
			cout << datas[i].ch << " " << datas[i].count << endl;
	}

	return 0;
}
