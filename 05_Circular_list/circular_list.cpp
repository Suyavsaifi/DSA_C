// implemetation of circular linked list


#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

struct node *head;
int size_of_list=0;

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

void view_size(){
	printf("\nSize of list is %d\n",size_of_list);
	clear_output();
}

int create_list(){
	struct node *temp, *new_node;
	int i;
	printf("Please enter the size of list: ");
	scanf("%d",&size_of_list);
	for (i=0;i<size_of_list;i++){
		new_node = (struct node*)malloc(sizeof(struct node));
		printf("\nPlease enter the data to node: ");
		scanf("%d", &new_node->data);
		if (head==NULL){
			head=temp=new_node;
		}
		else {
			temp->next = new_node;
			temp = new_node;
		}
	}
	new_node->next = head;
	clear_output();
	
}


void append(){
	struct node *temp, *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nPlease enter data to node: ");
	scanf("%d", &new_node->data);
	temp = head;
	while (temp->next!=head){
		temp = temp->next;
	}
	new_node->next = head;
	temp->next = new_node;
	size_of_list++;
	clear_output();
	
}

void prepend(){
	struct node *temp, *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nPlease enter data to node: ");
	scanf("%d", &new_node->data);
	temp = head;
	while (temp->next!=head){
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->next = head;
	head = new_node;
	size_of_list++;
	clear_output();
	
	
}


void insert_at_r(){
	struct node *temp, *new_node;
	int counter, pos;
	counter=1;
	printf("\nPlease enter the position to enter data: ");
	scanf("%d", &pos);
	if (size_of_list<=pos)
	{
		printf("\nSize of list is lessor, so entering data at last.");
		append();
	}
	else {
			new_node = (struct node*)malloc(sizeof(struct node*));
			printf("\nPlease enter the data to feed: ");
			scanf("%d",&new_node->data);
			temp = head;
			
			while (temp->next!=head){
				if (counter>=pos){
					new_node->next = temp->next;
					temp->next = new_node;
					break;
				}
				temp=temp->next;
				counter++;
			}
			size_of_list++;
			clear_output();
		}
}


void unprefix(){
	struct node *temp;
	temp = head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next = head->next;
	temp=head;
	head=head->next;
	free(temp);
	size_of_list--;
	clear_output();
}

void unsuffix(){
	struct node *temp, *curr;
	temp=head;
	while(temp->next!=head){
		curr=temp;
		temp = temp->next;
	}
	curr->next = head;
	free(temp);
	size_of_list--;
	clear_output();
}


void delete_from_r(){
	struct node *temp, *curr;
	int pos, counter;
	counter = 1;
	printf("\nPlease enter the position where you want to delete data from: ");
	scanf("%d",&pos);
	if (size_of_list<=pos){
		printf("\nSize of list is lessor, hence deleting the data from last:");
		unsuffix();
	}
	else
	{
		temp = head;
		while (temp->next!=head){
			if (counter>=pos){
				curr->next=temp->next;
				break;
			}
			curr=temp;
			temp=temp->next;
			counter++;
		}
		size_of_list--;
		clear_output();
	}
	
}

void display_reverse_list(){
	struct node *curr, *nextnode, *prevnode;
	curr = head;
	prevnode=NULL;
	while (curr->next!=head){
		nextnode=curr->next;
		curr->next=prevnode;
		prevnode = curr;
		curr=nextnode;
	}
	curr->next = prevnode;
	head->next = nextnode;
	head = nextnode;
	clear_output();
	
}

void display_list(){
	struct node *temp;
	temp=head;
	while(temp->next!=head)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
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
