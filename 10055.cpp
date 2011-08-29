#include <iostream.h>
#include <stdio.h>
#include <math.h>

int main(){
	long double a, b;

	while (cin >> a >> b){
		printf("%.0lf\n", fabs(a-b));
	}
	return 0;
}

