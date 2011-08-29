/* Problem: Automatic Poetry  UVa 10361
   Programmer: Md. Mahmud Ahsan
   Description: String Processing
   Compiled: Visual C++ 7.0
   Date: 20-08-05
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	char strA[200], strB[200];
	int n, i, j,k, brak;
	bool flag;
	
	cin >> n;
	cin.getline(strA, sizeof(strA)); // eat the newline
	for (i = 0; i < n; ++i){
		cin.getline(strA, sizeof(strA));
		cin.getline(strB, sizeof(strB));

		//first output
		for (j = 0; strA[j]; ++j)
			if (strA[j] != '>' && strA[j] != '<')
				cout << strA[j];
		cout << endl;

		//second output
		for (j = 0; strB[j]; ++j){
			if (strB[j] == '.')
				break;
			cout << strB[j];
		}
        //	cout << s4 << s3 << s2 << s5 << endl;
		brak = 0; 
		for (j = 0; strA[j]; ++j){ // for s4
			if (strA[j] == '<')
				++brak;
			if (brak == 2){
				for (k = j+1; strA[k] != '>'; ++k)
					cout << strA[k];
				break;
			}
		}
		for (j = 0; strA[j]; ++j){ // for s3
			if (strA[j] == '>'){
				for (k = j+1; strA[k] != '<'; ++k)
					cout << strA[k];
				break;
			}
		}
		for (j = 0; strA[j]; ++j){ // for s2
			if (strA[j] == '<'){
				for (k = j+1; strA[k] != '>'; ++k)
					cout << strA[k];
				break;
			}
		}
		brak = 0;
		for (j = 0; strA[j]; ++j){ // for s5
			if (strA[j] == '>')
				++brak;
			if (brak == 2){
				for (k = j+1; strA[k]; ++k)
					cout << strA[k];
				break;
			}
		}
		cout << endl;
	}		

	return 0;
}