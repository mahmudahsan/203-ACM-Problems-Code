/* Problem: Zeros And Ones UVa 10324
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 06-04-05
*/
#include <iostream>
using namespace std;

char str[1000005], tt[10];
long data[1000005];

          
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long cases, i, j, k,l, counter;
	char c;
	cases = 0;

	while ( cin.getline(str, sizeof(str))){
		k = strlen(str);
		
		if (k == 0) break;
		
		counter = 0;
		l = -1;
		c = str[0];

		for(i = 0; i < k; ++i){
			if (c != str[i]){
				c = str[i];
				++counter;
			}
			data[++l] = counter;
		}

		cin >> k;
		cout << "Case " << ++cases << ":"<< endl;
		for(l = 0; l < k; ++l){
			cin >> i >> j;
			if (data[i] == data[j])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cin.getline(tt, sizeof(tt)); // eat blankline
	}
	return 0;
}
