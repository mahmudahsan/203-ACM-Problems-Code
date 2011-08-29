/* Problem: Draw Grid UVa 11074
   Programmer: Md. Mahmud Ahsan
   Description: Simulation + output formated
   Compiled: Visual C++ 7.0
   Date: 12-09-06
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int s, t, n, temp1, i, j, k, counter, cases = 0;
	char str[50];
	
	while (cin >> s >> t >> n){
		if (!s && !t && !n) break;

		cout << "Case " << ++cases << ":" << endl;
		counter = 0;
		temp1 = s * n + t * n + t;

		// initialize the string t + s
		for (i = 0; i < t; ++i)
			str[i] = '*';
		for (j = i; j < t+s; ++j)
			str[j] = '.';
		str[j] = '\0';


		for (i = 0; i < t; ++i){
			for (j = 0; j < temp1; ++j)
				cout << "*";
			cout << endl;
		}

		for (i = t; i < temp1 - t; ){
			++counter;
			for (j = 0; j < n; ++j)
				cout << str;
			
			for (j = 0; j < t; ++j)
				cout << "*";
			cout << endl;

			if (counter == s){
				counter = 0;
				
				for (int m = 0; m < t; ++m){
					for (int n = 0; n < temp1; ++n)
						cout << "*";
					cout << endl;
				}
				i += t;
			}
			++i;			
		}
		cout << endl;
	}

	return 0;
}
