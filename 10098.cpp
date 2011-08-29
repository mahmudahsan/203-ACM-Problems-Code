/* Problem: Generating Fast, Sorted Permutation UVa 10098
   Programmer: Md. Mahmud Ahsan
   Description: Permutation, Using STL, sort(), next_permutation(), snail_sort()
   Compiled: Visual C++ 7.0
   Date: 10-07-05
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <class BidirectionalIterator>
void snail_sort(BidirectionalIterator first, BidirectionalIterator last){
	while (next_permutation(first, last)){
		copy(first, last, ostream_iterator<char>(cout, ""));
		cout << endl;
	}
}

int main(){
	int n, i, len;
	cin >> n;
	char str[15];

	
	for (i = 0; i < n; ++i){
		cin >> str;
		len = strlen(str);
		sort(str, str+len);
		
		
		cout << str << endl;
		
		snail_sort(str, str+len);
		
		cout << endl;

	}
	return 0;
}