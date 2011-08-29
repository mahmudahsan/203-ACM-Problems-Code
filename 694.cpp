/* Problem: The Collatz Sequence  UVa 694
   Programmer: Md. Mahmud Ahsan
   Compiled: Linux GNU C++
   Date: 05-08-04
*/

/*********************************************************************
We have to follow the 3n + 1 law for the initial value a's input. if a == 1 break
By computing Step 4, if a > l (limit value) then break without counting length of sequence
We have to use do - while loop
***********************************************************************/
#include <iostream>
using namespace std;

// typedef 
typedef long long int llint;

// prototypes
llint cycle(llint, llint);
void show(int, llint, llint, llint);

//====================================================================
int main(){
	llint a, l, temp, max;  // a means first input and l means last input
	static int count = 0;
	while (cin >> a >> l){
		if (a < 0 && l < 0) break;
		
		// always keep a to lower value
		if (a > l){
			temp = a;
			a = l;
			l = temp;
		}

		max = cycle(a, l);

		++count;
		// print the desired output
		show(count, a, l, max);
	}
	return 0;
}
//====================================================================

llint cycle(llint a, llint l){ // a means first input, l means last input
	int i = 1;

	do{
		// applying 3n + 1 law with modification
		if (a % 2 == 0){
			a = a / 2;
			++i;
		}
		else{
			a = 3 * a + 1;
			if (a > l) break; // if a > l not count the sequence
			++i;
		}
	}while (a != 1);
	
	return i;
}

void show(int i, llint a, llint l, llint max){
	cout << "Case " << i << ": A = " << a << ", limit = " << l << ", number of terms = " << max << endl;
}