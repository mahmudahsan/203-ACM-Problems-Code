/* Problem: The Seasonal War UVa 352
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 05-09-04
*/

#include <iostream>
#include <string>
using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0}; 
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
// as it contains 8 so in DFSvisit we must check 8

int n;
char array[100][100];

// prototlype
int valid(int, int);
int DFS();
void DFSvisit(int r, int c);

//================================================================================
int main(){
	char string[100];
	int i, j;
	int len;
	static int title = 1;

	while (cin >> n){
		len = 0;
		for (i = 0; i < 100; i++){
			for (j = 0; j < 100; j++)
				array[i][j] = 0;
		}

		for (i = 0; i < n; i++){
			cin >> string;
			len = strlen(string);

			for (j = 0; j < len; j++){
				array[i][j] = string[j] ;
			}
		}

		int result = DFS(); 
		cout << "Image number "<< title << " contains " << result << " war eagles." << endl;
		++title;
	}

	return 0;
}
//==================================================================================

int DFS(){
	int r, c, count = 0;
	for (r = 0; r < n; r++){
		for (c = 0; c < n; c++){
			if ('1' == array[r][c]){
				count++;
				DFSvisit(r, c);
			}
		}
	}
	return count;
}

void DFSvisit(int r, int c){
	int nr, nc, i;
	array[r][c] = '0';

	for (i = 0; i < 8; i++){
		nr = r + dr[i];
		nc = c + dc[i];
		if (valid(nr, nc) && '1' == array[nr][nc])
			DFSvisit(nr, nc);
	}

}

int valid(int r, int c){
	if (r < 0 || c < 0 || r >= n || c >= n)
		return 0;
	else
		return 1;
}
