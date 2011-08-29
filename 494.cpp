/* Problem:  Kindergarten Counting Game  UVa 494
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 25-08-04
*/

#include <iostream>
using namespace std;

int main(){
	char c;
	bool flag = false; // remember the first character of a word if letter
	int words = 0;

	c = cin.get();
	while (!cin.eof()){	// untile the end of the file is reached	
		
		while (c != '\n'){ // for per line
			if (( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
				if (!flag){
					// if false
					flag = true;
					words++;
				}
			}
			else
				flag = false;

			c = cin.get();
		}

		cout << words << endl;
		words = 0;
		flag = false;
		c = cin.get();
	}

	return 0;
}