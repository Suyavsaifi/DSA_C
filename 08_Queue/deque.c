#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 5

int front=-1, rear=-1, deque[N];


int input_data(){
	int data;
	printf("\nPlease enter the data to feed: ");
	scanf("%d", &data);
	return data;
}

void clear_output(int num){
	while (num>=0){
		printf("\r");
		printf("Code will take you to new input in %d sec.", num);
		sleep(1);
		num--;
	}
	system("cls");
	
}


void einsert(){
	int num;
	if (front==-1 && rear==-1){
		num=input_data();
		rear=front=0;
		deque[rear] = num;
	}
	else if ((rear+1)%N==front){
		printf("Deque is full.\n");
	}
	else{
		num=input_data();
		rear = (rear+1)%N;
		deque[rear]=num;
	}
	clear_output(1);
	
}

void binsert(){
	int num;
	if (front==-1 && rear==-1){
		front=rear=0;
		num=input_data();
		deque[front]=num;
	}
	else if ((rear+1)%N==front){
		printf("Deque is full.\n");
	}
	else if (front==0){
		num=input_data();
		front=N-1;
		deque[front]=num;
	}
	else{
		front--;
		num=input_data();
		deque[front]=num;
	}
	clear_output(1);
}

void edelete(){
	if (front==-1 && rear==-1){
		printf("Deque is empty.\n");
	}
	else if (rear==front){
		printf("Deleted element from end is %d\n.", deque[rear]);
		rear=front=-1;
	}
	else if (rear==0){
		printf("Deleted element from end is %d\n.", deque[rear]);
		rear=N-1;
	}
	else{
		printf("Deleted element from end is %d\n.", deque[rear]);
		rear--;
	}
	clear_output(2);
}

void bdelete(){
	if (front==-1 && rear==-1){
		printf("Deque is empty.\n");
	}
	else if (front==rear) {
		printf("Dequeued element is %d.\n", deque[front]);
		front=rear=-1;
	}
	else{
		printf("Dequeued element is %d.\n", deque[front]);
		front=(front+1)%N;
	}
	clear_output(2);
}

void peek(){
	if (front==-1 && rear==-1){
		printf("Deque is empty.\n");
	}
	else{
		printf("Top element is %d.\n", deque[front]);
	}
		
	clear_output(3);
}

void display(){
	if (front==-1 && rear==-1){
		printf("deque is empty.\n");
	}
	else{
		int count;
		count=front;
		while (count!=rear){
			printf("%d\n", deque[count]);
			count=(count+1)%N;
						   }
		printf("%d\n", deque[count]);
	}
	clear_output(2);
}

main(){
	int input_val;
	while(1){
		printf("Please press 1 to enter data from rear end of deque\n");
		printf("Please press 2 to enter data from front end of deque\n");
		printf("Please press 3 to delete data from rear end of deque\n");
		printf("Please press 4 to delete data from front end of deque\n");
		printf("Please press 5 to peek into deque\n");
		printf("Please press 6 to display deque\n");
		printf("To exit press 7\n");
		printf("Please enter your choice: ");
		scanf("%d", &input_val);
		
		if (input_val==1)
			einsert();
		else if (input_val==2)
			binsert();
		else if (input_val==3)
			edelete();
		else if (input_val==4)
			bdelete();
		else if (input_val==5)
			peek();
		else if (input_val==6)
			display();
		else if (input_val==7)
			exit(1);
		else
			{
				printf("Please enter the valid input\n");
				clear_output(1);
			}
			
	}
	return 0;
}


