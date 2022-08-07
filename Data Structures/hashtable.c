#include <stdio.h>
#include <string.h>
int i=0, size;

void insert(int arr[]){
	int n, item;
	printf("\n Enter Key Element: ");
	scanf("%d",&item);
	n = item % size;
	while(arr[n]!='\0')
	{
		n = (n+1) % size;
		i++;
		if(i==size)
			break;
	}	
	if (i==size)	
		printf("\nHash Table is Full");
	else{
		arr[n]=item;
		printf("\nElement added");
	} 
}
void display(int arr[]){
	printf("\nIndex \t\t Key\n");
	for(int i =0;i<size;i++)
		printf("%d \t\t %d\n",i,arr[i]);
	printf("No. of collison %d",i);

}
int menu(){
	int choice;
	printf("\n1. Add value to the Table");
	printf("\n2. Display Table");
	printf("\n3. exit");
	printf("\nPlease enter your choice: ");
	scanf("%d",&choice);
	return(choice);
}
int main(){
	int a=1;
	printf("Enter Size of Array: ");	
	scanf("%d", &size);
	int arr[size];
	memset( arr, 0, sizeof(arr) );
	while(a){
		switch(menu()){
			case 1:
				insert(arr);
				break;
			case 2:
				display(arr);
				break;
			case 3:
				a=0;
				break;
		}
	}

}