/* Problem: Mother Bear UVa 10945
   Programmer: Md. Mahmud Ahsan
   Description: String
   Compiled: Visual C++ 7.0
   Date: 18-02-06
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char str[100000], modified[100000];

bool isPalindrome(){
	int i, len = strlen(modified)-1;

	for (i = 0; i <= len/2; ++i){
		if (tolower(modified[i]) != tolower(modified[len-i])) return false;
	}
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int i, j;

	while (cin.getline(str, sizeof(str))){
		if (strcmp(str, "DONE") == 0) break;

		i = 0;
		for (j = 0; j < str[j]; ++j){
			if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
				modified[i++] = str[j];
		}
		modified[i] = '\0';
		
		if (isPalindrome())
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}
	return 0;
}
