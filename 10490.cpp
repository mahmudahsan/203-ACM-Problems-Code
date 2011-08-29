/* Problem: Mr. Azad and His Son!!!!! UVa 10490
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-04-05
*/

//** One Concept found: except '2' even numbers aren't perfect not prime provided the law
//** 11, 23, 29 are prime but not perfect
//** Others primes <=31 are perfect
//** and help from steven Halim

#include <iostream>
#include <cmath>
using namespace std;

/* Doing Precalculation
bool chkPrime(long long n);
bool chkPerfect(long long n);
*/

int main(){
	long long data;
	int input;
	//bool prime, perfect;
	bool flag;
	int prime[] = {2, 3, 5, 7, 13, 17, 19, 31};
	int notPerfect[] = {11, 23, 29};

	while (cin >> input){
		if (input == 0) break;
		data = ( pow (2 ,(input - 1)) ) * (( pow(2, input))-1);
		flag = false;
		/*
		cout << "Data "<< data << endl;
		prime = chkPrime(input); // check giver number for prime
 		perfect = chkPerfect(data);
		*/
		for (int i = 0; i < 8; ++i){
			if (prime[i] == input){
				cout << "Perfect: " << data << "!" << endl;
				flag = true;
			}
		}
		if (flag) continue;

		if (notPerfect[0] == input || notPerfect[1] == input || notPerfect[2] == input){
            cout << "Given number is prime. But, NO perfect number is available." << endl;
		}
		else
			cout << "Given number is NOT prime! NO perfect number is available." << endl;
	}
	return 0;
}

/*
bool chkPrime(long long n){
	if (n == 1) return false;
	long long k = sqrt( (double) n);
	long long i;
	for(i = 2; i <= k; ++i){
		if (n % i == 0)
			return false;
	}
	return true;
}
bool chkPerfect(long long n){
	long long i, total, limit = n / 2;
	
	total = 0;
	for (i = 1; i <= limit; ++i){
		if (n % i == 0)
			total += i;
	}
	if (total == n)
		return true;
	return false;
}
*/