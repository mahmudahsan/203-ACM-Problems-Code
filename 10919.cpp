/* Problem: Prerequisite UVa 10919
   Programmer: Md. Mahmud Ahsan
   Description: Ad hoc
   Compiled: Visual C++ 7.0
   Date: 20-08-06
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	int arr[200], courseTaken, category, selection, minimum;
	int i, size, counter, temp;
	bool flag;

	while (cin >> courseTaken){
		if (courseTaken == 0) break;

		cin >> category;
		for (i = 0; i < courseTaken; ++i){
			cin >> arr[i];
		}
		size = i;

		sort(arr, arr+size);
		flag = true;
		for (int j = 0; j < category; ++j){
			cin >> selection >> minimum;

			counter = 0;
			for (int k = 0; k < selection; ++k){
				cin >> temp;
				if (minimum != 0 && binary_search(arr, arr+size, temp)){
					if (counter >= minimum) continue;

					++counter;
				}
			}
			if (minimum == 0) continue;

			if (counter != minimum){
				flag = false;
			}
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
