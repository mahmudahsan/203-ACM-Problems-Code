/* Problem: Dollar UVa 147
   Programmer: Md. Mahmud Ahsan
   Description: Counting Change
   Compiled: Visual C++ 7.0
   Date: 25-08-05
*/
#include <iostream>
#include <cstdio>
using namespace std;

#define max 7000

//multiplying by 100 to convert cent to dollar
//then divide by 5,coz every input is multiple of 5
int coin[11] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
long long nway[max];

void init(){
	for (int i = 0; i < max; ++i)
		nway[i] = 0;
}

int main(){
	int i, j, c, v = 11, intAmount;
	double n;
	
	while (cin >> n){
		if (n == 0.00) break;
		
		init();
		nway[0] = 1;
		intAmount = (int) (n * 100 + .5);//to make larger than .5 makes a 1
		intAmount = intAmount / 5; // multiple of 5 said in problem
		
		for (i = 0; i < v; ++i){
			c = coin[i];
			for (j = c; j <= intAmount; ++j)
				nway[j] += nway[j-c];
		}

		printf("%6.2lf", n);
		cout.width(17);
		cout << nway[intAmount] << endl;
	}
	return 0;
}