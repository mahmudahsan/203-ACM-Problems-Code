/* Problem: Parity UVa 10931
   Programmer: Md. Mahmud Ahsan
   Description: Ad hoc
   Compiled: Visual C++ 7.0
   Date: 17-02-06
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long n, p, r;
	int j;
	char bin[100];

	while (cin >> n){
		if (n == 0) break;

		p = 0;
		j = 0;
		while (n != 0){
			r = n % 2;
			n = n / 2;
			p += r;
			bin[j++] = r + 48;
		}
		bin[j] = '\0';
		reverse(bin, bin+j);
		cout << "The parity of " << bin << " is " << p << " (mod 2)." << endl;
	}

	return 0;
}
