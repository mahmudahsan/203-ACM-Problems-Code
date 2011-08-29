/* Prob: Brownie Points UVA: 10865
Programmer: Md. Mahmud Ahsan
Desc: Using x,y coordinate
Visual C++
Online contest
*/

#include <iostream>
using namespace std;

struct k{
	long x, y;
}A[ 200000];

int main(){
	long i, n, mid;
	long stan, ollie;
	while (cin >> n){
		stan = ollie = 0;
		if (n == 0) break;
		mid = n / 2;

		for (i = 0; i < n; ++i){
			cin >> A[i].x >> A[i].y;
		}

		for (i = 0; i < n; ++i){
			if (A[i].x < A[mid].x && A[i].y > A[mid].y)
				++stan;
			else if (A[i].x > A[mid].x && A[i].y < A[mid].y)
				++stan;
			else if (A[i].x > A[mid].x && A[i].y > A[mid].y)
				++ollie;
			else if (A[i].x < A[mid].x && A[i].y < A[mid].y)
				++ollie;
		}
		cout << ollie << " " << stan <<endl;
	}
	return 0;
}
