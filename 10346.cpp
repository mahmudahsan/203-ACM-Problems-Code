/* Problem: Peter’s Smokes UVa 10346
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 09-01-05
*/

#include <iostream.h>

int main(){
	int n, k, m, total;

	while (cin >> n >> k){
		total = n;
		while (n >= k){
			if (n % k == 0)
				m = 0;
			else
				m = n % k;
			n = n / k;
			total = total + n;
			n = n + m;
		}
		cout << total << endl;
	}

	return 0;
}