#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>


struct node {
	int data;
	struct node *next;
};

struct node *head;
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

// this function display the linked list
void display_list(){
	struct node *temp;
	temp = head;
	if (temp!=NULL) {
		while (temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
	else {
		printf("List does not exist. Please create list first:\n");
	}
	clear_output();
}


// this function create the linked list
void create_list(){
	
	struct node *new_node, *temp;
	head=NULL;
	printf("Please enter the size of list: ");
	scanf("%d", &size_of_list);
	int i;
	for (i=0;i<size_of_list;i++){
		new_node = (struct node*) malloc(sizeof(struct node));
		printf("Please enter the data to the node: ");
		scanf("%d",&new_node->data);
		new_node->next = NULL;
		if (head==NULL){
			head = temp=new_node;
		}
		else{
			temp->next = new_node;
			temp = new_node;
		}
	}
	
	clear_output();
}


void prepend() {
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	printf("Please enter data to the new node: ");
	scanf("%d",&new_node->data);
	new_node->next = head;
	head = new_node;
	size_of_list++;
	clear_output();
	
}


void unprefix() {
	struct node *temp;
	temp = head;
	head = head->next;
	free(temp);
	size_of_list--;
	clear_output();
	
}


void append(){
	struct node *new_node, *temp;
	new_node = (struct node*) malloc(sizeof(struct node));
	printf("Please enter data to the new node: ");
	scanf("%d",&new_node->data);
	new_node->next = NULL;
	temp = head;
	if (temp!=NULL) {
		while (temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = new_node;
	}
	else {
		printf("List does not exist. Please create list first:\n");
	}
	size_of_list++;
	clear_output();
}


void unsuffix() {
	struct node *temp, *curr;
	temp = head;
	while (temp->next!=NULL){
		curr=temp;
		temp=temp->next;
	}
	curr->next=NULL;
	free(temp);
	size_of_list--;
	clear_output();
	
}


void insert_at_r(){
	struct node *new_node, *temp;
	int num, count=1;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("Please enter the position to feed the number. Position start from 1.: ");
	scanf("%d", &num);
	printf("\nPlease enter the data to feed: ");
	scanf("%d",&new_node->data);
	temp = head;
	while (temp->next!=NULL){
		if (count==num){
			new_node->next=temp->next;
			temp->next=new_node;
			break;
		}
		temp=temp->next;
		count++;
	}
	size_of_list++;
	clear_output();
}


void delete_from_r(){
	struct node *curr, *temp;
	int num, count=1;
	printf("Please enter the position to delete the node. Position start from 1.: ");
	scanf("%d", &num);
	temp = head;
	while (temp->next!=NULL){
		if (count==num){
			curr->next=temp->next;
			free(temp);
			break;
		}
		curr = temp;
		temp=temp->next;
		count++;
	}
	size_of_list--;
	clear_output();
}

// this is my method and it is well optimized.
//void reverse_linked_list(){
//	struct node *temp, *N;
//	temp = head;
//	N= temp->next;
//	head->next=NULL;
//	while (N!=NULL){
//		temp=N;
//		N=temp->next;
//		temp->next=head;
//		head=temp;	
//	}
//	clear_output();
//	
//}

void reverse_linked_list(){
	struct node *temp, *next_node, *prev_node;
	temp = next_node= head;
	prev_node = NULL;
	while (next_node!=NULL){
		next_node=next_node->next;
		temp->next=prev_node;
		prev_node=temp;
		temp=next_node;
	}
	head = prev_node;
	clear_output();
	
}

void view_size(){
	printf("The size of the list is %d. \n", size_of_list);
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
			create_list();
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
			reverse_linked_list();
		}
		else if (num==11){
			exit(1);
		}
		else {
			printf("Please enter a valid input\n");
		}
	system("cls");
	}
	
	return 0;
}
