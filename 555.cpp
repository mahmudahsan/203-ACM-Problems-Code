/* Problem: Bridge Hands UVa 555
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC + Sorting
   Compiled: Visual C++ 7.0
   Date: 07-12-05
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node{
	char cSuit; // card's character (N, E, S, W)
	char cValue; // card's value Character (1, 2..T, J)
	int suit;  // card's defineing suit value (1, 2, 3, 4) for 4 type cards
	int value;// card's defining value (A = 14 ...)
}N[13], E[13], S[13], W[13];
//global declaration
char ch, t, temp[100], first[200], second[200];
int now, suit, i, a,b,c,d, val;
	
int comp(node a, node b){
	if (a.suit != b.suit)
        return a.suit < b.suit;
	return a.value < b.value; 
}

void init(char *first); // its the main function

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (cin.getline(temp, sizeof(temp))){
		if (strcmp(temp, "#") == 0) break;
		
		a = b = c = d = -1;
		if (temp[0] == 'N')
			now = 1;
		else if (temp[0] == 'E')
			now = 2;
		else if (temp[0] == 'S')
			now = 3;
		else if (temp[0] == 'W')
			now = 4;

		cin.getline(first, sizeof(first));
		cin.getline(second, sizeof(second));

		init(first);
		init(second);
		sort(N, N+13, comp);
		sort(E, E+13, comp);
		sort(S, S+13, comp);
		sort(W, W+13, comp);
		
		cout << "S:";  
		for (i = 0; i < 13; ++i) 
			cout << " " << S[i].cSuit << S[i].cValue;
		cout << endl;
		cout << "W:";  
		for (i = 0; i < 13; ++i) 
			cout << " " << W[i].cSuit << W[i].cValue;
		cout << endl;
		cout << "N:";  
		for (i = 0; i < 13; ++i) 
			cout << " " << N[i].cSuit << N[i].cValue;
		cout << endl;
		cout << "E:";  
		for (i = 0; i < 13; ++i) 
			cout << " " << E[i].cSuit << E[i].cValue;
		cout << endl;
	}

	return 0;
}

void init(char *first){
	for (i = 0; first[i]; i+=2){
		now = now % 4 + 1; // we deal cards next to us
		ch = first[i]; // suit
		switch(ch){
			case 'C': suit = 1; break;
			case 'D': suit = 2; break;
			case 'S': suit = 3; break;
			case 'H': suit = 4; break;
		}
		t = first[i+1];// value
		
		if (t == 'T')
			val = 10;
		else if (t == 'J')
			val = 11;
		else if (t == 'Q')
			val = 12;
		else if (t == 'K')
			val = 13;
		else if (t == 'A')
			val = 14;
		else 
			val = t-48;
	
		switch(now){
			case 1: ++a; N[a].cSuit = ch; N[a].cValue = t; N[a].suit = suit; N[a].value = val; break;
			case 2: ++b; E[b].cSuit = ch; E[b].cValue = t; E[b].suit = suit; E[b].value = val; break;
			case 3: ++c; S[c].cSuit = ch; S[c].cValue = t; S[c].suit = suit; S[c].value = val; break;
			case 4: ++d; W[d].cSuit = ch; W[d].cValue = t; W[d].suit = suit; W[d].value = val; break;
		}
		
	}//end for loop
}