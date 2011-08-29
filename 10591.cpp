/* Problem: Happy Number UVa 10591
   Programmer: Md. Mahmud Ahsan
   Description: Ad hoc, if any repetion of the new number then unhappy
   Compiled: Visual C++ 7.0
   Date: 03-06-05
*/
#include <iostream>
using namespace std;

long array[10000];
int main(){
	long item, itemOrg, j, store;
	int cases = 0, test, t, k, temp, flag;
	cin >> test;

	for (t = 0; t < test; ++t){
		cin >> item;
		itemOrg = item;
		flag = 100; // flag but 1,0 both is needed
		k = 0;

		while (flag != 1 && flag != 0){
			store = 0; 
			while (item != 0){
				temp = item % 10;
				item = item / 10;
				store += temp * temp;
			}
			item = store;
			if (store == 1)
				flag = 1;
			else{
				array[++k] = store;
				for (j = k-1; j > 0; --j){
					if (store == array[j]){
						flag = 0;
						break;
					}
				}
			}
		}
		cout << "Case #" << ++cases << ": ";
		if (flag)
			cout << itemOrg << " is a Happy number." << endl;
		else
			cout << itemOrg << " is an Unhappy number." << endl;
	}
	return 0;
}
		
