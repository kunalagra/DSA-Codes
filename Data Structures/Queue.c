#include<stdio.h>

void insert(int);
void delete(), peek(), display(), isFull(), isEmpty();

int arrsize=10, empty,full,setd=0;
int queuearr[10], f = -1, r = -1;

void main() {
	int value, option,exitst=1;
	while (exitst) {
		printf("\nSelect the Option to Execute:");
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Peek\n5. isFull\n6. isEmpty\n7. Exit\n");
		printf("\nEnter your option: ");
		scanf("%d", &option);
		switch (option) {
		case 1:
			printf("Enter the value to be insert: ");
			scanf("%d", &value);
			insert(value);
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		case 5:
			setd=1;
			isFull();
			break;
		case 6:
			setd=1;
			isEmpty();
			break;
		case 7:
			printf("Exiting..");
			exitst = 0;
			break;
		default:
			printf("\nPlease enter correct option. Retry");
		}
	}
	
}
void insert(int value) {
	setd=0;
	isFull();
	if(full==0) {
		if (f == -1)
			f = 0;
		r++;
		queuearr[r] = value;
		printf("\nInserted Successfully. Queue got updated");
	}
}
void delete() {
	setd=0;
	isEmpty();
	if (empty==0){
		printf("\nDeleted : %d", queuearr[f]);
		f++;
		printf("\nQueue is updated. Element is deleted.");
		if (r < f){
			printf("\nQueue has become empty. Initialize the Queue Again");
			r = f = -1;
		}
	}
}
void display() {
	setd=0;
	isEmpty();
	if (empty==0){
		int i;
		printf("\nQueue elements are:\n");
		for (i = f; i <= r; i++){
			printf(" %d |", queuearr[i]);
		}
	}
}

void peek(){
	setd=0;
	isEmpty();
	if (empty==0)
		printf("Front Value: %d\n",queuearr[f]);
}

void isFull(){
	if(r == arrsize-1){
		printf("\tQueue is Full\n");
		full = 1;
	}
	else {
		if (setd==1){
			printf("Queue is not full");
		}
		full = 0;
	}
}
void isEmpty(){
	if( r == -1 && f == -1){
		printf("Queue is Empty");
		empty=1;
	}
	else if (f>r){
		printf("Queue is Empty");
		empty=1;
	}
	else{
		if(setd==1){
			printf("Queue is not Empty.");
		}
		empty=0;
	}
}