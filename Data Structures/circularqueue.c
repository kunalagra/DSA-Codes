#include <stdio.h>
#define SIZE 5

int circqueue[SIZE];
int front = -1, rear = -1;


int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void enQueue(int element) {
  if (isFull())
	printf("\n Queue is full!! \n");
  else {
	if (front == -1) front = 0;
	rear = (rear + 1) % SIZE;
	circqueue[rear] = element;
	printf("\n Inserted -> %d", element);
  }
}
int deQueue() {
  int element;
  if (isEmpty()) {
	printf("\n Queue is empty !! \n");
	return (-1);
  } else {
	element = circqueue[front];
	if (front == rear) {
	  front = -1;
	  rear = -1;
	} 
	else {
	  front = (front + 1) % SIZE;
	}
	printf("\n Deleted element -> %d \n", element);
	return (element);
  }
}

void display() {
  int i;
  if (isEmpty())
	printf(" \n Empty Queue\n");
  else {
	printf("\n Front Pter-> %d ", front);
	printf("\n Items -> ");
	for (i = front; i != rear; i = (i+1) % SIZE) {
	  printf("%d ", circqueue[i]);
	}
	printf("%d ", circqueue[i]);
	printf("\n Rear Pter-> %d \n", rear);
  }
}
int menu(){
	int choice;
	printf("\n 1. Add value to the Queue");
	printf("\n 2. Delete value to the Queue");
	printf("\n 3. Display Queue");
	printf("\n 4. exit");
	printf("\n Please enter your choice: ");
	scanf("%d",&choice);
	return(choice);
}
void main(){
	int value,exitst=0;
	while(exitst==0){
		switch(menu()){
			case 1:
		   printf("Input for insertion: ");
			scanf("%d",&value);
				enQueue(value);
				break;
			case 2:
				deQueue();
				break;
			case 3:
				display();
				break;
			case 4:
				exitst++;
			default:
				printf("Invalid choice. Please try Again.");
		}
	}
} 