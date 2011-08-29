/* Problem: Word Problem  UVa 895
   Programmer: Md. Mahmud Ahsan
   Description: String
   Compiled: Visual C++ 7.0
   Date: 15-09-06
*/

#include <iostream>
#include <string>
using namespace std;

int arr[1005][26];

int main(){
	//freopen("input.txt", "r", stdin);
	char str[1000], ch;
	int i, j, counter, count;
	int letters[26];
	bool found;

	counter = 0;
	while (cin >> str){
		if (str[0] == '#') break;
		
		for (i = 0; str[i]; ++i){
			ch = str[i];
			if (ch >= 'a' && ch <= 'z'){
				arr[counter][ch-97]++;
			}
		}
		++counter;
	}

	cin.getline(str, sizeof(str));
	while (cin.getline(str, sizeof(str))){
		if (str[0] == '#') break;
		count = 0;

		for (i = 0; i < 26; ++i)
			letters[i] = 0;

		for (i = 0; str[i]; ++i){
			ch = str[i];
			if (ch >= 'a' && ch <= 'z'){
				++letters[ch-97];			
			}
		}
		for (i = 0; i < counter; ++i){
			found = true;
			for (j = 0; j < 26; ++j){
				if (arr[i][j] > letters[j]){
					found = false;
					break;
				}
			}
			if (found) ++count;
		}
		cout << count << endl;
	}

	return 0;
}
