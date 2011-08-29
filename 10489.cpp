/* Problem: Boxes of Chocolates UVa 10489
   Programmer: Md. Mahmud Ahsan
   Description: Modular Arithmetic
   Compiled: Visual C++ 7.0
   Date: 21-08-06
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	long long test, friends, boxes, result, i, j;
	long long temp, temp2, finalResult;

	cin >> test;

	while(test--){
		cin >> friends >> boxes;
		finalResult = 0;

		for (i = 0; i < boxes; ++i){
			cin >> temp;
			result = 1;

			for (j = 0; j < temp; ++j){
				cin >> temp2;
				result = (temp2 * result) % friends;
			}
			finalResult += result % friends;
			finalResult = finalResult % friends;
		}	
        cout << finalResult << endl;
	}

	return 0;
}
