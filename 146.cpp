/* Problem: ID Codes UVa 146
   Programmer: Md. Mahmud Ahsan
   Description: Permutation, STL USED here
   Compiled: Visual C++ 7.0
   Date: 17-08-05
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	char str[200];
	int n;
	while (cin >> str){
		if (str[0] == '#') break;

		n = strlen(str);
		if (next_permutation(str, str+n))
			copy(str, str+n, ostream_iterator<char>(cout));
		else
			cout << "No Successor";
		cout << endl;
	}

	return 0;
}