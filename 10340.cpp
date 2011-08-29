/* Problem:  All in All   UVa 10340
   Programmer: Md. Mahmud Ahsan
   Description: SET
   Compiled: Visual C++ 7.0
   Date: 13-02-06
*/

#include <iostream>
#include <string>
using namespace std;

const int MX = 5000000;
char s[MX], t[MX];

bool chkSub(){
	int lenS = strlen(s);
	int lenT = strlen(t);
	int i, m = 0;

	for (i = 0; i < lenT; ++i){
		if (s[m] == t[i]){
			++m;
			if (m >= lenS)
				return true;
		}
	}
	return false;
}

int main(){
	while (cin >> s >> t){
		if (chkSub())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
