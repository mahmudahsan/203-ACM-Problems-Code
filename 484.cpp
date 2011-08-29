/* Problem:  The Department of Redundancy Department  UVa 484
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC
   Compiled: Visual C++ 7.0
   Date: 20-08-05
*/
#include <iostream>
#include <vector>
using namespace std;

int count[50000][2];
vector <int> v;

int main(){
	int i, j, k, n ,total;

	while (cin >> n){
		v.push_back(n);
	}

	j = 0;
	int siz = v.size();
	for (i = 0; i < siz; ++i){
		if (v[i] == -777979)
			continue;
		total = 1;
		for (k = i+1; k < siz; ++k){
			if (v[i] == v[k]){
				++total;
				v[k] = -777979; // marking for this item searched prev
			}
		}
		count[j][0] = v[i];
		count[j][1] = total;
		++j;		
	}
	for (i = 0; i < j; ++i){
		cout << count[i][0] << " " << count[i][1] << endl;
	}
	return 0;
}