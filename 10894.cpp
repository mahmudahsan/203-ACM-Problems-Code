/* Problem: Save Hridoy UVa 10894
   Programmer: Md. Mahmud Ahsan
   Description: Simulation, output related, ad hoc
   Compiled: Visual C++ 7.0
   Date: 16-08-05
*/ 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	//initialize for positive number
	char h[5][100];
	strcpy(h[0], "*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*");
	strcpy(h[1], "*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.");
	strcpy(h[2], "*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..");
	strcpy(h[3], "....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..");
	strcpy(h[4], "*****.*...*...*...*****...*...*.*..**.*****.***...*****...*..");

	//initialize for negative number
	char v[61][10];
	strcpy(v[0], "*****");
	strcpy(v[1], "*....");
        strcpy(v[2], "*****");
	strcpy(v[3], "....*");
	strcpy(v[4], "*****");
	strcpy(v[5], ".....");
	strcpy(v[6], ".***.");
	strcpy(v[7], "*...*");
	strcpy(v[8], "*****");
	strcpy(v[9], "*...*");
	strcpy(v[10],"*...*");
	strcpy(v[11],".....");
	strcpy(v[12],"*...*");
	strcpy(v[13],"*...*");
	strcpy(v[14],"*...*");
	strcpy(v[15],".*.*.");
	strcpy(v[16],"..*..");
	strcpy(v[17],".....");
	strcpy(v[18],"*****");
	strcpy(v[19],"*....");
	strcpy(v[20],"***..");
	strcpy(v[21],"*....");
	strcpy(v[22],"*****");
	strcpy(v[23],".....");
	strcpy(v[24],".....");
	strcpy(v[25],".....");
	strcpy(v[26],"*...*");
	strcpy(v[27],"*...*");
	strcpy(v[28],"*****");
	strcpy(v[29],"*...*");
	strcpy(v[30],"*...*");
	strcpy(v[31],".....");
	strcpy(v[32],"*****");
	strcpy(v[33],"*...*");
	strcpy(v[34],"*****");
	strcpy(v[35],"*.*..");
	strcpy(v[36],"*..**");
	strcpy(v[37],".....");
	strcpy(v[38],"*****");
	strcpy(v[39],"..*..");
	strcpy(v[40],"..*..");
	strcpy(v[41],"..*..");
	strcpy(v[42],"*****");
	strcpy(v[43],".....");
	strcpy(v[44],"***..");
	strcpy(v[45],"*..*.");
	strcpy(v[46],"*...*");
	strcpy(v[47],"*..*.");
	strcpy(v[48],"***..");
	strcpy(v[49],".....");
	strcpy(v[50],"*****");
	strcpy(v[51],"*...*");
	strcpy(v[52],"*...*");
	strcpy(v[53],"*...*");
	strcpy(v[54],"*****");
	strcpy(v[55],".....");
	strcpy(v[56],"*...*");
	strcpy(v[57],".*.*.");
	strcpy(v[58],"..*..");
	strcpy(v[59],"..*..");
	strcpy(v[60],"..*..");

	bool flag = false, pos;
	int n, m, i, j, k;
	while (cin >> n){
		if (n == 0) break;
		if (flag)
			cout << endl << endl;
		flag = true;

		pos = true;
		if (n < 0){
			pos = false;
			n = abs(n);
		}
		//output for positive number
		if (pos){
			for (i = 0; i < 5; ++i){
				m = 0; 
				while (m < n){
					for (j = 0; h[i][j]; ++j){
						k = 0;
						while (k < n){
							cout << h[i][j];
							++k;
						}
					}
					++m;
					cout << endl;
				}
			}
		}
		else{
			for (i = 0; i < 61; ++i){
				m = 0; 
				while (m < n){
					for (j = 0; v[i][j]; ++j){
						k = 0;
						while (k < n){
							cout << v[i][j];
							++k;
						}
					}
					++m;
					cout << endl;
				}
			}
		}
	}
	cout << endl << endl;
	return 0;
}