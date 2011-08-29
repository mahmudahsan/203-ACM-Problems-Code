/* Problem: My Dear Neighbours UVa 10928
   Programmer: Md. Mahmud Ahsan
   Description: Number Theory
   Compiled: Visual C++ 7.0
   Date: 19-08-06
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Data{
	int index;
	int count;
}datas[20000];

inline bool comp(const Data &a, const Data &b){
	if (a.count != b.count)
		return a.count < b.count;
	return a.index < b.index;
}

int main(){
	//freopen("input.txt" , "r", stdin);

	int test, p, i, temp, counter;
	char str[20000],*ptr;
	
	cin >> test;
	while(test--){
		counter = 0;
		cin >> p;
		cin.getline(str, sizeof(str)); // eat new line character

		for (i = 0; i < p; ++i){
			cin.getline(str, sizeof(str));
			
			temp = 0;
			ptr = strtok(str, " \n");
			while(ptr){
				++temp;
				ptr = strtok(NULL, " \n");
			}
			datas[counter].index = counter + 1;
			datas[counter].count = temp;
			++counter;
		}

		sort(datas, datas + counter, comp);
		
		cout << datas[0].index;

		for (i = 1; i < counter; ++i){
			if (datas[i].count == datas[0].count)
				cout << " " << datas[i].index;
			else
				break;
		}
		cout << endl;
	}

	return 0;
}
