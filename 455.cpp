/* Problem: Periodic Strings UVa 455
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC
   Compiled: Visual C++ 7.0
   Date: 26-10-05
*/
#include <iostream>
#include <string>
using namespace std;

char strMain[100];
char strSub[100];
int lenMain, lenSub;


int comp(){
	lenSub = strlen(strSub);
	int i, j;
	for (i = 0; strMain[i]; i += lenSub){
		for (j = 0; strSub[j]; ++j){
			if (strSub[j] != strMain[i+j])
				return 0;
		}
	}
	return 1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int n, i, j, k;
	cin >> n;

	int flag = 1;
	while (n--){
		cin >> strMain;
		lenMain = strlen(strMain);

		if (!flag) cout << endl; flag = 0;

		for (i = 0; strMain[i]; ++i){
			for (j = 0; j <= i; ++j)
				strSub[j] = strMain[j];
			strSub[j] = '\0';
			k = comp();
			if (k == 1){
				cout << lenSub << endl;
				break;
			}
		}
	}

	return 0;
}