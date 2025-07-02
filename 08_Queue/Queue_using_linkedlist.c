#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>


struct node {
	int data;
	struct node *next;
};

struct node *head=NULL, *tail=NULL;
int size_of_queue=0;

void clear_output(int num){
	printf("===========================================================================\n");
	while (num>0){
		printf("\r");
		printf("It will take you to input again in %d sec ",num);
		sleep(1);
		num--;
	}
	system("cls");
}


void enqueue(){
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nPlease enter the data to feed: ", &new_node->data);
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if (head==NULL){
		head=tail=new_node;
	}
	else{
		tail->next=new_node;
		tail=new_node;
	}
	size_of_queue++;
	clear_output(3);
}


void display(){
	
	if (size_of_queue==0){
		printf("Underflow condition. Queue is empty\n");
		clear_output(3);
	}
	else{
		struct node *temp;
		temp=head;
		printf("Elements of the list are: \n");
		while(temp!=NULL){
			printf("%d\n", temp->data);
			temp=temp->next;
		}
		clear_output(5);
	}
	
}


void view_size_of_queue(){
	printf("At the moment queue has %d elements.\n", size_of_queue);
	clear_output(3);
}

void dequeue(){
	if (size_of_queue==0){
		printf("Underflow condition, hence element cannot be removed from queue.\n");
		clear_output(3);
	}
	else{
		struct node *temp;
		temp=head;
		head=head->next;
		printf("Removed data from queue is %d\n",temp->data);
		free(temp);
		size_of_queue--;
		clear_output(4);
	}
	
}

void peek(){
	printf("First element of the queue is %d\n", head->data);
	clear_output(3);
}


int main(){
	
	int num;
	
	while ( 1 ) {
		printf("Please help me with following input:\n");
		printf("To add data to Queue 1:\n");
		printf("To view queue press 2:\n");
		printf("To view size of queue press 3\n");
		printf("To delete data from queue press 4\n");
		printf("To view top element press 5\n");
		printf("To exit from the code press 6\n");
		printf("Please enter your choice: ");
		scanf("%d", &num);
		
		
		if (num == 1){
			enqueue();
		}
		else if (num==2){
			display();
		}
		else if (num==3){
			view_size_of_queue();
		}
		
		else if (num==4){
			dequeue();
		}
		
		else if (num==5){
			peek();
		}
		else if (num==6){
			exit(1);
		}
		else {
			printf("Please enter a valid input\n");
		}
	system("cls");
	}
	
	return 0;
}
