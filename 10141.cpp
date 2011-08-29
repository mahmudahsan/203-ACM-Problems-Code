/* Problem: Request for Proposal UVa 10141
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC
   Compiled: Visual C++ 7.0
   Date: 31-08-05
*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	//freopen("output.txt", "w", stdout);
	int n, p, i, j, cases = 0, prio, prevPrio;
	double value, prevValue;
	char str[500], name[500];
	char final[500];
	bool flag = false;

	while (cin >> n >> p){
		if (n == 0 && p == 0) break;
		
		cin.getline(str, sizeof(str));// eat blank char
		for (i = 0; i < n; ++i) 
			cin.getline(str, sizeof(str)); // ignore this

		cin.getline(final, sizeof(final));
		cin.getline(str, sizeof(str));
		sscanf(str, "%lf%d", &prevValue,&prevPrio);
			
		for (j = 0; j < prevPrio; ++j) cin.getline(str, sizeof(str));

		for (i = 1; i < p; ++i){
			cin.getline(name, sizeof(name));
			cin.getline(str, sizeof(str));
			
			sscanf(str, "%lf%d", &value,&prio);
			
			for (j = 0; j < prio; ++j) cin.getline(str, sizeof(str));

			if (prio > prevPrio){
				prevPrio = prio;
				strcpy(final, name);
			}
			else if (prio == prevPrio){
				if (value < prevValue){
					prevValue = value;
					strcpy(final, name);
				}
			}
		}
		if (flag) cout << endl;
		flag = true;

		cout << "RFP #" << ++cases << endl;
		cout << final << endl;
	}
	return 0;
}