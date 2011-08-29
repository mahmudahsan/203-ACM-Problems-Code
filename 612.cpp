/* Problem: DNA Sorting UVa 612
   Programmer: Md. Mahmud Ahsan
   Description: Sorting, Bubble + Stable
   Compiled: Visual C++ 7.0
   Date: 20-08-05
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct word{
	char str[200];
	int order;
}words[200];

inline bool comp(word a, word b){
	return a.order < b.order;
}

int bubble(char *);

int main(){	
	//freopen("output.txt", "w", stdout);
	int test, t, m, n, i;
	char st[200];

	bool flag = false;
	cin >> test;
	for (t = 0; t < test; ++t){
		cin >> n >> m;
		for (i = 0; i < m; ++i){
			cin >> words[i].str;
			strcpy(st, words[i].str); // temporarily sort by bubble
			words[i].order = bubble(st);
		}
		//for output
		if (flag) cout << endl; flag = true;

		stable_sort(words, words+m, comp);
		for (i = 0; i < m; ++i)
			cout << words[i].str << endl;
		
	}

	return 0;
}
int bubble(char *str){
	int count=0;
	char temp;
    int i, j, len = strlen(str);;
	for (i = 1; i < len; ++i){
		for (j = 0; j < len-i; ++j){
			if (str[j] > str[j+1]){
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
				++count;
			}
		}
	}
	return count;
}