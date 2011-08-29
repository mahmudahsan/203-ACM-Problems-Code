/* Problem: Long Multiplication  UVa 338
   Programmer: Md. Mahmud Ahsan
   Description: Simulation + Big Number Multiplication
   Compiled: Visual C++ 7.0
   Date: 26-08-05
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

const int length = 2000;

void removeZero(char *str);
void reverseStr(char *one);
char *bigSum(char *sFirst, char *sSecond);
char *bigMult(char *sFirst, char *sSecond);

//======================================
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char str[100], temp[100], temp2[100], *x, *y, final[100];
	int xDigit, yDigit, maxDigit, width, i, j, fWidth;
	int _x, _y;

	while (cin.getline(str, sizeof(str))){
		if (str[0] == '0' && strlen(str) == 1) break;
		x = strtok(str, " \t\n");
		y = strtok(NULL," \t\n");
		
		removeZero(x); removeZero(y); // at the beginning zero deleted

		xDigit = strlen(x); 
		yDigit = strlen(y);

		strcpy(final, bigMult(x, y)); // final result;
	
		maxDigit = max(xDigit, yDigit); //for output hypen
		fWidth = width = strlen(final); 
		//fWidth not modify but width modify
		
		_x = atol(x); _y = atol(y);//used for detecting zero is input or not
		if ((_x == 0 || _y == 0)){
		//special case 
			cout.width(maxDigit); cout << x << endl;
			cout.width(maxDigit); cout << y << endl;
	
			for(i = 0; i < maxDigit; ++i) cout << "-";
			cout << endl;
			cout.width(maxDigit); cout << final << endl;
		}
		else if (maxDigit == 1){
			//for one hypen output
			cout.width(width); 	cout << x << endl;
			cout.width(width);	cout << y << endl;
			cout.width(width);
			for (i = 0; i < maxDigit; ++i) cout << "-";
			cout << endl;
			cout << final << endl;
		}
		else{
			//final case multiple digits
			int nonZero = 0;
			for (i = 0; y[i]; ++i){
				if (y[i] != '0') ++nonZero;
			}
			cout.width(width); cout << x << endl;
			cout.width(width); cout << y << endl;
		
			i = strlen(y)-1;
			if (i != 0){//if y contains multiple digit
				cout.width(width - maxDigit + 1);
				for (j = 0; j < maxDigit; ++j) cout << "-";
				cout << endl;
				
				for ( ; i >= 0; --i){
					temp[0] = y[i]; temp[1] = '\0'; // char become string
					strcpy(temp2, bigMult(temp, x));
					cout.width(width--); 
					if ((strcmp(temp2, "0") != 0) && (nonZero != 1))
						cout << temp2 << endl; 
				}
				if (nonZero == 1){
					cout.width(fWidth); cout << final << endl;
				}
				else{
					for (i = 0; i < fWidth; ++i) cout << "-";
					cout << endl;
					cout.width(fWidth); cout << final << endl;
				}
			}
			else{
				cout.width(width - maxDigit + 1);
                for (i = 0; i < maxDigit; ++i) cout << "-";
				cout << endl;
				cout.width(fWidth); cout << final << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
void removeZero(char *str){
	char temp[100];
	int i, j = -1, flag = 1;
	for (i = 0; str[i]; ++i){
		if (str[i] == '0' && flag) continue;
		temp[++j] = str[i];
		flag = 0;
	}
	if (flag)temp[++j] = '0';
	temp[++j] = '\0';
	strcpy(str, temp);
}

//========================================================================
char *bigMult(char *sFirst, char *sSecond){
// sFirst means first String, sSecond means second string
	char sTemp[length], sSum[length], sFinal[length];
	int iFirst, iSecond;
	int firstLen, secondLen;
	int i, j, t, carry, temp, putZero;
	
	// main calculation begins here
		sSum[0] = '\0';
		sTemp[0] = '\0';
			
		firstLen = strlen(sFirst) - 1;
		secondLen = strlen(sSecond) - 1;
		
	    // putZero used for to add zero after multiplication when addition is needed
	   // zero add to the empty space at right side after the first multiplicaton row
		putZero = -1;
		for (i = secondLen; i >= 0; --i){
		//sTemp used for a new multiplication for a line suppose 22 * 3 = 66
		// here  sTemp contains 66
			sTemp[0] = '\0';
			carry = t = 0;
			
			iSecond = sSecond[i] - 48;
			for (j = firstLen; j >= 0; --j){
				iFirst = sFirst[j] - 48;
				temp = (iFirst * iSecond) + carry;
				
				if (temp <= 9)
					carry = 0;
				else if (temp >= 10 && temp <= 19)
					carry = 1;
				else
					carry = temp / 10;
				
				sTemp[t++] = (temp % 10) + 48; 
			}
			sTemp[t] = '\0';
			++putZero;
					
			if (carry > 0){
				sTemp[t] = carry + 48;
				sTemp[++t] = '\0';
				
			}
			else
				sTemp[t] = '\0';
			
			// after putting carry string must be reversed	
			reverseStr(sTemp);			
			
			// if two or more lines, zero added [11 * 3] =  33 + 330
			for (int k = 0; k < putZero; k++)
				sTemp[t++] = '0';
			sTemp[t] = '\0';
			strcpy (sSum, bigSum(sSum, sTemp));
		}
		bool flag = true; // use for checking zeros
		int sSumLen = strlen(sSum);
		int kk = -1; // use for sFinal
		sFinal[0] = '0';
		

		for (i = 0; i < sSumLen; i++){
			if (flag && sSum[i] == '0')
				continue; // if zero leading
			else{ 
				flag = false;
				sFinal[++kk] = sSum[i];
			}
		}
		
		if (flag)
			sFinal[1] = '\0';
		else 
			sFinal[++kk] = '\0';
		
		return sFinal;
}
void reverseStr(char *one){
	char temp[length];
	int h = strlen(one) - 1;
	int i = 0;

	for (int j = h; j >= 0; j--){
		temp[i] = one[j];
		++i;
	}
	temp[i] = '\0'; // must set to null at last for "two" second string
	strcpy(one, temp);
}

char *bigSum(char *sFirst, char *sSecond){
	char sSum[length];
	int firstLen, secondLen;
	int iFirst, iSecond, iSum;
	int carry;
	int t;

	// here the main calculation Begins
		carry = 0;
		t = 0;
		sSum[0] = '\0';
		firstLen = strlen(sFirst) - 1;
		secondLen = strlen(sSecond) - 1;

		while (firstLen >= 0 || secondLen >= 0){
			iFirst = sFirst[firstLen] - 48;
			iSecond= sSecond[secondLen] - 48;
			
			if (firstLen < 0) iFirst = 0;
			if (secondLen < 0) iSecond = 0;

			iSum = iFirst + iSecond + carry;
			
			if (iSum > 9)
				carry = 1;
			else
				carry = 0;
	
			sSum[t] = (iSum % 10) + 48;
			++t;
			--firstLen;
			--secondLen;
		}
		if (carry == 1){
			sSum[t] = carry + 48;
			sSum[++t] = '\0';
		}
		else
			sSum[t] = '\0';
		
		reverseStr(sSum);
		return sSum;
}