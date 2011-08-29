/* Problem: Box of Bricks UVa 591
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 06-08-04
*/

#include <iostream>
#include <cstdlib>
using namespace std;

//prototypes

int move(int array[], int size);

//==========================================================
int main(){
	//freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

	static int set = 0;
	int *p; // dynamic memory allocation
	int input, result;
	int i;

	while (cin >> input){
		if (input == 0) break;
		p = new int[input];
		for (i = 0; i < input; i++)
			cin >> p[i];
			
		result = move(p, input);
		cout << "Set #" << ++set << endl;
		cout << "The minimum number of moves is " << result << "." << endl;
		cout << endl;
		delete [] p;
	}
	return 0;
}
//==========================================================

int move(int array[], int size){
	int i, total, average;
	int temp;

	total = 0;
	temp = 0;
	for (i = 0; i < size; i++)
		total += array[i];

	average = total / size; // for average height

	for (i = 0; i < size; i++)
		// check which pillar is larger or smaller than the average height
		temp += abs(array[i] - average);
	
	// because move can be happen only one time
	return temp / 2;
}
