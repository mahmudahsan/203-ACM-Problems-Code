/* Problem: Chess UVa 278
   Programmer: Md. Mahmud Ahsan
   Description: AD HOC
   Compiled: Visual C++ 7.0
   Date: 26-10-05
*/
#include <iostream>
#include <algorithm>
using namespace std;

char board[20][20];
int white, black;

int main(){
	//freopen("input.txt", "r", stdin);
	int test, m, n, i, j, result;
	char c;

	cin >> test;
	while (test--){
		cin >> c >> m >> n;

		if (c == 'k'){//knight
			bool flag = false;
			white = black = 0;

			//generating the board to obtain the number of black and white room
			for (i = 0; i < m; ++i){
				if (!flag) flag = true;
				else flag = false;

				for (j = 0; j < n; j+=2){
					if (flag) ++white;// board[i][j] = 'w';
					else ++black; //board[i][j] = 'b';
				}

				for (j = 1; j < n; j+=2){
					if (!flag) ++white; //board[i][j] = 'w';
					else ++black; //board[i][j] = 'b';
				}
			}
			result = max(black, white);
			cout << result << endl;
		}
		else if (c == 'r'){//rook
			result = min(m,n);
			cout << result << endl;
		}
		else if (c == 'Q'){//queen
			result = min(m,n);
			cout << result << endl;
		}
		else if (c == 'K'){//king
			result = ( ((m+1) / 2) * ((n+1)/2));
			cout << result << endl;
		}
	}

	return 0;
}