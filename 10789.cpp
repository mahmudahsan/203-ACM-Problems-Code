/* Problem: Prime Frequency UVa 10789
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 12-12-04
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void init(int array[][2]); // first initialize
void sieve(vector <int> &v); // collects primes

//========================================================
int main(){
	vector <int> v; // use for holds primes
	int test;
	int i, j, k, cases = 0;
	int array[125][2];
	char str[2050]; // get string
	bool flag;

	/*
	ifstream fin("input.in");
	cin = fin;
	*/

	sieve(v);

	cin >> test;

	for (i = 0; i < test; i++){
		init(array);
		flag = true;
		
		cin >> str;
		for (j = 0; str[j]; j++){
			array[str[j]][1] += 1;
		}

		cout << "Case " << ++cases << ": ";
		for (k = 48; k < 124; k++){
			// if illegal characters are inputted except 0-9, A-Z, a-z
				if(k==58)k=65;
				else if(k==93)k=97;
			for (j = 0; j < v.size(); j++){
				// as array is string so we must subtract 48
				if (array[k][1] == v[j]){
					cout << (char) array[k][0];
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cout << "empty";

		cout << endl;
	}
	//fin.close();
	return 0;
}
//================================================================

void init(int array[][2]){
	int i;
	for (i = 48; i < 125; i++){
		array[i][0] = i;
		array[i][1] = 0;
	}
}

void sieve(vector <int> &v){
	int i, j;
	int prime[2052];

	for (i = 0; i <= 2050; i++)
		prime[i] = 1;


	prime[0] = 0;
	prime[1] = 0;
	for (i = 2; i <= 2050; i++){
		for (j = i + i; j <= 2050; j += i){
			prime[j] = 0;
		}
	}

	for (i = 0; i <= 2050; i++){
		if (prime[i] == 1)
			v.push_back(i);
	}
}
