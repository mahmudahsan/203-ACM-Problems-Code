/* Problem: The Dole Queue UVa 133
   Programmer: Md. Mahmud Ahsan
   Description: Simulation, Circular Queue
   Compiled: Visual C++ 7.0
   Date: 17-08-05
*/

#include <iostream>
#include <cstdio>
using namespace std;

char cq[22];

void init(){
	for(int i = 0; i < 22; ++i)
		cq[i] = 0;
}
// is empty or not
bool check(int n){
	for (int i = 1; i <= n; ++i)
		if (cq[i] != 1)
			return false;
	return true;
}

int main(){
	//freopen("output.txt", "w", stdout);
	int n , m, k, a, b, i, j, clock, anticlock;
	bool foundA, foundB, comma;

	while (cin >> n >> k >> m){
		if (!m && !n && !k) break;

		init();
		comma = false;

		a = 1; b = n;
		clock = anticlock = 0;
		foundA = foundB = false;

		while (true){
			if (check(n))
				break;
			//for anti clockwise
			if (cq[a] == 0){
				++anticlock;
				if (anticlock == k){
					foundA = true;
					i = a; // i for fixed position
				}
			}
			if (!foundA)
				a = a % n + 1; // next move
			
			//for clock wise
			if (cq[b] == 0){
				++clock;
				if (clock == m){
					foundB = true;
					j = b;
				}
			}
			
			if (!foundB){ // next move
				b = b - 1;
				if (b < 1)
					b = n;
			}

			// for both clockwise and anticlockwise man found
			if (foundA && foundB){
				cq[i] = cq[j] = 1;
				foundA = foundB = false;
				clock = anticlock = 0;

				if (comma)
					cout << ",";
				comma = true;

				if (i != j){
					printf("%3d%3d", i, j);
				}
				else
					printf("%3d", i);
			}
		}
		cout << endl;
	}
	return 0;
}