/* Problem:   Pig-Latin  UVa 492
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC
   Compiled: Visual C++ 7.0
   Date: 20-08-05
*/

#include <iostream>
#include <cctype>
using namespace std;

int main(){
	int state, save;
	char c, temp, saveChar;

	state = 0;
	while ( (c=cin.get()) && !cin.eof()){
		//state is used to detect for the first letter 
		if (state == 0 && ( (c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z'))){
			state = 1;
			temp = tolower(c); // converting temporarily lower case
			if (temp=='a'||temp=='e'||temp=='i'||temp=='o'||temp=='u'){
				cout << c;//but always print the orginal case
				save = 0;// no consonent at the first letter of the word
			}
			else{
				saveChar = c;
				save = 1;
			}	
		}
		else if( (c>='a' && c<='z') || (c>='A' && c<='Z')){
			//letter other than the first letter of a word
			cout << c;
		}
		else{
			//when a word finish
			if (state == 1 && save == 1){
				//for consonent
				cout << saveChar << "ay";
				state = save = 0;
			}
			else if (state == 1){// for vowel
				cout << "ay";
				state = 0;
			}
			
			//for other sumbol, space, newline, digit etc
			cout << c;		
			
		}
	}

	return 0;
}