/* Problem: Automatic Editing UVa 10115
   Programmer: Md. Mahmud Ahsan
   Description: String + replacing
   Compiled: Visual C++ 7.0
   Date: 30-08-05
*/
#include <iostream>
#include <string>
using namespace std;

struct dic{
	char key[500];
	char value[500];
}dics[100];

int main(){
	char key[500], value[500], input[1000];
	int n, i, j, count;
	
	while (cin >> n){
		cin.getline(input, sizeof(input)) ;// eat blank line
		if (n == 0) break;
		
		j = 0;
		for (i = 0; i < n; ++i){
			cin.getline(key, sizeof(key));
			cin.getline(value, sizeof(value));
			strcpy(dics[j].key, key);
			strcpy(dics[j].value, value);
			++j;
		}
		
		cin.getline(input, sizeof(input));
		string buffer(input); // converting char* to string object

		for (i = 0; i < n; ++i){//rules are applied
			do{
				count = 0;
				int pos;
				while ( (pos = buffer.find(dics[i].key)) != string::npos){
					buffer.replace(pos, strlen(dics[i].key), dics[i].value);
					++count;
				}
				if (count == 0) break;//no new match
			}while (true);
		}	
		cout << buffer << endl;
	}
	return 0;
}