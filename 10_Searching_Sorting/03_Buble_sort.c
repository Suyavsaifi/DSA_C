#include<stdio.h>

//Bubble Sort is a comparison based simple sorting algorithm that works by comparing
//the adjacent elements and swapping them if the elements are not in the correct order.
//It is an in-place and stable sorting algorithm that can sort items in data structures
//such as arrays and linked lists.


int main(void){
	int array[] = {-2, 45, 0, 11, -9}, size, i,j, temp;
	
	size = sizeof(array)/sizeof(array[0]);
	
	
	printf("Array before sorting\n");
	for (i=0;i<size;i++){
		printf("%d\t", array[i]);
	}
	
	// buble sort
	for (i=0;i<size-1;i++){
		for (j=0;j<size-1-i;j++){
			if (array[j]>array[j+1]){
				temp = array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	printf("\nArray after sorting\n");
	for (i=0;i<size;i++){
		printf("%d\t", array[i]);
	}
	
}
