/* Problem: Vito's family UVa 10041
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 07-10-04
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//typedef type
typedef long int lint;

void insertion(lint array[], lint size);
//================================================================================
int main(){
	lint test;
	lint relative;
	lint dataSet[30005];
	/*  minSum = minimal sum of distances 
		optimal = optimal here means middle of the street
	*/
    lint optimal, minSum, temp; 
	int i, j;

	cin >> test;

	for (i = 0; i < test; i++){
		minSum = 0;

		for (j = 0; j < 30005; j++)
			dataSet[j] = 0;

		cin >> relative;
		for (j = 0; j < relative; j++)
			cin >> dataSet[j];
		
		// street numbers must be sorted
		insertion(dataSet, relative);
		optimal = relative / 2;

		for (j = 0; j < relative; j++){
			// distance between two street number d[i][j] = abs(s[i] - s[j]) 
			temp = abs (dataSet[optimal] - dataSet[j]);
			minSum += temp;
		}
		cout << minSum << endl;
	}
	return 0;
}
//===============================================================================
void insertion(lint array[], lint size){
	lint i, j, key;

	for (j = 1; j < size; j++){
		key = array[j];
		i = j - 1;

		while (i >= 0 && array[i] > key){
			array[i+1] = array[i];
			i = i - 1;
		}
		array[i+1] = key;
	}
}