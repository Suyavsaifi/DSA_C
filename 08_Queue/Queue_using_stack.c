#include<stdio.h>
#include<stdlib.h>



#define N 5

int top1=-1, top2=-1, s1[N], s2[N];

int count=0;

void push1(int data){
	top1++;
	s1[top1]=data;
}


void push2(int data){
	top2++;
	s2[top2]=data;
}


int pop1(){
	return s1[top1--];
}

int pop2(){
	return s2[top2--];
}

void enqueue(int x){
	if (top1==N-1){
		printf("Queue is full.\n");
	}
	else{
		push1(x);
		count++;
	}
}

void dequeue(){
	int i, a, b;
	if (top1==-1){
		printf("Queue is empty.\n");
	}
	else{
		
		for (i=0;i<count;i++){
			a=pop1();
			push2(a);
		}
		b=pop2();
		count--;
		printf("Dequeued element is %d\n", b);
	}
	for (i=0;i<count;i++){
			a=pop2();
			push1(a);
		}
	
}

void display(){
	int i;
	printf("Elements of the queue are: \n");
	for (i=0;i<=top1;i++){
		printf("%d\n", s1[i]);
	}
}

int main(){
	enqueue(2);
	enqueue(5);
	enqueue(-1);
	display();
//	peek();
	dequeue();
//	peek();
	enqueue(0);
	enqueue(7);
	display();
	
	return 0;
}
