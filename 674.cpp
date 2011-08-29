/* Problem: Coin Change  UVa 674
   Programmer: Md. Mahmud Ahsan
   Description: Counting Change + dp
   Compiled: Visual C++ 7.0
   Date: 20-08-05
*/
#include <iostream>
using namespace std;

#define max 8000


int coin[5] = {50, 25, 10, 5, 1};
long long nway[max];
long long dp[max];

void init(){
	for(int i = 0; i < max; ++i)
		nway[i] = 0;
}

int main(){
	int i, j, n, v = 5, c;
	int k = -1;
	for (n = 0; n < max; ++n){
		init();
		nway[0] = 1;

		for (i = 0; i < v; ++i){
			c = coin[i];
			for (j = c; j <= n; ++j)
				nway[j] += nway[j-c];
		}
		dp[++k] = nway[n];
	}
	while (cin >> n){
		cout << nway[n] << endl;
	}

	return 0;
}

