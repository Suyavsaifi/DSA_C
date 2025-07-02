// this file implement stack using array
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>


void clear_output(int num){
	printf("\n===========================================================================\n");
	while (num>0){
		printf("\r");
		printf("It will take you to input again in %d sec ",num);
		sleep(1);
		num--;
	}
	system("cls");
}


#define N 5

int stack[N], top=-1;


void push(){
	if (top==N-1){
		printf("\nThe stack is over flow you cannot add any value to it.");
	}
	else{
		top++;
		int num;
		printf("\nPlease enter the number you want to add: ");
		scanf("%d", &num);
		stack[top]=num;
	}
	clear_output(2);
}

void pop(){
	if (top==-1){
		printf("\nThe stack is underflowing you can do the pop operation.");
	}
	else{
		int item;
		item = stack[top];
		top--;
		printf("\nThe removed number is %d.",item);
	}
	clear_output(3);
}


void peek(){
	if (top==-1){
		printf("\nThe stack is empty.");
	}
	else{
		printf("\nLast fed element is %d.", stack[top]);
	}
	clear_output(3);
}

void display(){
	int i;
	for (i=0;i<=top;i++){
		printf("%d\n", stack[i]);
	}
	clear_output(5);
}

int main(){
	int choice;
	
	do {
		
		printf("-----------------------------------------\n");
		printf("|                                       |\n");
		printf("| To add element press 1                |\n");
		printf("| To remove element press 2             |\n");
		printf("| To view last fed element press 3      |\n");
		printf("| To view entire stack elements press 4 |\n");
		printf("| To exit press 0                       |\n");
		printf("|                                       |\n");
		printf("-----------------------------------------\n");
		printf("\nPlease enter your choice: ");
		scanf("%d",&choice);
		
		if (choice == 1)
			push();
		else if (choice ==2)
			pop();
		else if (choice==3)
			peek();
		else if (choice == 4)
			display();
		else
			printf("Invalid choice. Please enter correct number.");
	} while (choice!=0);
	system("cls");
	return 0;
}
