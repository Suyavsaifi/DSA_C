#include<stdio.h>


int main(void){
	int array[] = {-2, 45, 0, 11, -9}, size, i,j, temp, flag;
	
	size = sizeof(array)/sizeof(array[0]);
	
	
	printf("Array before sorting\n");
	for (i=0;i<size;i++){
		printf("%d\t", array[i]);
	}
	
	// buble sort
	for (i=0;i<size-1;i++){
		flag=0;
		for (j=0;j<size-1-i;j++){
			if (array[j]>array[j+1]){
				temp = array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				flag=1;
			}
		}
		if (flag==0)
			break;
	}
	printf("\nArray after sorting\n");
	for (i=0;i<size;i++){
		printf("%d\t", array[i]);
	}
	
}
