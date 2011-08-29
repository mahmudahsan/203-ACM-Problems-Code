/* Problem: How Many Points of Intersection? UVa 10790
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 07-01-05
*/
 
#include <iostream>
using namespace std;

typedef long long lint;

int main(){
	int cases = 0;
	lint m, n, result;

	while (cin >> m >> n){
		if (!m && !n) break;

		result = (( (m*(m-1))/2) * (n*(n-1)/2));
		cout << "Case " << ++cases << ": " << result << endl;
	}

	return 0;
}