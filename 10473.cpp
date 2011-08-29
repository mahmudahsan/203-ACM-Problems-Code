/* Problem: Simple Base Conversion  UVa 10473
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-05-04
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	char str[100];
	int result, exit;
	while (cin >> str){
		exit = atoi(str);
		if (exit < 0) break;

		if ( (strlen(str) > 2) && (str[1] == 'x' || str[1] == 'X')){
				sscanf(str, "%X", &result);
				cout << result << endl;
		}
		else{
			sscanf(str, "%d", &result);
			printf("0x%X\n", result);
		}
	}
	return 0;
}