/* Problem: Word Morphing UVa 10508
   Programmer: Md. Mahmud Ahsan
   Description: Ad-hoc
   Compiled: Visual C++ 7.0
   Date: 13-09-06
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	vector <string> str;
	string org, temp;
	int word, letter, cnt;

	while (cin >> word >> letter){
		str.resize(word);
		
		cin >> org;
		str[0] = org;

		for (int j = 1; j < word; ++j){ 
			cin >> temp;
			cnt = 0;
			for (int i = 0; i < letter; ++i){
				if (org[i] != temp[i])
					++cnt;
			}
			str[cnt] = temp;
		}
		for (int i = 0; i < str.size(); ++i)
			cout << str[i] << endl;
	}

	return 0;
}
