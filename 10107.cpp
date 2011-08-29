/* Problem: What is Median? UVa 10107
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 11-12-04
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

typedef long lint;

// prototypes
void insertionSort(lint array[], lint size);

//==========================================
int main(){
	//ifstream fin("input.in");
	//cin = fin;
	lint i = 0;
	lint sum, med;
	lint array[10005];

	while (cin >> array[i]&& !cin.eof()){
		insertionSort(array, i+1);
		if (i % 2 == 1) {
			// if i is even as array begins 0 so here checking system differ
			med = i / 2;
			sum = array[med] + array[med + 1];
			sum = sum / 2;
			cout << sum << endl;
		}
		else{
			med = i / 2;
			cout << array[med] << endl;
		}
		++i;
	}
	return 0;
}
//=========================================
void insertionSort(lint array[], lint size){
	int i, j, key;
	
	for (j = 1; j < size; j++){
		key = array[j];
		i = j - 1;

		while (i >= 0 && array[i] > key){
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}