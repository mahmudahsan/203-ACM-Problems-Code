/* Problem: Decode the Mad man  UVa 10222
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 07-08-04
*/

#include <iostream>
using namespace std;

int main(){
	/* store the code special rules [ \\ \' ] */
	char string[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	char input[10000];
	int i, j;
	int flag;
	
	while (cin.getline(input, sizeof(input))){
		for (i = 0; input[i] != '\0'; i++){
			flag = 0; //check input character is found int the string code
			for (j = 0; string[j] != '\0'; j++){
				if (input[i] == string[j]){
					cout << string[j-2]; // print the previous - 1 character
					flag = 1; // ensure that input character is found in the code
					break;			
				}
			}
			if (flag == 0) cout << input[i];
		}
		cout << endl;
	}
	return 0;
}
		