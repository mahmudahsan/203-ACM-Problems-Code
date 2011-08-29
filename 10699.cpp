/* Problem: Problem D - Count the factors UVa 10699
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 15-04-05
*/
#include <iostream>
#include <cmath>
using namespace std;

#define sqRoot sqrt( (double) 1000000)

long seive[1000000];
long prmCol[1000000];

void genSeive();
//======================================
int main(){
	genSeive();
	long orginal, input, i;
	int prmFactor;

	while (cin >> input && input != 0){
		orginal = input;
		prmFactor = 0;
		for (i = 0; i <= 1000000 && prmCol[i] != 0; ++i){
			if ( input % prmCol[i] == 0){
				input = input / prmCol[i];
				++prmFactor;
			}
		}
		cout << orginal << " : " << prmFactor << endl;
	}	
	return 0;
}
//==========================================================

void genSeive(){
	long i, j;
	
	seive[0]=seive[1] = 1;
	for (i = 2; i <= sqRoot; ++i){
		for (j = i + i; j < 1000000; j += i)
			seive[j] = 1;
	}

	j = -1;
	for (i = 2; i < 1000000; ++i){
		if (seive[i] == 0)
			prmCol[++j] = i;
	}
}