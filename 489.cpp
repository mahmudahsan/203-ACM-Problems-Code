/* Problem: Hangman UVa 489
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 25-03-05
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	char strSol[50];
	char strGuess[50];
	int round;
	
	int sol[50][2];
	int guess[50][2];
	int i, j, lenSol, lenGuess;

	while (true){
		cin >> round;
		if (round == -1) break;

		cin >> strSol >> strGuess;
		
		lenSol = strlen(strSol);
		for (i = 0; i < lenSol; ++i){
			sol[i][0] = strSol[i];
			sol[i][1] = 1;
		}

		lenGuess = strlen(strGuess);
		for (i = 0; i < lenGuess; ++i){
			guess[i][0] = strGuess[i];
			guess[i][1] = 1;
		}

		for (j = 0; j < lenGuess; ++j){
			for (i = 0; i < lenSol; ++i){
				if (guess[j][0] == sol[i][0]){
					guess[j][1] = sol[i][1] = 0;
				}
			}
		}

		int resSol = 0;
		for (i = 0; i < lenSol; ++i){
			if (sol[i][1] == 1)
				++resSol;
		}

		int resGuess = 0;
		for (i = 0; i < lenGuess; ++i){
			if (guess[i][1] == 1)
				++resGuess;
		}

		cout << "Round " << round << endl;

		if (resSol == 0 && resGuess < 7)
			cout << "You win." << endl;
		else if (resSol != 0 && (resGuess < 7 || resGuess > 7))
			cout << "You chickened out." << endl;
		else{
			cout << "You lose." << endl;
		}
	}

	return 0;
}