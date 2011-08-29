/* Problem: Hartals UVa 10050 PC 110203
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 04-09-04
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector <bool> days(3655); // store days
	int i, j, count; // count store the total hartals
	int t, n, parties; 
	// n = number of days
	int averDay; // days of hartals by each party

	cin >> t; // test case
	
	for (int test = 0; test < t; test++){

		count = 0;
		// initialize all to false
		for (i = 0; i < days.size(); i++)
			days[i] = false;

		cin >> n >> parties;
		
		for (j = 0; j < parties; j++){
			// each parties hartals declared
			cin >> averDay;
			// i = averDay - 1 as array index starts with 0
			for (i = averDay - 1; i < n; i += averDay){
				days[i] = true;
			}
		}

		// for friday and saturday
		days[5] = days[6] = false; 
		for (i = 5; i < n; i += 7){
			days[i] = false;
			days[i + 1] = false;
		}

		for (i = 0; i < n; i++){
			if (days[i] != false)
				count++;
		}

		cout << count << endl;
		
	}
	
	return 0;
}