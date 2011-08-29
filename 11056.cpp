/* Problem: Problem A – Formula 1 UVa 11056
   Programmer: Md. Mahmud Ahsan
   Description: Sort
   Compiled: Visual C++ 7.0
   Date: 14-08-06
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Type{
	int min, sec, ms;
	string name1, name2;
}pilots[1000];

inline bool comp(const Type &a, const Type &b){
	if (a.min != b.min)
		return a.min < b.min;
	else if (a.sec != b.sec)
		return a.sec < b.sec;
	else if (a.ms != b.ms)
		return a.ms < b.ms;
	else
		return a.name2 < b.name2;
}

int main(){
	//freopen("input.txt", "r", stdin);
	string temp;
	char name[100];
	int n, min, sec, ms;

	while (cin >> n){
		for (int i = 0; i < n; ++i){
			cin >> name >> temp >> min >> temp >> sec >> temp >> ms >> temp;
			
			pilots[i].name1 = name;
			for (int j = 0; name[j]; ++j){
				if (name[j] >= 'A' && name[j] <= 'Z')
					name[j] = name[j] + 32;
			}
			
			temp = name;
			pilots[i].name2 = temp;
			pilots[i].min = min;
			pilots[i].sec = sec;
			pilots[i].ms = ms;
		}
		sort(pilots, pilots +n, comp);
		int cases = 0;

		
		for (int i = 0; i < n; ++i){
			if (i % 2 == 0)
				cout << "Row " << ++cases << endl;
			cout << pilots[i].name1 << endl;
		}
		cout << endl;
	}

	return 0;
}
