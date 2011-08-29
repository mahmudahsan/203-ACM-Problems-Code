/* Problem: Secret Research  UVa 621
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++
   Date: 28-12-04
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	char str[1000];
	int len, test;
	
	cin >> test;
	for (int i = 0; i < test; i++){
		cin >> str;
		len = strlen(str);
		
		if (len == 1){
			if (str[0] == '1' || str[0] == '4')
				cout << '+' << endl;
		}
		else if (len == 2){
			if (str[0] == '7' && str[1] == '8')
				cout << '+' << endl;
		}
		if (len >= 3){
			if (str[len-1] == '5' && str[len-2] == '3')
				cout << '-' << endl;
			else if (str[len-1] == '4' && str[0] == '9')
				cout << '*' << endl;
			else if (str[0] == '1' && str[1] == '9' && str[2] == '0')
				cout << '?' << endl;
		}	
	}
	return 0;
} 
