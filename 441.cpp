/* Problem: Lotto UVa 441
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC, identify loop
   Compiled: Visual C++ 7.0
   Date: 26-07-05
*/
#include <iostream>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, array[30];
	int a, b, c, d, e, f, i;

	bool flag = false;

	while (cin >> n){
		if (!n) break;
		for (i = 0; i < n; ++i)
			cin >> array[i];

		if (flag) cout << endl; flag = true;

		for (a = 0; a < n-5; ++a)
			for (b = a + 1; b < n - 4; ++b)
				for (c = b + 1; c < n - 3; ++c)
					for (d = c + 1; d < n - 2; ++d)
						for (e = d + 1; e < n - 1; ++e)
							for (f = e + 1; f < n; ++f){
								cout << array[a] << " " << array[b] << " " << array[c] << 
									" " << array[d] << " " << array[e] << " " << array[f] << endl;
							}
	}

	return 0;
}
