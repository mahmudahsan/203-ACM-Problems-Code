/* Problem: List of Conquests UVa 10420
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 18-10-04
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// cmp function for quick sort
int cmp(const void *a, const void *b){
	return strcmp( (char*) a, (char*) b);
}

int main(){
	char str[2200][100]; // list of countries
	char temp[100];
	int input;
	int i, j;

	cin >> input;

	for (i = 0; i < input; i++){
		cin >> str[i];
		cin.getline(temp, sizeof(temp)); // to ignore woman's name
	}
	
	qsort(str, input, sizeof(str[0]), cmp); // alphabetical order 
	
	int count;
	for (i = 0; i < input; i+= count){
		count = 0;
		cout << str[i] << " ";
		for (j = i; j < input; j++){
			if (strcmp(str[i], str[j]) == 0)
				++count;
		}
		cout << count << endl;
	}
	return 0;
}

