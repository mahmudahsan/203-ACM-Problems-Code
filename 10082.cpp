/* Problem: WERTYU UVa 10082
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 07-08-04
*/

#include <iostream>
using namespace std;

int main(){
	/* store the code some rules [ \\ \' ] */ 
	char string[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
	char input[200];
	int i, j;
	int flag;

	while (cin.getline(input, sizeof(input))){
		for (i = 0; input[i] != '\0'; i++){
			flag = 0; // chekc if other character that not in the code
			for (j = 0; string[j] != '\0'; j++){
				if (input[i] == string[j]){
					cout << string[j-1]; // print the previous character
					flag = 1; // if character found in the string code than say no
					break;
				}
			}
			if (flag == 0) cout << input[i];
		}
		cout << endl;
	}
	return 0;
}
		