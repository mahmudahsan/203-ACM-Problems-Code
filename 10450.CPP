/* Prblem: World Cup Noise Uva: 10450
   Programmer: Md. Mahmud Ahsan
   Date: 09-01-05
*/

#include <iostream>
#include <string>
using namespace std;

typedef long long lint;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	lint input, testCase;
	lint array[52];
	lint i;
	int cases = 0;
        int flag = 0;
	array[1] = 2;
	array[2] = 3;

	for (i = 3; i < 52; i++)
		array[i] = array[i-1] + array[i-2];
	cin >> testCase;
	for (int t = 0; t < testCase; ++t){
		cin >> input;

		cout << "Scenario #" << ++cases << ":" << endl;
		cout << array[input] << endl << endl; 
	}
	return 0;
}
