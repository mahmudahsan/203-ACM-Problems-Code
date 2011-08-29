/* Problem:  Pebble Solitaire   UVa 10651
   Programmer: Md. Mahmud Ahsan
   Description: Brute Force
   Compiled: Visual C++ 7.0
   Date: 27-03-06
*/

#include <iostream>
#include <string>
using namespace std;

char data[20];
int min, k;

int pebbleCount(){
	int temp = 0;
	for (int i = 0; i < 12; ++i)
		if (data[i] == 'o')
			++temp;
	return temp;
}

void pebble(){
	if (pebbleCount() < min)
		min = pebbleCount();
	for (int i = 0; i < 10; ++i){
		if (data[i] == '-' && data[i+1] == 'o' && data[i+2] == 'o'){
			data[i] = 'o';
			data[i+1] = '-';
			data[i+2] = '-';
			
			if (pebbleCount() < min)
				min = pebbleCount();

			pebble();
			data[i] = '-';
			data[i+1] = 'o';
			data[i+2] = 'o';
			
		}
		else if (data[i] == 'o' && data[i+1] == 'o' && data[i+2] == '-'){
			data[i] = '-';
			data[i+1] = '-';
			data[i+2] = 'o';
			if (pebbleCount() < min)
				min = pebbleCount();

			pebble();
			data[i] = 'o';
			data[i+1] = 'o';
			data[i+2] = '-';
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int n;


	cin >> n;
	cin.getline(data, sizeof(data));//eat newline
	while (n--){

		cin.getline(data, sizeof(data));

		min = 12;
		pebble();
		cout << min << endl;

	}	

	return 0;
}
