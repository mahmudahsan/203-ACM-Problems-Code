/* Problem: Big Mod  UVa 374
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++
   Date: 05-08-04
*/


#include <iostream>
using namespace std;

typedef long long int lint;

// prototypes
lint square(lint n);
lint bigMod(lint b, lint p, lint m);

//================================================
int main(){
	lint b, p, m;
	lint result;

	while (cin >> b >> p >> m){
		result = bigMod(b, p, m);
		cout << result << endl;
	}
	return 0;
}
//=================================================

lint square(lint n){
	return n * n;
}

// The main part is shown below 
// This is called dynamic programming
lint bigMod(lint b, lint p, lint m){
	if (p == 0) return 1;
	else if (p % 2 == 0) 
		return square(bigMod(b, p / 2, m) %m) %m;
	else
		return ((b % m) * bigMod(b, p - 1, m) %m) %m;
}