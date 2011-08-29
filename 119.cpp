/* Problem:  Greedy Gift Givers  UVa 119
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 7.0
   Date: 30-05-05
*/

#include <iostream>
#include <string>
using namespace std;

struct person{
	string name;
	int dollar;
};

int main(){
	int i, j, k, n, flag = 0;
	int dollar, people, temp, differ;

	person obj[15];
	string name, name1;
	while (cin >> n){
		for (i = 0; i < n; ++i){
			cin >> obj[i].name;
			obj[i].dollar = 0;
		}

		for (i = 0; i < n; ++i){
			cin >> name >> dollar >> people;

			//the money holder who will give
			for (k = 0; k < n; ++k){
					if (name == obj[k].name){
						obj[k].dollar += -dollar;
						if (people != 0)
							temp = dollar / people;
						differ = dollar - (temp * people);
						obj[k].dollar += differ;
						break;
					}
			}

			for (j = 0; j < people; ++j){
				cin >> name1;
				//checking each person whom gift money to give
				for (k = 0; k < n; ++k){
					if (name1 == obj[k].name){
						if (people != 0)
							temp = dollar / people;
						obj[k].dollar += temp;
						break;
					}
				}
			}
		}

		if (flag == 1) cout << endl;
		flag = 1;
		for(i = 0; i < n; ++i)
			cout << obj[i].name << " " << obj[i].dollar << endl;
		
	}

	return 0;
}