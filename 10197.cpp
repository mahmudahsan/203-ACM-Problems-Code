/* Problem: Learning Portuguese UVa 10197
   Programmer: Md. Mahmud Ahsan
   Description: Ad-hoc
   Compiled: Visual C++ 7.0
   Date: 21-08-06
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

void strRev(char *str){
	char temp[100];
	int len = strlen(str)-1;
	int i;
	for (i = 0; str[i]; ++i){
		temp[i] = str[len-i];
	}
	temp[i] = '\0';
	strcpy(str, temp);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//ar, er, ir vowels: a, e, i

	bool flag = false;
	char v1[100], v2[100], word[100], ch[3];
	int len, i, temp;

	while (cin >> v1 >> v2){
		if (flag) cout << endl; flag = true;
		cout << v1 << " (to " << v2 << ")" << endl;

		len = strlen(v1);
		ch[0] = v1[len-1];
		ch[1] = v1[len-2];
		ch[2] = '\0';
		strRev(ch);

		for (i = 0; i < len - 2; ++i){
			word[i] = v1[i];
		}
		word[i] = '\0';

		if (strcmp(ch, "ar") == 0){
			printf("%-10s", "eu");
			cout << word << "o" << endl;

			printf("%-10s", "tu");
			cout << word << "as" << endl;

			printf("%-10s", "ele/ela");
			cout << word << "a" << endl;

			printf("%-10s", "nós");
			cout << word << "amos" << endl;

			printf("%-10s", "vós");
			cout << word << "ais" << endl;

			printf("%-10s", "eles/elas");
			cout << word << "am" << endl;
		}
		else if (strcmp(ch, "er") == 0){
			printf("%-10s", "eu");
			cout << word << "o" << endl;

			printf("%-10s", "tu");
			cout << word << "es" << endl;

			printf("%-10s", "ele/ela");
			cout << word << "e" << endl;

			printf("%-10s", "nós");
			cout << word << "emos" << endl;

			printf("%-10s", "vós");
			cout << word << "eis" << endl;

			printf("%-10s", "eles/elas");
			cout << word << "em" << endl;

		}
		else if (strcmp(ch, "ir") == 0){
			printf("%-10s", "eu");
			cout << word << "o" << endl;

			printf("%-10s", "tu");
			cout << word << "es" << endl;

			printf("%-10s", "ele/ela");
			cout << word << "e" << endl;

			printf("%-10s", "nós");
			cout << word << "imos" << endl;

			printf("%-10s", "vós");
			cout << word << "is" << endl;

			printf("%-10s", "eles/elas");
			cout << word << "em" << endl;
		}
		else{
			cout << "Unknown conjugation" << endl;
		}

	}

	return 0;
}
