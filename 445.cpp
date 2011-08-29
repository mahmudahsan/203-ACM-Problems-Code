/* Problem: Marvelous Mazes UVa 445
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 11-09-04
*/
#include <iostream>
using namespace std;

int main(){
	// c for select one character
	char c, str[200];
	// in contains integer converted from character
	// temp counts the total summation for multiple digit
	int in, temp;
	int i, j;
	
	while (cin.getline(str, sizeof(str))){
		temp = 0;
		for (i = 0; str[i]; i++){
			c = str[i];
			if (c >= '1' && c <= '9'){
				in = c - 48; // conver character to integer
				temp += in;
				continue;
			}

			if(c == 'b'){
				for (j = 0; j < temp; j++)
					cout << " ";
				temp = 0;
				continue;
			}
			else if(c == '!' || c == '\0'){
				cout << endl;
				continue;
			}
			// if no special character found then			
			for (j = 0; j < temp; j++)
				cout << c;
			temp = 0;
		}
		cout << endl;
	}
	return 0;
}