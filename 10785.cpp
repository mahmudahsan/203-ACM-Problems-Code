/* Problem: The Mad Numerlogist UVa 10785
   Programmer: Md. Mahmud Ahsan
   Description: Simulation
   Compiled: Visual C++ 7.0
   Date: 17-08-06
*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const char vowel[] = "AUEOI";
int countVowel[] ={21,21,21,21,21};
const char consonent[][4] = { {"JS"},
						{"BKT"},
						{"CL"},
						{"DMV"},
						{"NW"},
						{"FX"},
						{"GPY"},
						{"HQZ"},
						{"R"} 
						};
int countConsonent[][3] = {
						   {5,5,-100},
						   {5,5,5},
						   {5,5, -100},
						   {5,5,5},
						   {5,5, -100},
						   {5,5, -100},
						   {5,5,5},
						   {5,5,5},
						   {5, -100, -100}
						  };

char getVowel(){
	for (int i = 0; i < 5; ++i){
		if (countVowel[i] != 0){
			--countVowel[i];
			return vowel[i];
		}
	}
}

char getConsonent(){
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 3; ++j){
			if (countConsonent[i][j] == -100) continue;

			else if (countConsonent[i][j] != 0){
				--countConsonent[i][j];
				return consonent[i][j];
			}
		}
	}
}

void init(){
	fill(countVowel, countVowel+5, 21);
	countConsonent[0][0] = countConsonent[0][1] = 5;
	countConsonent[1][0] = countConsonent[1][1] = countConsonent[1][2]= 5;
	countConsonent[2][0] = countConsonent[2][1] = 5;
	countConsonent[3][0] = countConsonent[3][1] = countConsonent[3][2]= 5;
	countConsonent[4][0] = countConsonent[4][1] = 5;
	countConsonent[5][0] = countConsonent[5][1] = 5;
	countConsonent[6][0] = countConsonent[6][1] = countConsonent[6][2]= 5;
	countConsonent[7][0] = countConsonent[7][1] = countConsonent[7][2]= 5;
	countConsonent[8][0] = 5;

 }
class X{
public:	char ch;
};

bool operator < (const X &a, const X &b){
	return a.ch > b.ch;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int test, n, i, j, temp, cases = 0;
	bool case1, case2;
	priority_queue <X> vowel, consonent;
	X ob;
	char str[500];
	int s;
	
	cin >> test;
	while (test--){
		init();
		cin >> n;
		cout << "Case " << ++cases <<": ";
		
		for (int i = 0; i < n; ++i){
			if (i % 2 == 0){
				ob.ch = getVowel();
				vowel.push(ob);
			}
			else{
				ob.ch = getConsonent();
				consonent.push(ob);
			}
		}
		s = 0;

		while (!vowel.empty() || !consonent.empty()){
			if (!vowel.empty()){
				ob = vowel.top();
				str[s++] = ob.ch; vowel.pop();
			}
			if (!consonent.empty()){
				ob = consonent.top();
				str[s++] = ob.ch; consonent.pop();
			}
		}	
		str[s] = '\0';
		cout << str << endl;

	}

	return 0;
}
