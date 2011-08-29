/* Problem: Beat the Spread UVa 10812
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 09-05-05
*/
#include <iostream>
using namespace std;

int main(){
	long n, sum, diff, x, y, temp;
	cin >> n;
	long i;
	for (i = 0; i < n; ++i){
		cin >> sum >> diff;

		

		temp = sum + diff;
		x = temp /2;
		y = sum - x;

		if ((diff > sum) || (temp % 2 != 0)){
			cout << "impossible" << endl;
			continue;
		}

		if (x < y){
			temp = x;
			x = y;
			y = temp;
		}
		cout << x << " " << y << endl;
	}

	return 0;
}