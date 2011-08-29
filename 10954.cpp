/* Problem: Add All UVa 10954
   Programmer: Md. Mahmud Ahsan
   Description: Ad-hoc + Data structure
   Compiled: Visual C++ 7.0
   Date: 19-08-06
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct X{
	int n;
};

bool operator < (const X &a, const X &b){
	return a.n > b.n;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int n, i, temp, final;
	priority_queue <X> q;
	X x, y;

	while (cin >> n){
		if (!n) break;
		final = temp = 0;

		for (i = 0; i < n; ++i){
			cin >> temp;
			x.n = temp;
			q.push(x);
		}
		
		while (!(q.size() == 1)){
			x = q.top(); q.pop();
			y = q.top(); q.pop();
			temp = x.n + y.n;
			final += temp;
			x.n = temp;
			q.push(x);
		}
		q.pop();
		cout << final << endl;
	}

	return 0;
}
