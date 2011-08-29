/* Problem: Prime Words UVa 10924
   Programmer: Md. Mahmud Ahsan
   Description: Simulation
   Compiled: Visual C++ 7.0
   Date: 17-02-06
*/

#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n){
	if (n == 1) return true;
	if (n < 1) return false;
	if (n == 2) return true;
	if (n%2 == 0) return false;

	for (int i = 3; i * i <= n; i+=2)
		if (n % i == 0) return false;
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);

	string str;
	int i, j, temp;
	int value[150];
	j = 1;
	for (i = 97; i <= 'z'; ++i)
		value[i] = j++;

	for (i = 65; i <= 'Z'; ++i)
		value[i] = j++;

	while (cin >> str){
		temp = 0;
		j = str.size();
		for (i = 0; i < j; ++i)
			temp += value[str[i]];
		if (isPrime(temp))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}	
	return 0;
}
