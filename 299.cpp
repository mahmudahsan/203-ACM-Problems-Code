/* Problem: Train Swaping UVa 299 
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
*/

#include <iostream>
using namespace std;

int bubbleSort(long int array[], long int size){
	long int i, j, temp, result = 0;

	for (i = 0; i < size; i++){
		for (j = 0; j < size-1; j++){
			if (array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				result += 1;
			}
		}
	}
	return result;
}


int main(){
	long int array[1000];
	long int n, i, j, inFirst, inSecond, result;

	cin >> n;
	for (i = 0; i < n; i++){
		cin >> inFirst;
		for (j = 0; j < inFirst; j++){
			cin >> array[j];
		}
		result = bubbleSort(array, inFirst);
		cout << "Optimal train swapping takes " << result << " swaps." << endl;
	}
	cout << endl;
	return 0;

}