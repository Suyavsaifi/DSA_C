// implementation of doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>


struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head, *tail;
int size_of_list;

void clear_output(){
	int num=6;
	printf("===========================================================================\n");
	while (num>0){
		printf("\r");
		printf("It will take you to input again in %d sec ",num);
		sleep(1);
		num--;
	}
	system("cls");
}


void create_doubly_list(){
	struct node *temp, *new_node;
	head = NULL;
	printf("Please enter the size of list to create: ");
	scanf("%d", &size_of_list);
	int i;
	for (i=0;i<size_of_list;i++){
		new_node = (struct node*)malloc(sizeof(struct node));
		printf("\nPlease enter the number: ");
		scanf("%d", &new_node->data);
		new_node->next = NULL;
		if (head==NULL){
			head = temp = new_node;
			head->prev=NULL;
		}
		else
		{
			temp->next = new_node;
			new_node->prev = temp;
			temp=new_node;
		}
	}
	tail = new_node;
	clear_output();
	
}


void display_list(){
	struct node *temp;
	temp = head;
	while (temp!=NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	clear_output();
}


void prepend(){
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nPlease enter the data: ");
	scanf("%d",&new_node->data);
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	size_of_list++;
	clear_output();
}

void append(){
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nPlease enter the data: ");
	scanf("%d",&new_node->data);
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next=NULL;
	tail = new_node;
	size_of_list++;
	clear_output();
}

void view_size(){
	printf("\nSize of list is %d",size_of_list);
	clear_output();
}


void insert_at_r(){
	struct node *new_node, *temp;
	int pos, counter;
	counter = 1;
	temp = head;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nPlease enter the position to enter the number: ");
	scanf("%d", &pos);
	printf("\nPlease enter the data: ");
	scanf("%d",&new_node->data);
	
	while (temp!=NULL){
		if (counter>=pos){
			new_node->next = temp->next;
			new_node->prev = temp;
			temp->next = new_node;
			break;
			
		}
		temp = temp->next;
		counter++;
	}
	size_of_list++;
	clear_output();
	
}


void unprefix(){
	struct node *temp;
	temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
	size_of_list--;
	clear_output();
}


void unsuffix(){
	struct node *temp;
	temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
	size_of_list--;
	clear_output();
}


void delete_from_r(){
	struct node *temp, *new_node;
	int pos, counter;
	counter = 1;
	printf("\nPlease enter the position to delete the number: ");
	scanf("%d", &pos);
	temp = head;
	while (temp!=NULL){
	if (counter>=pos){
		new_node = temp;
		temp = temp->prev;
		temp->next = new_node->next;
		temp=temp->next;
		temp->prev = new_node->prev;
		free(new_node);
		break;
	}
	temp = temp->next;
	counter++;
}
	size_of_list--;
	clear_output();
}


void display_reverse_list(){
	// with this method we are just starting it with tail
//	struct node *temp;
//	temp = tail;
//	while (temp!=NULL){
//		printf("%d\n", temp->data);
//		temp = temp->prev;
//	}
	
	struct node *curr, *nextnode;
	curr = head;
	while(curr!=NULL){
		nextnode = curr->next;
		curr->next = curr->prev;
		curr->prev = nextnode;
		curr = nextnode;
		
	}
	curr = head;
	head = tail;
	tail = head;
	clear_output();
}

int main(){
	
	int num;
	
	while ( 1 ) {
		printf("Please help me with following input:\n");
		printf("To create list press 1:\n");
		printf("To view list press 2:\n");
		printf("To insert data at beginning press 3:\n");
		printf("To insert data at end press 4:\n");
		printf("To view size of list press 5\n");
		printf("To insert value at r press 6\n");
		printf("To delete the node from beginning press 7\n");
		printf("To delete from end press 8\n");
		printf("To delete the node from r position press 9\n");
		printf("To reverse the list press 10\n");
		printf("To exit from the code press 11\n");
		printf("Please enter your choice: ");
		scanf("%d", &num);
		
		
		if (num == 1){
			create_doubly_list();
		}
		else if (num==2){
			display_list();
		}
		else if (num==3){
			prepend();
		}
		
		else if (num==4){
			append();
		}
		
		else if (num==5){
			view_size();
		}
		
		else if (num==6){
			insert_at_r();
		}
		
		else if (num == 7){
			unprefix();
		}
		else if (num==8){
			unsuffix();
		}
		else if (num==9){
			delete_from_r();
		}
		else if (num==10){
			display_reverse_list();
		}
		else if (num==11){
			exit(1);
		}
		else {
			printf("Please enter a valid input\n");
			clear_output();
		}
	system("cls");
	}
	
	return 0;
	
}
