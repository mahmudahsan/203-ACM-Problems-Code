/* Problem: Hay Points UVa 10295
   Programmer: Md. Mahmud Ahsan
   Description: Sorting + Searching 
   Compiled: Visual C++ 7.0
   Date: 18-09-05
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct word{
	string str;
	int dollar;
}dics[1200];

inline bool comp(word a, word b){
	if (a.str > b.str) return false;
	return true;
}	

int binarySearch(string a, int h){
	int low, mid, high = h;
	low = 0;

	while (low <= high){
		mid = (high + low) / 2;
		
		if (dics[mid].str == a)
			return mid;
		else if (dics[mid].str < a)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main(){
	int m, n, k, i, dollar;
	string a;

	while (cin >> m >> n){
		for (i = 0; i < m; ++i)
			cin >> dics[i].str >> dics[i].dollar;
		
		sort(dics, dics+m, comp);
		
		for (i = 0; i < n; ++i){
			dollar = 0;
			while (cin >> a){
				if (a == ".") break;
				
				k = binarySearch(a, m);
				if (k != -1)
					dollar += dics[k].dollar;
			}
			cout << dollar << endl;
		}
	}

	return 0;
}