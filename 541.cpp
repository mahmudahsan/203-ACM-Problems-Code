/* Problem: Error Correction UVa 541
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 01-10-04
*/
#include <iostream>
using namespace std;

namespace global{
	bool parity;
	int chRow;
	int chCol;
	char grid[102][102];
	int input;
}

//prototypes
void chkParity();
void initialize();
//========================================================
int main(){
	int i, j;

	using namespace global;
	while (cin >> input){
		if (input == 0) break;
		initialize(); // all character set to '0'

		for (i = 0; i < input; i++){
			for (j = 0; j < input; j++){
				cin >> grid[i][j];
			}
		}

		chkParity();
		if (parity){
			cout << "OK" << endl;
			continue;
		}
		
		if (grid[chRow][chCol] == '0')
			grid[chRow][chCol] = '1';
		else
			grid[chRow][chCol] = '0';
				
		chkParity();
		if (parity)
			cout << "Change bit (" << ++chRow << "," << ++chCol << ")" << endl;
		else
			cout << "Corrupt" << endl;
	}
	return 0;
}
//=============================================================================
using namespace global;
void chkParity(){
	int i, j;
	int result;
	
	parity = true; // at first time
	for (i = 0; i < input; i++){
		result = 0;
		for (j = 0; j < input; j++){
			result += grid[i][j] - 48;
		}
		
		// if in a row an error occured
		if (result % 2 != 0){
			parity = false;
			chRow = i;
			break;
		}
	}

	for (i = 0; i < input; i++){
		result = 0;
		for (j = 0; j < input; j++){
			result += grid[j][i] - 48;
		}
		// if in a col an error occured
		if (result % 2 != 0){ 
			parity = false;
			chCol = i;
			break;
		}
	}
}

// initializing the boolean grid
void initialize(){
	parity = true;
	int i, j;
	
	for (i = 0; i < 102; i++){
		for (j = 0; j < 102; j++){
			grid[i][j] = '0';
		}
	}	
}