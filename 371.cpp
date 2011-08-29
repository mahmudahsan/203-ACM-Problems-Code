/* Problem: Ackermann Functions UVa 371
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++
   Date: 05-08-04
*/

#include <iostream>
using namespace std;

// typedef
typedef long long int llint;

// prototypes
llint cycleLength(llint);
void show(llint l, llint h, llint value, llint max);

//===================================================================
int main(){
	llint l, h, temp, value, max; // l means lower, h means higher
								  // value that generates max length
	int i; // for counter loop

	while (cin >> l >> h){
		if (l == 0 && h == 0) break;

		// swapping the lower and higher 
		if (l > h){
			temp = l;
			l = h;
			h = temp;
		}

		value = 0;
		max = 0;

		for (i = l ; i <= h; i++){
			temp = cycleLength(i);
			if (temp > max) {
				max = temp;
				value = i;
			}
		}
		show(l, h, value, max);
	}

	return 0;
}
//=================================================================
llint cycleLength(llint n){
	int i = 0;
	do{
		if ((n % 2) == 0)
			n = n / 2;
		else
			n = 3 * n + 1;
		
		i++;
	} while (n != 1);
	return i;
}

void show(llint l, llint h, llint value, llint max){
	cout << "Between " << l << " and " << h << ", " << value << " generates the longest sequence of " << max << " values." << endl;
}