/* Problem: Jolly Jumpers UVa 10038
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 29-09-04
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
	int input; // for test case
	int i;
	int last, next, result; // temporary used for set the places
	bool flag; // check if jolly or not jolly

	while (cin >> input){
		// each time place will automatically initialized to zero
		vector <bool> place(3005);
		flag = true;
		
		cin >> last;
		// i = 1 as first input take before it
		for (i = 1; i < input; i++){
			cin >> next;
			result = abs(last - next);
			place[result] = true;
			last = next;
		}

		// main condition successive elements take place
		for (i = 1; i < input; i++)
			if (!place[i]){
				flag = false;
				break;
			}

		if (flag)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}