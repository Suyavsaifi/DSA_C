#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>



struct node {
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head=NULL,*tail=NULL;
int size_of_list=0;

void clear_output(){
	int num=6;
	printf("\n===========================================================================\n");
	while (num>0){
		printf("\r");
		printf("It will take you to input again in %d sec ",num);
		sleep(1);
		num--;
	}
	system("cls");
}


void create_list(){
	struct node *temp, *new_node;
	int i;
	printf("Pleae enter the size of list: ");
	scanf("%d",&size_of_list);
	
	
	for (i=0;i<size_of_list;i++){
		new_node = malloc(sizeof(struct node));
		printf("\nPlease enter the data to node: ");
		scanf("%d",&new_node->data);
		if (head==NULL){
			head=temp=new_node;
		}
		else{
			temp->next=new_node;
			new_node->prev = temp;
			temp=new_node;
		}
	}
	tail = temp;
	tail->next = head;
	head->prev = tail;
	clear_output();
}


void display_list(){
	struct node *temp;
	temp = head;
	while(temp->next!=head){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
	clear_output();
}

void display_reverse_list(){
	struct node *temp;
	temp = tail;
	while(temp->prev!=tail){
		printf("%d\n",temp->data);
		temp=temp->prev;
	}
	printf("%d\n",temp->data);
	clear_output();
}

void view_size(){
	printf("%d\n", size_of_list);
	clear_output();
}


void prepend(){
	struct node *new_node;
	printf("\nPlease enter data to prepend: ");
	new_node = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &new_node->data);
	new_node->next = head;
	new_node->prev = tail;
	head->prev = new_node;
	head=new_node;
	tail->next = head;
	size_of_list++;
	clear_output();
}


void append(){
	struct node *new_node;
	printf("\nPlease enter the data to append: ");
	new_node = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&new_node->data);
	new_node->prev = tail;
	new_node->next = head;
	tail->next = new_node;
	tail = new_node;
	head->prev = tail;
	size_of_list++;
	clear_output();
}

void unprefix(){
	struct node *temp;
	temp = head;
	head = head->next;
	head->prev = tail;
	tail->next = head;
	free(temp);
	size_of_list--;
	printf("\nNode has been deleted from begining.\n");
	clear_output();
}

void unsuffix(){
	struct node *temp;
	temp=tail;
	tail=tail->prev;
	tail->next = head;
	head->prev=tail;
	free(temp);
	size_of_list--;
	printf("\nNode has been deleted from end.\n");
	clear_output();
}


void insert_at_r(){
	int pos, counter=1;
	printf("\nPlease enter the position to add the node: ");
	scanf("%d",&pos);
	if (size_of_list<=pos){
		append();
	}
	else{
			struct node *new_node, *temp;
			new_node = (struct node*)malloc(sizeof(struct node*));
			printf("Please enter the data to enter: ");
			scanf("%d",&new_node->data);
			temp=head;
			while(temp->next!=head){
				if (pos<=counter){
					new_node->next = temp->next;
					new_node->prev=temp;
					temp->next = new_node;
					temp=new_node->next;
					temp->prev = new_node;
					break;
				}
				counter++;
				temp=temp->next;
			}
			size_of_list++;
			clear_output();
	}
}

void delete_from_r(){
	int pos, counter=1;
	printf("\nPlease enter the position to delete node: ");
	scanf("%d", &pos);
	if (pos>size_of_list){
		unsuffix();
	}
	else{
		struct node *temp, *nextnode;
		temp=head;
		while(temp->next!=head){
			if (counter>=pos){
				nextnode=temp->next;
				temp->next = nextnode->next;
				temp=temp->next;
				temp->prev = nextnode->prev;
				free(nextnode);
				break; 
				
			}
			temp= temp->next;
			counter++;
		}
		size_of_list--;
		clear_output();
	}
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

