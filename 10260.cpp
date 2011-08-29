/* Problem: Soundex UVa 10260
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 06-08-04
*/

#include <iostream>
using namespace std;

int main(){
	char code[92][2]; // first column contains character second contains code
	int i, j;
	
	for (i = 65; i <= 91; i++){
		code[i][0] = i;
	}

	// initialize the seond column
	code['A'][1] = code['E'][1] = code['I'][1] = code['O'][1] = code['U'][1] = code['H'][1] = code['W'][1] = code['Y'][1] = '0';
	code['B'][1] = code['F'][1] = code['P'][1] = code['V'][1] = '1';
	code['C'][1] = code['G'][1] = code['J'][1] = code['K'][1] = code['Q'][1] = code['S'][1] = code['X'][1] = code['Z'][1] = '2';
	code['D'][1] = code['T'][1] = '3';
	code['L'][1] = '4';
	code['M'][1] = code['N'][1] = '5';
	code['R'][1] = '6';

	char input[100];

	while (cin >> input){

		for (i = 0; input[i] != '\0'; i++){
			for (j = 65; j <= 91; j++){
				// search if input[i] equal to code[j][0]
				if ((input[i] == code[j][0]) && (code[j][1] != '0')){
					// Words with the same Soundex coding are considered equivalent so
					if (code[input[i]][1] != code[input[i-1]][1])
						cout << code[j][1];
				}
			}
		}
		cout << endl;
	}
	return 0;
}