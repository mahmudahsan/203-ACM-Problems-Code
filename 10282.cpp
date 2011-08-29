/* UVA: Babelfish  prob: 10282
Programmer: Md. Mahmud Ahsan
Visual C++ 6
IN Lab
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct dic{
	char foreign[12];
	char english[12];
}dict[100005];

int bSearch(char *str, int max){
	int mid, low, high, cmp;
	low = 0;
	high = max;

	while (low <= high){
		mid = (low + high) / 2;

		cmp = strcmp(dict[mid].foreign, str);
		if (cmp == 0)
			return mid;
		else if (cmp > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int cmp(const void *a, const void *b){
	dic *x, *y;
	x = (dic*) a;
	y = (dic*) b;
	
	return strcmp(x->foreign, y->foreign);
}


int main(){
	freopen("input.txt", "r", stdin);

	int i = 0, j;
	char str[100], a[100], b[100];

	while(gets(str)){
		if (strlen(str) == 0) break;

		sscanf(str, "%s %s", a, b);
		
		strcpy(dict[i].english, a);
		strcpy(dict[i].foreign, b);
		++i;
	}
	qsort(dict, i, sizeof(dict[0]), cmp);


	while (cin >> str){
		j = bSearch(str, i);
			
		if (j >= 0)
			cout << dict[j].english << endl;
		else
			cout << "eh" << endl;
	}

	return 0;
}
