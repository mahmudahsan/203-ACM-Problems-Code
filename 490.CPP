/* Problem:  Rotating Sentences   UVa 490
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-04-05
*/

#include <stdio.h>
#include <iostream.h>
#include <string.h>

int main(){
	char str[105][105];
	int array[105];
	int n, i, j, k, max;

	i = 0;
	max = 0;

	while (cin.getline(str[i], sizeof(str)) != NULL){
	       n = strlen (str[i]);
	       if (n > max)  max = n;
	       array[i] = n;
	       ++i;
	}

	i = i - 1;

	for(k = 0; k < max; ++k){
		for(j = i; j >= 0; --j){
			if (k >= array[j])
				cout << " ";
			else
				cout << str[j][k];
		}
		cout << endl;
	}
	return 0;
}