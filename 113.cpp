#include <stdio.h>
#include <math.h>

int main (){
	long double result;
	long double i,j,k,l;

    for( ;scanf("%Lf%Lf",&i,&j)==2; )
	{
		k=log(j);
		l=k/i;
		result = exp(l);
		printf("%.0Lf\n",result);
	}
	return 0;
}