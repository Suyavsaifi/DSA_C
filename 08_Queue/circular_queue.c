#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define N 5

int queue[N], front=-1, rear=-1;

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
	int data;
	if ((rear+1)%N==front){
		printf("Queue is full.\n");
	}

	else if (front==-1 && rear==-1){
		printf("\nPlease enter the data: ");
		scanf("%d", &data);
		front=rear=0;
		queue[rear]=data;
	}
	
	else{
		printf("\nPlease enter the data: ");
		scanf("%d", &data);
		rear = (rear+1)%N;
		queue[rear]=data;
	}
	clear_output(3);
}

void dequeue(){
	if (front==-1 && rear==-1)
		printf("Underflow condition\n");
	else if (front==rear){
		printf("Removed element is %d\n",queue[front]);
		front=rear=-1;
	}
	else{
		printf("Removed element is %d\n",queue[front]);
		front=(front+1)%N;
	}
	clear_output(4);
}


void display(){
	if (front==-1 && rear==-1)
		printf("Queue is empty, hence it cannot be displayed.\n");
	else {
		int i=front;
		while (i!=rear)
		{
			printf("%d\n",queue[i]);
			i=(i+1)%N;
		}
		printf("%d\n",queue[i]);
	}
	clear_output(5);
}


void peek(){
	if (front==-1 && rear==-1)
		printf("Queue is empty, hence it cannot be displayed.");
	else{
		printf("Top element is %d\n", queue[front]);
	}
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
//			view_size_of_queue();
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
