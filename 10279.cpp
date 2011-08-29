/* Problem: Minesweeper UVa 10279
   Programmer: Md. Mahmud Ahsan
   Description: Grid Searching
   Compiled: Visual C++ 7.0
   Date: 17-02-06
*/
#include <iostream>
#include <string>
using namespace std;

char data[20][20];
char str[20][20];
char output[20][20];

int dr[] = {-1, -1, -1, 0, 1, 1,  1,  0};
int dc[] = {-1,  0,  1, 1, 1, 0, -1, -1};

void init(int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			output[i][j] = '.';
	}
}

char check(int n, int R, int C){
	int i, r, c, num = 0;

	for (i = 0; i < 8; ++i){
		r = R + dr[i];
		c = C + dc[i];

		if ( r >= 0 && r < n && c >= 0 && c < n){
			if (data[r][c] == '*')
				++num;
		}
	}
	return num+48;
}

void checkAll(int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (data[i][j] == '*')
				output[i][j] = '*';
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	bool flag = false;

	int test, i, j, t, n;
		
	cin >> test;
	while (test--){
		cin >> n;
		
		if (flag) cout << endl; flag = true;
		
		init(n);
		for (t = 0; t < n; ++t)
			cin >> data[t];
		
		for (t = 0; t < n; ++t)
			cin >> str[t];

		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j){
				if (data[i][j] == '.' && str[i][j] == 'x'){
					output[i][j] = check(n, i, j);
				}
				if (data[i][j] == '*' && str[i][j] == 'x'){
					checkAll(n);
				}
			}
		}
		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j)
				cout << output[i][j];
			cout << endl;
		}
	}

	return 0;
}
