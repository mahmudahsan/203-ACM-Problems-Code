/* Problem: F: 498 UVa 10268
   Programmer: Md. Mahmud Ahsan
   Description: Horner's Rule + Derivative of the equation
   Compiled: Visual Studio .Net
   Date: 26-12-05
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const long MX = 1000001;
double array[MX], arrayD[MX], result, temp;
char str1[MX], str2[MX], *ptr;

double horner(int n, double array[], double x){
	//horner compute the value of a polynomial of order n
	double p;
	p = array[n];
	for (int i = n-1; i >= 0; --i){
		p = p * x + array[i];
	}
	return p;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, i, order;
	
	while (cin.getline(str1, sizeof(str1))){
		cin.getline(str2, sizeof(str2));

		sscanf(str1, "%d", &x);

		//separate the coefficients and store in the array
		i = -1;
		ptr = strtok(str2, " \t\n");
		while (ptr){
			++i;
			sscanf(ptr, "%lf", &array[i]);

			ptr = strtok(NULL, " \t\n");
		}
		temp = i;
		order = --i; //after derivative order decrease by 1
		for (int j = 0; j <= order; ++j){
			arrayD[j] = temp-- * array[j];
		}

		reverse(arrayD, arrayD+order+1);
		
		result = horner(order, arrayD, x);
		//cout << result << endl;
		printf("%.0lf\n", result);
	}
	return 0;
}