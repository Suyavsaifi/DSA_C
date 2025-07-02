#include<stdio.h>

int main(){
	
	# Traversing of array
	
	int arr[10], size, i;
	
	printf("Please enter the size of array\n");
	scanf("%d",&size);
	
	for (i=0;i<size;i++){
		printf("\nplease enter element at position %d: ", i);
		scanf("%d", &arr[i]);
		
	}
	
	printf("\nPrinting Array:");
	for (i=0;i<size;i++){
		printf("\narrays element are %d: ", arr[i]);
	}
	
	
	
	
	return 0;




}
