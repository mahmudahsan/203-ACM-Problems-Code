/* Problem: Parentheses Balance UVa 673
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 14-09-04
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


//=============================================================================
int main(){
	bool flag; 
	int test;
	// vector used here as like as stack
	vector <char> v;
	char c[30], str[200];
	int i;
	
	// Here a critical style input is taken. As I got 3 times wrong answer.
	cin.getline(c, sizeof(c));
	sscanf(c, "%d", &test);

	for (int t = 0; t < test; t++){
		i = 0;
		flag =false;
	
		cin.getline(str, sizeof(str));
		while (str[i]){         
			flag = true; // it's reason described below
			
			if (str[i] == ')' && v[v.size()-1] == '(' && !v.empty()){
				v.pop_back();
			}
			else if (str[i] == ']' && v[v.size() - 1] == '[' && !v.empty()){
				v.pop_back();
			}
			else if (str[i] == ')' && v[v.size() - 1] == '['&& !v.empty())
				break;
			else if (str[i] == ']' && v[v.size() - 1] == '('&& !v.empty())
				break;
			else
				v.push_back(str[i]);
			
			++i;
		}
		
		// if I not use it, then this function calls automatically before whileloop
		if (flag) {
		    if (v.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
				v.clear();	
			}	
		else
			cout << "Yes" << endl;
	}
	return 0;
}
//===========================================================================
