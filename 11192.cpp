//11192
#include <iostream>
#include <string>
using namespace std;

const int MX = 1000;

int main(){
	int n, i, k;
	string s;
	char buff[MX];

	while (cin >> n){
		if (n == 0) break;
		cin >> s;

		n = s.size() / n;
		k = 0;
		for (i = 0; i < s.size(); ++i){
			if (k == n){
				for (int j = k-1; j >= 0; --j)
					cout << buff[j];
				k = 0;				
			}
			buff[k++] = s[i];
		}
		for (int j = k-1; j >= 0; --j)
				cout << buff[j];
		cout << endl;
	}

	return 0;
}
