/* Problem: Andy's First Dictionary UVa 10815
   Programmer: Md. Mahmud Ahsan
   Description: String + Sorting
   Compiled: Visual C++ 7.0
   Date: 18-02-06
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;

void strLwr(char *s){
	char str[1000];
	int i;
	for (i = 0; s[i]; ++i){
		str[i] = tolower(s[i]);
	}
	str[i] = '\0';
	strcpy(s, str);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char input[1000], taken[1000];	
	vector <string> v;
	int i, j, len;

	while (cin.getline(input, sizeof(input))){
		strLwr(input);

		j = 0;
		len = strlen(input);

		for (i = 0; i <= len; ++i){
			if (input[i] >= 'a' && input[i] <= 'z'){
				taken[j++] = input[i];
			}
			else{
				taken[j] = '\0';
				j = 0;
				if (strlen(taken) == 0)
					continue;
				
				string sss(taken);
				v.push_back(sss);
			}
		}
	}

	sort (v.begin(), v.end());
	
	len = v.size();
	cout << v[0] << endl;
	for (int i = 1; i < len; ++i){
		if (v[i] == v[i-1]) continue;
		cout << v[i] << endl;
	}
	return 0;
}
