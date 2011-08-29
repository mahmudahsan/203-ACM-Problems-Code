//11172
#include <iostream>
#include <string>
using namespace std;

int main(){
	long long a, b;
	int n;

	cin >> n;

	while (n--){
		cin >> a >> b;
		if (a > b) cout << ">" << endl;
		else if (a < b) cout << "<" << endl;
		else cout << "=" << endl;
	}

	return 0;
}
