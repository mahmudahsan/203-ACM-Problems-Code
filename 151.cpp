/* Problem: Power Crisis  UVa 151
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 12-04-05
*/

#include <iostream>
using namespace std;

int array[101], data[101];

int main(){
	int i, j, k, l, counter, counts;
	bool flag;
	int dFinal = 12; // to store variable 13<=n<100
	for (i = 13; i < 101; ++i){
		for (j = 1; j <= 1000; ++j){

			for (l = 1; l <= i; ++l)
				array[l] = 0;
			
			flag = true;
			// counter used for counting how many array[zeros] exists
			counter = counts = 0;
			array[1] = 1;
			k = 1;		
			// main calculation
			while (counter != (i-2)){
				k = (k % i) + 1;
				if (array[k] == 0)
					counts++;
				if (counts == j){
					array[k] = 1;
					if (array[13] == 1){
						flag = false;
						break;
					}
					counts = 0;
					counter++;
				}
			}
			if (flag){
				data[++dFinal] = j;
				break;
			}
		}
	}

	int input;
	while (cin >> input){
		if (input == 0) break;
		cout << data[input] << endl;
	}
	return 0;
}