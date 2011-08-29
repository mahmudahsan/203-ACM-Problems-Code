/* Problem: Simply Emirp  UVa 10235
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 29-03-05
*/
#include <iostream>
#include <cmath>
using namespace std;

const long length = 1000005;

long seive[length];
void genSeive();
long reverse(long n);

int main(){
	genSeive();	
	long input, rev;
	bool prime, emirp;

	while (cin >> input){
		prime = emirp = false;
		if (seive[input] == 0)
			prime = true;
		rev = reverse(input);
		if (seive[rev] == 0)
			emirp = true;

		cout << input;
		if (!prime)
			cout << " is not prime." << endl;
		else if (prime && (input == rev))
			cout << " is prime." << endl;
		else if (prime && !emirp)
			cout << " is prime." << endl;
		else if (prime && emirp)
			cout << " is emirp." << endl;
	}

	return 0;
}

long reverse(long n){
	int digit = floor(log10(n))+1;
	long m;
	long result = 0;

	while (n != 0){
		m = n % 10;
		n = n / 10;

		if (digit > 1){
			result = result + (m * pow(10, --digit));
		}
		else
			result = result + m;
	}
	return result;
}

void genSeive(){
	long i, j;

	seive[0]=seive[1] = 1;
	for(i = 2; i < length; ++i){
		for (j = i + i; j < length; j += i)
			seive[j] = 1;
	}
}