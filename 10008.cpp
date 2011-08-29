/* Problem: What's Cryptanalysis? UVa 10008
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 26-11-04
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

namespace scope{
	char alphabet[130][2];
}

void init();
void checkCharacter(char *str);
void display();
void myStrlwr(char *str);
//================================================
int main(){
	char str[900];
	int input;
	int i;

	init();
	
	cin >> input;
	
	for (i = 0; i <= input; i++){
		cin.getline(str, sizeof(str));
		myStrlwr(str);
		checkCharacter(str);
	}
	
	display();
	return 0;
}
//===============================================
void init(){
	for (int i = 96; i < 130; i++){
		scope ::alphabet [i][0] = i;
		scope ::alphabet[i][1] = '0';
	}
}

void checkCharacter(char *str){
	int i;
	for (i = 0; str[i]; i++){
		if (str[i] >= 'a' && str[i] <= 'z'){
			scope ::alphabet[str[i]][1] += 1;
		}
	}
}

using namespace scope;
void display(){
	int i, j, max;
	char ch;

	max = 0;
	for (i = 96; i < 130; i++){
		if ((alphabet[i][1] - 48) > max)
			max = alphabet[i][1] - 48;
	}
	

	for (i = max; i > 0; --i){
		for (j = 96; j < 130; j++){
			if ((alphabet[j][1] - 48) == i){
				ch = alphabet[j][0];
				cout << (char )toupper(ch) << " " << alphabet[j][1] << endl;
			}
		}
	}
}

void myStrlwr(char *str){
	int i;
	for (i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
}