/* Problem: Lunch in Grid City UVa 855
   Programmer: Md. Mahmud Ahsan
   Description: Sorting + Median
   Compiled: Visual C++ 7.0
   Date: 09-12-05
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

inline bool comp(int a, int b){
	return a < b;
}

int street[50000], avenue[50000];

int main(){
	int T, median, s, a, f, i;

	cin >> T;
	while (T--){
		cin >> s >> a >> f;
		for (i = 1; i <= f; ++i){
			cin >> street[i] >> avenue[i];
		}
		sort(street, street+f, comp);
		sort(avenue, avenue+f, comp);

		median = ceil(f / 2.0);
		
		cout << "(Street: " << street[median] << ", Avenue: " << avenue[median] <<")" << endl;

	}

	return 0;
}