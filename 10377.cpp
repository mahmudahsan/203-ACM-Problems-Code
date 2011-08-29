/* Problem: Maze Traversal UVa 10377
   Programmer: Md. Mahmud Ahsan
   Description: Simulation
   Compiled: Visual C++ 7.0
   Date: 18-09-05
*/
#include <iostream>
#include <string>
using namespace std;

char dir = 'N';
string coridor[100];
int test, row, col, i, _row, _col;

void forward(){
	if (dir == 'E'){ 
		if (coridor[_row][_col+1] != '*')
			++_col;
	}
	else if (dir == 'W'){ 
		if (coridor[_row][_col-1] != '*')
			--_col;
	}
	else if (dir == 'S'){ 
		if (coridor[_row+1][_col] != '*')
			++_row;
	}
	else if (dir == 'N'){ 
		if (coridor[_row-1][_col] != '*')
			--_row;
	}
}

void right(){
	switch(dir){
		case 'N': dir = 'E'; break;
		case 'E': dir = 'S'; break;
		case 'S': dir = 'W'; break;
		case 'W': dir = 'N'; break;
	}
}

void left(){
	switch(dir){
		case 'N': dir = 'W'; break;
		case 'W': dir = 'S'; break;
		case 'S': dir = 'E'; break;
		case 'E': dir = 'N'; break;
	}
}

int main(){
	char c, str[200];
	cin >> test;
	bool flag = false;

	while (test--){
		cin >> row >> col;
		cin.getline(str, sizeof(str)); // eat blank line
		for (i = 0; i < row; ++i){
			cin.getline(str, sizeof(str));
			coridor[i] = str;
		}

		cin >> _row >> _col;
		dir = 'N';
		--_row; --_col;

		while ( (c = cin.get()) != 'Q'){
			switch(c){
				case 'R': right(); break;
				case 'L': left(); break;
				case 'F': forward(); break;
			}
		}
		if (flag) cout << endl; flag = true;
		cout << _row+1 << " " << _col+1 << " " << dir << endl;
	}

	return 0;
}