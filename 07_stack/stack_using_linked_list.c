// implementation of stack using linked list.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define N 5

int top=-1;

struct node {
	int data;
	struct node *next;
};

struct node *head=NULL;

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


void push(){
	if (top>=N-1){
		printf("\nStack is full. No new data can be added.");
	}
	else{
		struct node *new_node;
		new_node = (struct node*)malloc(sizeof(struct node));
		printf("\nPlease enter the data to feed: ");
		scanf("%d", &new_node->data);
		new_node->next=NULL;
		if (head==NULL){
			head=new_node;
		}
		else{
			new_node->next=head;
			head=new_node;
		}
		top++;
		
	}
	clear_output(2);
}


void peek(){
	printf("\nLast fed value is %d.", head->data);
	clear_output(3);
}


void pop(){
	struct node *temp;
	if (top==-1){
		printf("\nThere is no data in stack to remove.");
	}
	else{
		temp=head;
		head=head->next;
		printf("\nRemoved data from stack is %d", temp->data);
		free(temp);
		top--;
	}
	
	clear_output(2);
}


void display(){
	struct node *temp;
	temp=head;
	while (temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
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
