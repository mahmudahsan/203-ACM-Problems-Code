/* Problem: Pseudo-Random Numbers UVa 350
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 07-10-04
*/
#include <iostream>
using namespace std;

typedef long int lint;

int main(){
	lint z, i, m, l;
	lint count;
	lint caseCount = 0;
	lint dataSet[10000];
	lint x, y, temp;
	bool flag;

	while (cin >> z >> i >> m >> l){
		if (!z && !i && !m && !l) break;

		for (x = 0; x < 10000; ++x)
			dataSet[x] = 0;
		dataSet[0] = l;

		flag = true;
		y = 1;
		temp = l;
		while (flag){
			temp = (z * temp + i) % m;
			dataSet[y] = temp;

			for (x = y - 1; x > 0; --x){
				if (dataSet[y] == dataSet[x]){
					count = y;
					flag = false;
					break;
				}
			}
			++y;
		}

		//for output case
		++caseCount;
		cout << "Case " << caseCount << ": " << --count << endl;
	}

	return 0;
}