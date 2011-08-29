/* Problem: Haiku Review UVa 576
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-02-05
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	char str[200];
	int i;
	int iFirst, iSecond, iThird, iCount;
	bool fFirst, fSecond, fThird;

	while (cin.getline(str, sizeof(str))){
		if (strcmp(str, "e/o/i") == 0)
			break;

		i = iFirst = iSecond = iThird = 0;
		iCount = 1;
		fFirst = true;

		while (str[i]){
			if (str[i] == '/')
				iCount++;
			if (iCount == 2){
				fFirst =false; fSecond = true; fThird = false;
			}
			else if (iCount == 3){
				fSecond = false; fThird = true; fFirst = false;
			}

			int k = 1;

			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){
				if (fFirst)
					iFirst++;
				
				else if (fSecond)
					iSecond++;
				
				else if (fThird)
					iThird++;
				while (str[i] && str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){
					i++;
					k = 0;
				}
			}
			if (k != 0)
				++i;
		}
		if (iFirst!= 5)
			cout << 1 << endl;
		else if (iSecond != 7)
			cout << 2 << endl;
		else if (iThird != 5)
			cout << 3 << endl;
		else
			cout << "Y" << endl;

	}

	return 0;
}