/* Problem: Odd Sum UVa 10783
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 28-11-04
*/

#include <iostream>
using namespace std;

int main(){
	int test, a, b;
	int count, k, testCase = 1;
	cin >> test;
	
	for (int i = 0; i < test; i++){
		cin >> a >> b;
		count = 0;

		if (a % 2 == 0){ 
			for (k = a + 1; k <= b; k += 2){
				count += k;
			}
		}
		else{
			for (k = a; k <= b; k += 2){
				count += k;
			}
		}
		cout << "Case " << testCase++ << ": " << count << endl;
	}
	return 0;
}