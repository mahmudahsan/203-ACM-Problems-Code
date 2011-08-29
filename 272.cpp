/* Problem: TeX Quotes UVa 272
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 08-08-04
*/

#include <iostream>
#include <cstdio>
using namespace std;

//======================================================
int main(){
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

	char string[1000000]; // buffer where the lines stored
	char c;
	int i = 0;

	do{
		c = cin.get(); // it also takes '\n' character
		string[i] = c;
		i++;
	}while (c != EOF); // until ctrl + z is pressed
	
	string[i] = '\0';
	
	// root work
	int check = 1; // if 1 then first target, if 2 then second target
	
	for (i = 0; string[i]; i++){
		if (string[i] == '\"'){
			if (check % 2 != 0){
				// for first target
				cout << "``";
				check++;
				continue; // leave the rest process
			}
			else if (check % 2 == 0){
				// for second target
				cout << "''";
				check--;
				continue;
			}
		}
		// general print
		if (string[i] == EOF);
		else
			cout << string[i];
	}
	//complete root work 
	return 0;
}
//=======================================================
