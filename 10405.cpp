/* Problem: Longest Common Subsequence UVa 10405
   Programmer: Md. Mahmud Ahsan
   Description: LCS
   Compiled: Visual C++ 7.0
   Date: 20-11-05
*/
#include <iostream>
#include <string>
using namespace std;

#define N 1005

//Global Declaration
int c[N+1][N+1];
//char b[N+1][N+1];

int LCSLength(char *x, char *y, int m, int n);
//void printLCS(char *x, int i, int j); // i for x and j for y

int main(){
	char x[N], y[N];

	while (cin.getline(&x[1], sizeof(x))){
		cin.getline(&y[1], sizeof(y));

		int m = strlen(&x[1]); // as string index begins from 1
		int n = strlen(&y[1]); // as string index begins from 1

		int len = LCSLength(x, y, m, n);
		cout << len << endl;
		//printLCS(x, m, n);
		//cout << endl;
	}

	return 0;
}

int LCSLength(char *x, char *y, int m , int n){
	int i, j;
	
	/* initialize all to zero */
	for (i = 0; i <= m; ++i)
		for (j = 0; j <= n; ++j)
			c[i][j] = 0;

	for (i = 1; i <= m; ++i){
		for (j = 1; j <= n; ++j){
			if (x[i] == y[j]){
				c[i][j] = c[i-1][j-1] + 1;
				//b[i][j] = '#'; //# for angle arrow
			}
			else if (c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				//b[i][j] = '^'; //^ for up arrow
			}
			else{
				c[i][j] = c[i][j-1];
				//b[i][j] = '<'; //< for left arrow
			}
		}
	}
	return c[m][n];
}
/*
void printLCS(char *x, int i, int j){
	if (i == 0 || j == 0) return;
	
	if (b[i][j] == '#'){
		printLCS(x, i-1, j-1);
		cout << x[i]<< " ";
	}
	else if (b[i][j] == '^')
		printLCS(x, i-1, j);
	else
		printLCS(x, i, j-1);	
}
*/
