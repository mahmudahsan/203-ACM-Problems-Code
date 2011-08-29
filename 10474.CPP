/* Problem: Where is the Marble? UVa 10474
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-05-04
*/
#include <iostream.h>
#include <stdlib.h>
//using namespace std;

// use for built in quick sort
int cmp_func(const void *a, const void * b){
	int *_a, *_b;
	_a = (int *) a;
	_b = (int *) b;
	if ( *_a < *_b) return -1;
	else if (*_a == *_b) return 0;
	else return 1;
}

int linearSearch(int array[], int n, int item);
//===============================================
int main(){
	int *data;
	int n, q, result, query;
	int i, cases = 0;

	while (cin >> n >> q){
		if (n == 0 && q == 0) break;

		data = new int[n];
		for (i = 0; i < n; ++i)
			cin >> data[i];

		qsort(data, n, sizeof(data), cmp_func);

		cout << "CASE# " << ++cases << ":" << endl;
		for (i = 0; i < q; ++i){
			cin >> query;
			result = linearSearch(data, n, query);

			if (result != -1){
				cout << query << " found at " << ++result << endl;
			}
			else
				cout << query << " not found" << endl;
		}
		delete[] data;
	}
	return 0;
}
//================================================
int linearSearch(int array[], int n, int item){
	int i;
	for (i = 0; i < n; ++i){
		if (array[i] == item)
			return i;
	}
	return -1;
}