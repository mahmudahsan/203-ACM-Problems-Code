/* Problem: Tic Tac Toe UVa 10363
   Programmer: Md. Mahmud Ahsan
   Description: Ad-hoc
   Compiled: Visual C++ 7.0
   Date: 21-08-06
*/
#include <iostream>
#include <string>
using namespace std;

char grid[5][5];

bool chkWin(char c){
	int i, r1, r2, r3;
	r1 = r2 = r3 = 0;
	for (i = 0; i < 3; ++i){
		if (grid[0][i] == c) ++r1;
		if (grid[1][i] == c) ++r2;
		if (grid[2][i] == c) ++r3;
	}
	if (r1 == 3 || r2 == 3 || r3 == 3) return true;

	//now  r stands for col
	r1 = r2 = r3 = 0;
	for (i = 0; i < 3; ++i){
		if (grid[i][0] == c) ++r1;
		if (grid[i][1] == c) ++r2;
		if (grid[i][2] == c) ++r3;
	}
	if (r1 == 3 || r2 == 3 || r3 == 3) return true;

	if (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) return true;
	if (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c) return true;

	return false;
}

int count(char c){
	int temp = 0;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
			if (grid[i][j] == c)
				++temp;
	}
	return  temp;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int n, x, o;
	bool oWin, xWin, possible;

	cin >> n;

	while (n--){
		possible = true;

		cin >> grid[0];
		cin >> grid[1];
		cin >> grid[2];

		xWin = chkWin('X');
		oWin = chkWin('O');
	
		x = count('X');
		o = count('O');

		while(true){
			if (xWin && oWin) { possible = false; break;}
			if (x < o || x > o+1) { possible = false; break;}
			if (xWin && x != o+1) { possible = false; break;}
			if (oWin && o != x)   { possible = false; break;} 
			break;
		}

		if (possible) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}
