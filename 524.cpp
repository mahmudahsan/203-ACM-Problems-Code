/* Problem: Prime Reing Problems UVa 524
   Programmer: Md. Mahmud Ahsan
   Description: Backtracking
   Compiled: Visual C++ 7.0
   Date: 14-03-06
*/
#include <iostream>
using namespace std;

bool visited[20];
int data[20], output[20], n, maxLevel;

void init(){
	for (int i = 0; i < n; ++i){
		visited[i] = false;
		data[i] = i + 1;
	}
}

bool isPrime(int x){
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;

	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

void backtrack(int level){
	int temp;
	if (level >= maxLevel){
		if (!isPrime(output[0] + output[maxLevel-1]))
			return;

		cout << output[0];
		for (int i = 1; i < maxLevel; ++i)
			cout << " " << output[i];
		cout << endl;
		return;
	}

	for (int i = 1; i < n; ++i){
		if (visited[i]) continue;
		
		temp = output[level-1] + data[i];
		if (isPrime(temp)){
			visited[i] = true;
			output[level] = data[i];
			backtrack(level + 1);
			visited[i] = false;
		}
	}
}


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cases = 0;
	bool flag = false;

	while (cin >> n){
		init();
		if (flag) cout << endl; flag = true;
		cout << "Case " << ++cases << ":" << endl;
		visited[0] = true;
		output[0] = 1;
		maxLevel = n;
		backtrack(1);
	}
	return 0;
}
