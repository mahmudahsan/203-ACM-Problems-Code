/* Problem: Combination UVa 369
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 15-12-04
*/

#include <iostream>
using namespace std;

typedef long long lint;

lint nCr(lint n, lint r);
//===============================================
int main(){
	lint n, r, nMr;
	lint result;

	while (cin >> n >> r){
		if (!n && !r) break;
                
                nMr = r;
		if (n-r < r){
			nMr = n-r;			
		}

		result = nCr(n, nMr);
		cout << n << " things taken " << r << " at a time is " << result << " exactly." << endl;
	}
	return 0;
}
//===============================================
lint nCr(lint n, lint r){
	lint i;
	lint k, prod;

	prod = 1;
	k = n;

	for (i = 1; i <= r; ++i)
		prod = (prod * k--) / i;
	return prod;
}