/* Problem: Ecological Bin Packing UVa 102
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 25-08-04
*/

#include <iostream>
#include <string>
using namespace std;

// struct type
struct Bin{
	char style[4];
	int amount;
};

//prototype
void printOutput(Bin obj[]);

//=================================================================
int main(){
	int a, b, c, d, e, f, g, h, i;
	
	while (cin >> a >> b >> c >> d >> e >> f >> g >> h >> i){
		Bin obj[6];

		strcpy(obj[0].style, "BCG");
		obj[0].amount = d + g + c + i + b + e;

		strcpy(obj[1].style, "BGC");
		obj[1].amount = d + g + b + h + c + f;

		strcpy(obj[2].style, "CBG");
		obj[2].amount = f + i + a + g + b + e;

		strcpy(obj[3].style, "CGB");
		obj[3].amount = f + i + b + h + a + d;

		strcpy(obj[4].style, "GBC");
		obj[4].amount = e + h + a + g + c + f;

		strcpy(obj[5].style,  "GCB");
		obj[5].amount = e + h + c + i + a + d;

		printOutput(obj);
	}
	
	return 0;
}
//======================================================================

void printOutput(Bin obj[]){
	int temp = obj[0].amount;
	int flag = 0;

	for (int i = 1; i < 6; i++){
		if (temp > obj[i].amount){
			temp = obj[i].amount;
			flag = i;
		}
	}
	cout << obj[flag].style << " " << obj[flag].amount << endl;
}