/* Problem: Encoder and Decoder  UVa 444
   Programmer: Md. Mahmud Ahsan
   Description: String processing, reversing, given ascii code only
   Compiled: Visual C++ 7.0
   Date: 10-07-05
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	char str[1005];
	int i, n, len;
		while (cin.getline(str, sizeof(str))!= NULL){
		len = strlen(str);
		reverse(str, str+len);
		
		n = 0;
		if ( (str[0] -48) >= 0 && str[0]-48 <= 9){
			for (i = 0; str[i]; ++i){
				n = n * 10 + str[i]-48;
				if ( (n >= 65 && n <= 90) || (n >= 97 && n <= 122) || n == 32 || n == 33 
					||n == 44 || n == 46 || n == 58 || n == 59 || n == 63){
					cout << (char) n;
					n = 0;
				}
			}
		}
		else{
			for (i = 0; str[i]; ++i){
				n = str[i];
				while (n != 0){
					cout << n % 10;
					n = n / 10;
				}
			}
		}
		cout << endl;
	}
	return 0;
}