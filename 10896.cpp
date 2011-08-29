/* Problem: Known Plaintext Attack UVa 10896
   Programmer: Md. Mahmud Ahsan
   Description: String
   Compiled: Visual C++ 7.0
   Date: 15-09-06
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

char seq[] = "abcdefghijklmnopqrstuvwxyz";

int getPos(char a, char b){
	int posA, posB, total;
	posA = a-97;
	posB = b-97;

	if (posA <= posB)
		return posB - posA;
	
	total = 26 - posA;
	return total + posB;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int n;
	char line[100], word[100], *ptr;
	int lenLine, lenWord, i, j, temp, total, prev;
	bool ok;

	cin >> n;
	cin.getline(line, sizeof(line));
	
	while (n--){
		vector <char> ch;

		cin.getline(line, sizeof(line));
		cin.getline(word, sizeof(word));

		lenWord = strlen(word);
	
		ptr = strtok(line, " \n");
		    
		while (ptr){
			lenLine = strlen(ptr);

			if (lenLine == lenWord){
				prev = getPos(word[0], ptr[0]);
				temp = prev;
				ok = true;
				for (i = 1; word[i]; ++i){
					temp = getPos(word[i], ptr[i]);
					if (temp != prev){
						ok = false;
						break;
					}

				}
				if (ok){
					int character = temp;
					ch.push_back(seq[character % 26]);
			
				}
			}

			ptr = strtok(NULL, " \n");
		}
		sort(ch.begin(), ch.end());
		for (i = 0; i < ch.size(); ++i)
			cout << ch[i];
		cout << endl;

	}
	return 0;
}
