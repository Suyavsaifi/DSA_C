#include<stdio.h>

#define N 8

int array[] = {10, 50, 30, 70, 80, 20, 90, 40};


void linear_search(num){
	int i;
	for(i=0;i<N;i++){
		if (array[i]==num){
			printf("%d has found on %d", num, i);
			break;
		}
	}
	if (i==N){
		printf("%d not found i array", num);
	}
}



int main(){
	int num;
	printf("\nPlease provide the number to search in array: ");
	scanf("%d", &num);
	linear_search(num);
	return 0;
}
