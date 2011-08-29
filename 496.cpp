/* Problem: Simply Subsets UVa 496
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-05-04
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	char strA[5000], *ptr;
	char strB[5000];

	int arrayA[1000], arrayB[1000];
	int i, j, lengthA, lengthB, count;
	bool emptyA, emptyB;

	while (cin.getline(strA, sizeof(strA))){
		cin.getline(strB, sizeof(strB));
		
		emptyA = emptyB = true;
		count = 0;
		// for string A
		ptr = strtok(strA, " \t\n");
		i = 0;
		while (ptr){
			arrayA[i++] = atoi(ptr);
			ptr = strtok(NULL, " \t\n");
		}
		lengthA = i;
		// for string B
		ptr = strtok(strB, " \t\n");
		i = 0;
		while (ptr){
			arrayB[i++] = atoi(ptr);
			ptr = strtok(NULL, " \t\n");
		}
		lengthB = i;

		for (i = 0; i < lengthA; ++i){
			for (j = 0; j < lengthB; ++j){
				if (arrayA[i] == arrayB[j]){
					++count;
					arrayA[i] = 0;
					arrayB[j] = 0;
				}
			}
		}
		
		for (i = 0; i < lengthA; ++i){
			if (arrayA[i] != 0)
				emptyA = false;
		}

		for (i = 0; i < lengthB; ++i){
			if (arrayB[i] != 0)
				emptyB = false;
		}

		if (emptyA && emptyB)
			cout << "A equals B" << endl;
		else if (!emptyA && !emptyB && count)
			cout << "I'm confused!" << endl;
		else if (!emptyA && !emptyB)
			cout << "A and B are disjoint" << endl;
		else if (emptyA && !emptyB)
			cout << "A is a proper subset of B" << endl;
		else if (!emptyA && emptyB)
			cout << "B is a proper subset of A" << endl;		
	}
	return 0;
}