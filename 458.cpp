/* Problem: The Decoder UVa 458
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 07-08-04
*/

#include <iostream>
using namespace std;

int main(){
	int i;
	char input[200];
	char c;

	while (cin >> input){
		for (i = 0; input[i] != '\0'; i++){
			c = input[i] - 7;
			cout << c;
		}
		cout << endl;
	}
	return 0;
}