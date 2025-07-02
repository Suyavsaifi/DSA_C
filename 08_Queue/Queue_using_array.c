#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define N 5

int queue[N], front=-1, rear=-1;


void enqueue(int data){
	if (rear==N-1)
		printf("Overflow condition.\n");
	else if (front==-1 && rear==-1){
		front=rear=0;
		queue[rear]=data;
	}
	else{
		rear++;
		queue[rear]=data;
	}
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
		front++;
	}
}


void display(){
	if (front==-1 && rear==-1)
		printf("Queue is empty, hence it cannot be displayed.\n");
	else {
		int i;
		for(i=front;i<=rear;i++){
			printf("%d\n",queue[i]);
		}
	}
}


void peek(){
	if (front==-1 && rear==-1)
		printf("Queue is empty, hence it cannot be displayed.");
	else{
		printf("Top element is %d\n", queue[front]);
	}
}


int main(){
	enqueue(2);
	enqueue(5);
	enqueue(-1);
	display();
	peek();
	dequeue();
	peek();
	enqueue(0);
	enqueue(7);
	display();
	
	return 0;
}
