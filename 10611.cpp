/* Problem: The Playboy Chimp UVa 10611
   Programmer: Md. Mahmud Ahsan
   Description: Binary Search
   Compiled: Visual C++ 7.0
   Date: 18-08-05
*/

#include <stdio.h>
#define max 50002

int arr[max];

int binarySearch(int item, int size, int *l, int *h){	
	int low = 0, high = size - 1;
	int mid;
	
	while (low <= high){
		mid = (low + high) / 2;
		if (arr[mid] == item)
			return mid;
		else if (arr[mid]< item)
			low = mid + 1;
		else
			high = mid - 1;
	}
	//if no item match, low become higher and high become lower
	*l = low;
	*h = high;
	return -1;
}

int main(){
    int item, l, size, h, N, i, temp, prev;
	int result;

	i = -1;
	scanf("%d", &size);
	
	scanf("%d", &arr[++i]);//first element is inputed
	for (h = 1; h < size; ++h){
        scanf("%d", &temp);
		if (arr[i] == temp)
			continue; // as we ignore same input data element
		arr[++i] = temp;
	}
	size = i + 1; // modified size rejecting same elements
	
	scanf("%d", &N);
	for(i = 0; i < N; ++i){
		scanf("%d", &item);

		// special cases
		if (item < arr[0]){
			printf("X %d\n", arr[0]);
			continue;
		}
		else if (item == arr[0]){
			printf("X %d\n", arr[1]);
			continue;
		}
		else if (item > arr[size-1]){
			printf("%d X\n", arr[size-1]);
			continue;
		}
		else if (item == arr[size-1]){
			printf("%d X\n", arr[size-2]);
			continue;
		}

        result = binarySearch(item, size, &l, &h);
		
		if (result != -1)
			printf("%d %d\n", arr[result-1], arr[result+1]);
		else
			printf("%d %d\n", arr[h], arr[l]);
	}
	return 0;
}