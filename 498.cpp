/* Problem: Polly the Polynomial UVa 498
   Programmer: Md. Mahmud Ahsan
   Description: Horner's Rule
   Compiled: Visual Studio .Net
   Date: 26-12-05
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const long MX = 1000000;

double horner(int n, double array[], double x){
	//horner compute the value of a polynomial of order n
	double p;
	p = array[n];
	for (int i = n-1; i >= 0; --i){
		p = p * x + array[i];
	}
	return p;
}

double array[MX], result;
char str1[MX], str2[MX], *ptr;

int main(){
#ifndef ONLINE_JUDGE
	freopen("498.in", "r", stdin);
	freopen("498.out", "w", stdout);
#endif
	int n, i;
	
	bool space;

	while (cin.getline(str1, sizeof(str1))){
		cin.getline(str2, sizeof(str2));

		space = false;
		i = -1;
		ptr = strtok(str1, " \t\n");
		while (ptr){
			++i;
			sscanf(ptr, "%lf", &array[i]);
			ptr = strtok(NULL, " \t\n");
		}

		// reverse the order of the coefficients
		reverse(array, array + i+1);

		ptr = strtok(str2, " \t\n");
		while (ptr){
			sscanf(ptr, "%d", &n);
			result = horner(i, array, n);
			if (space)cout << " "; space = true;
			//cout << result;
			printf ("%.0f", result);
			ptr = strtok(NULL, " \t\n");
		}
		cout << endl;
	}
	return 0;
}