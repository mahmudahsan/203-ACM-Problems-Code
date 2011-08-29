/* Problem: Polygon Inside A Circle  UVa 10432
   Programmer: Md. Mahmud Ahsan
   Compiled: Visual C++ 6.0
   Date: 19-08-04
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(){
	 
  int n; 
  double area, dn, dr; 
  double al; 
   
  while (scanf("%lf %d",&dr,&n) == 2){ 
    	dn = (double) n; 
	al = sin(acos(-1.0)*2.0/n); 
    	area = (al*dr*dr*dn)*0.5; 
    	printf("%.3lf\n",area); 
  } 
  return 0; 
} 


 
  