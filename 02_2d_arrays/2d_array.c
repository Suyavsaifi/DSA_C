// 2D arrays


#include<stdio.h>
#include <stdlib.h>



int main(){
	int a[2][3], i, j;
	printf("Please enter the element\n");
	for (i=0;i<2;i++){
		for (j=0;j<3;j++){
			printf("Please enter at %d row and %d columns\n", i,j);
			scanf("%d",&a[i][j]);
		}
	}
	system("cls"); // this will clear the values from console
	printf("Printing arrays: \n");
	for (i=0;i<2;i++){
		for (j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("%d", *(*a+1));
	return 0;
}



