/* Problem: Flip Short UVa 10327
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
*/

#include <iostream.h>

int bubble(int array[], int size){
	int i, j, exchange, temp;

	exchange = 0;

	for (i = 0; i < size; i++){
		for (j = 0; j < size - 1; j++){
			if (array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				exchange += 1;
			}
		}
	}
	return exchange;
}


int main(){
	int *p;
	int n, i, exchange;

	while (cin >> n){
		p = new int[n];
		for (i = 0; i < n; i++){
			cin >> p[i];
		}

		exchange = bubble(p, n);
		cout << "Minimum exchange operations : " << exchange << endl;
	}
	delete [] p;
	return 0;
}