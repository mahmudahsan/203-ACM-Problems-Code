/* Problem: Children's Game UVa 10905
   Programmer: Md. Mahmud Ahsan
   Description: Radix Sort
   Compiled: Visual C++ 7.0
   Date: 26-09-05
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int comp(const void *_a, const void *_b){
	char *a = (char*) _a;
	char *b = (char*) _b;

	char temp1[100], temp2[100];
	if (strlen(a) == strlen(b))
		return (strcmp(a, b) < 0);
	else if(strlen(a) != strlen(b)){
		strcpy(temp1, a);
		strcat(temp1, b);
		strcpy(temp2, b);
		strcat(temp2, a);

		return (strcmp(temp1, temp2) < 0);
	}
	return 1;
}

int main(){
	char str[55][100];

	int i, n;
	while (cin >> n){
		if (n == 0) break;
		
		for (i = 0; i < n; ++i)
			cin >> str[i];
		
		qsort(str, n, sizeof(str[0]), comp);
		for (i = 0; i < n; ++i)
			cout << str[i];
		cout << endl;
	}

	return 0;
}