/* Problem: Luggage UVa 10664
   Programmer: Md. Mahmud Ahsan
   Description: Backtracking + sorting
   Compiled: Visual C++ 7.0
   Date: 28-07-06
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int data[100], sum, size, tempSum, n;
bool visited[100];
bool found;

inline bool comp(const int a, const int b){
	return a > b;
}

void backtrack(int level){
	if (tempSum == sum){
		cout << "YES" << endl;
		found = true;
		return;
	}
	else if (tempSum > sum)
		return;
	if (level > (n/2)) return;

	for (int i = 0; i < n; ++i){
		if (visited[i])continue;

		tempSum += data[i];
		visited[i] = true;
		backtrack(i+1);

		if (found) return;

		tempSum -= data[i];
		visited[i] = false;
	}

}

int main(){
	//freopen("input.txt", "r", stdin);
	int test, i;
	char str[100], *ptr;

	cin >> test;
	cin.getline(str, sizeof(str));

	while(test--){
		cin.getline(str, sizeof(str));	
		
		size = sum = 0;
		ptr =strtok(str, " \n");
		while (ptr){
			sscanf(ptr, "%d", &data[size]);
			sum += data[size];
			++size;
			ptr = strtok(NULL, " \n");
		}

		if (size == 1){
			cout << "NO" << endl;
			continue;
		}

		if (sum % 2 != 0) {
			cout << "NO" << endl;
			continue;
		}
		
		fill(visited, visited + size, false);
		sum = sum / 2; //if sum even
		sort(data, data + size, comp);

		n = size;

		tempSum = 0;
		found = false;
		backtrack(0);

		if (!found) cout << "NO" << endl;
	}

	return 0;
}
