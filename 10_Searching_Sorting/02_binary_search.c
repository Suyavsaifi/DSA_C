#include <stdio.h>



int binary_search(int num, int arr[], int max){
	int min=0, mid;
	min = 0;
	while (min<=max){
		mid = (min+max)/2;
		if (arr[mid]==num){
			return mid;
		}	
		else if (arr[mid]>num) {
			max=mid-1;
		}
		else {
			min=mid+1;
		}
	}
	return -1;
}



int main(){
	int idx, num, max;
	num=10;
	int array[] = { 2, 3, 4, 10, 40 };
	max = sizeof(array)/sizeof(array[0]);
	idx = binary_search(num,array, max);
	if (idx==-1){
		printf("%d not found in array\n", num);
	}
	else {
		printf("%d found at %d index\n", num, idx);
	}
	return 0;
}
