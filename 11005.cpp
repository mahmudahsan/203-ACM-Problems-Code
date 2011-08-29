/* Problem: Cheapest Base UVa 11005
   Programmer: Md. Mahmud Ahsan
   Description: Base
   Compiled: Visual C++ 7.0
   Date: 07-03-06
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lint;

lint weight[40];
vector <lint> index;

lint convert(lint number, int base){
	lint temp, mod;
	
	temp = 0;
	while (number != 0){
		mod = number % base;
		number = number / base;
		temp += weight[mod];
	}
	return temp;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j, k;
	int test, query, cases = 0;
	lint temp, data;
	lint mn;
	bool flag =false;

	cin >> test;
	while (test--){
		for (i = 0; i < 36; ++i){
			cin >> weight[i];
		}
		cin >> query;

		if (flag) cout << endl; flag = true;
			cout << "Case " << ++cases << ":" << endl;

		for (i = 0; i < query; ++i){
			cin >> data;
			
			index.clear();
			index.push_back(2);
			mn = convert(data, 2);
			for (j = 3; j <= 36; ++j){
				temp = convert(data, j);
				if (temp < mn){
					mn = temp;
					index.clear();
					index.push_back(j);
				}
				else if (temp == mn){
					index.push_back(j);
				}
			}
			
			cout << "Cheapest base(s) for number " << data << ":";
			for (k = 0; k < index.size(); ++k)
				cout << " " << index[k];
			cout << endl;
		}

	}
	return 0;
}
