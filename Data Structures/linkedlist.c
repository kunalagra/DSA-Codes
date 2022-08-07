#include <stdio.h>
#include <stdlib.h>

/*
struct node includes a pointer to itself. From the point-of-view of the compiler, it ensures that struct node has a member that is a pointer to struct node before it has even completed the statement (reached the semicolon) creating struct node. The somewhat similar declaration replacing struct node *next with struct node next is NOT allowed in C: a structure cannot contain a member of the same type!
*/
struct nodes{
	int data;
	// self Referential structure
	struct nodes * nextnode;
};
struct nodes *l_node, *f_node, *t_node = 0, *prev_node;

int value;

int count(){
	int count = 0;
	t_node = f_node;
	while (t_node != 0){
		count++;
		t_node = t_node->nextnode;
	}
	printf("\nNo Of Items In Linked List : %d\n", count);
	return count;
}
void display(){
	int count = 0;
	t_node = f_node;
	printf("Linked List: \n");

	printf("%p", t_node);
	while (t_node != 0){
		printf(" --> || %d | %p ||", t_node->data, t_node->nextnode);
		count++;
		t_node = t_node->nextnode;
	}
}
void insertask(){
	printf("\nEnter Element to Insert: ");
	scanf("%d", &value);
		/*
	malloc allocates sizeof(struct node) bytes, and returns a void pointer to it, which we cast to struct node *
	*/

	t_node = (struct nodes *) malloc(sizeof(struct nodes));
	t_node->data = value;
}

void insertbeg(){
	insertask();
	if (f_node == 0){
		// Initialize the linked List
		f_node = t_node;
		f_node->nextnode=0;
	}
	else{
		t_node->nextnode = f_node;
	}
	f_node = t_node;
}
void insertend(){
	insertask();
	if (f_node == 0){
		// Initialize the linked List
		f_node = t_node;
	}
	else{
		// previous nextnode gets address of new node
		// eg. if 2nd node, First node nextnode will be updated
		// to have ptr to 2nd node. Similarly, when 3rd node is added, 
		// 2nd node's nextnode is updated with ptr pointing to 3rd node
		l_node->nextnode = t_node;
	}

	// update temp node's nextnode to null address (Making it last)
	t_node->nextnode = 0;
	// updates lastnode's pointer to temp node's pointer
	// ie from 2nd node to 3rd node(new)
	l_node = t_node;
}
void inser_at_pos()
{  
    int i,loc,item;   
    struct nodes *ptr, *temp;
	ptr = (struct nodes *) malloc (sizeof(struct nodes));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value: ");  
        scanf("%d",&item);  
		ptr->data = item;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("\n%d",&loc);  
        temp=f_node;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->nextnode;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->nextnode = temp ->nextnode;   
        temp ->nextnode = ptr;   
        printf("\nNode inserted");  
    }  
}  
void deletebeg(){
	if(f_node==NULL){
		printf("Empty List");
	}
	else{
		t_node=f_node;
		f_node = t_node->nextnode;
		free(t_node);
		printf("First Node Deleted");

	}
}
void deleteend(){
	struct nodes *ptr;  
	if(f_node==NULL){
		printf("Empty List");
	}
	else if (f_node->nextnode==NULL){
		f_node=NULL;
		free(f_node);
		printf("Only Node Deleted");
	}
	else{
		t_node = f_node;
		while(t_node->nextnode!=NULL){
			ptr = t_node;
			t_node = t_node->nextnode;
		}
		ptr->nextnode=NULL;
		free(t_node);
		printf("Deleted Last Node");

	}
}
void delete_at_pos(){
	int countv, loc, i = 0;
	countv = count();
	t_node = f_node;
	printf("\nEnter Position to Dlete: ");
	scanf("%d", &loc);
	if (f_node==0){
		printf("Empty Linked list");
	}

	else if (loc > 0 && loc <= countv){
		if (loc == 1){
			t_node = t_node->nextnode;
			f_node = t_node;
			printf("\nElement Deleted Successfully \n\n");
		}
		else{
			while (t_node != 0){
				if (i == (loc - 1)){
					prev_node->nextnode = t_node->nextnode;
					if (i == (countv - 1)){
						l_node = prev_node;
					}
					printf("\nElement Deleted Successfully \n\n");
					break;
				}
				else {
					i++;
					prev_node = t_node;
					t_node = t_node->nextnode;
				}
			}
		}
	}
	else
		printf("\nInvalid Position Given\n\n");
}

void main(){
	int value, inopt, option, exitst = 1;
	while (exitst){
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Count\n5. Exit");
		printf("\nEnter your option: ");
		scanf("%d", &option);
		switch (option){
			case 1:
				printf("\n1. Insert At End\n2. Insert at Beg\n3. Insert at Loc");
				printf("\nChoose Your Option: ");
				scanf("%d",&inopt);
				switch (inopt){
					case 1:
						insertend();
						break;
					case 2:
						insertbeg();
						break;
					case 3:
						inser_at_pos();
						break;
				}
				break;
			case 2:
				printf("\n1. Delete At End\n2. Delete at Beg\n3. Delete at Loc");
				printf("\nChoose Your Option: ");
				scanf("%d",&inopt);
				switch (inopt){
					case 1:
						deleteend();
						break;
					case 2:
						deletebeg();
						break;
					case 3:
						delete_at_pos();
						break;
				}
				break;
			case 3:
				display();
				break;
			case 4:
				count();
				break;
			case 5:
				printf("Exiting..");
				exitst = 0;
				break;
			default:
				printf("\nPlease enter correct option. Retry");
		}
	}
}