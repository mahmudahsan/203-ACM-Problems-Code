/* Problem: Throwing cards away I  UVa 10935
   Programmer: Md. Mahmud Ahsan
   Description: Simulation + Data Structure
   Compiled: Visual C++ 7.0
   Date: 18-02-06
*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int r, dis;
deque <int> v;

void odd(int n){
	int i;

	cout << "Discarded cards:";
	cout << " 1";

	for (i = 3; i <= n; i += 2){
		cout << ", " << i;
		v.push_back(i-1);
	}

	while (!v.empty()){
		r = v[0]; 
		v.pop_front();
		
		if (v.empty()) break;
		dis = v[0];
		v.pop_front();
		cout << ", " << dis;
		if (!v.empty())
			v.push_back(r);
	}

	cout << "\nRemaining card: " << r << endl;
}

void even(int n){
	int i;
    
	cout << "Discarded cards:";
	cout << " 1";
	for (i = 3; i <= n; i += 2){
		cout << ", " << i;
		v.push_back(i-1);
	}
	v.push_back(n);

	while (!v.empty()){
		dis = v[0]; 
		v.pop_front();

		cout << ", " << dis;
		if (!v.empty()){
			r = v[0];
			v.pop_front();

			if (v.empty()) break;
			v.push_back(r);
		}
	}
	cout << "\nRemaining card: " << r << endl;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, i;

	while (cin >> n){
		if (n == 0) break;

		if (n == 1){
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" << endl;
			continue;
		}
		if (n == 2){
			cout << "Discarded cards: 1" << endl;
			cout << "Remaining card: 2" << endl;
			continue;
		}
		if (n % 2 == 0) 
			even(n);
		else
			odd(n);
		v.clear();
	}
	return 0;
}
