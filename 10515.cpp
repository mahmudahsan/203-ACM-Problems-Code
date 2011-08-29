/* Problem: Power et. All UVa 10515
   Programmer: Md. Mahmud Ahsan
   Description: Number Theory
   Compiled: Visual C++ 7.0
   Date: 21-02-06
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int myPow(int m, int n){
	int total;
	if (m == 0) return 0; //base 0
	if (n == 0) //powe 0
		total = 1;
	else
		total = m;

	for (int i = 1; i < n; ++i){
		total = total * m;
		total = total % 10;
	}
	return total;
}

int main(){
	//freopen("input.txt", "r", stdin);
	string m, n;
	int _m, _n, temp;

	while (cin >> m >> n){
		if (m == "0" && n == "0") break;
		
		_m = m[m.size()-1] - 48;
		if (n.size() >= 2){ // we need n's last two digit
			temp = n[n.size()-1] - 48;
			_n = (n[n.size()-2]-48) * 10 + temp;
		}
		else
			_n = n[n.size()-1]-48;

		if (_n == 0){ //last two digit zero then
			temp = myPow(_m, 99); //_m ^ 100 = _m ^ 99 * _m
			temp = (temp * _m) % 10;	
		}
		else
            temp = myPow(_m, _n) % 10;
		cout << temp << endl;

	}
	return 0;
}
