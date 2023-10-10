
#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node *start=NULL;
struct Node
{
	int data;
	struct Node *next;
};
void insert_at_begin(int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(start==NULL)
	{
		start=t;
		start->data=x;
		start->next=NULL;
		return;
	}
	t->data=x;
	t->next=start;
	start=t;
}

void insertAtPosition()
{
	int data, pos, i = 1,len=0;
	struct Node *temp, *newnode,*temp2;
	newnode = malloc(sizeof(struct Node));
	newnode->next = NULL;
	temp2 = start;
	printf("\nEnter position : ");
	scanf("%d", &pos);
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);

	while(temp2 != NULL){
        len++;
        temp2 = temp2 -> next;
    }

    if(pos > len){
        printf("Position out of range.\n");
        return;
    }


	// Enter the position and data
	// If start==NULL,
	if (start == NULL) {
		start = newnode;
		newnode -> data = data;
		newnode->next = NULL;
	}

	// If position==1,
	else if (pos == 1) {
	insert_at_begin(data);
	}

	// Change links
	else {
	newnode-> data = data;
	temp = start;
		while (i < pos - 1) {
			temp = temp -> next;
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;

	}
}
void insert_at_end(int x)
{
	struct Node *t,*temp;
	t=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(start==NULL)
	{
		start=t;
		start->data=x;
		start->next=NULL;
		return;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=t;
	t->data=x;
	t->next=NULL;
}
void delete_from_begin()
{
	struct Node *t;
	int n;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	n=start->data;
	t=start->next;
	free(start);
	start=t;
	count--;
	printf("Deleted element is %d\n\n",n);
	return;
}

void deletePosition()
{
	int pos, n, i = 1, len=0;
	struct Node *temp, *position,*temp2;
	temp2 = start;
	printf("\nEnter position : ");
    scanf("%d", &pos);
    while(temp2 != NULL){
        len++;
        temp2 = temp2 -> next;
    }

    temp = start;
    if(pos > len){
        printf("Position out of range.\n");
        return;
    }

	if (start == NULL)
		printf("\nList is empty\n");

	else {
		if (pos == 1) {
			delete_from_begin();
			free(position);
			return;
		}

		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}

		position = temp->next;
		n = position -> data;
		printf("Deleted element is %d\n\n",n);
		temp->next = position->next;


		free(position);
	}
}


void delete_from_end()
{
	struct Node *t,*u;
	int n;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	count--;
	if(start->next==NULL)
	{
		n=start->data;
		free(start);
		start=NULL;
		printf("Deleted element is %d\n\n",n);
		return;
	}
	t=start;
	while(t->next!=NULL)
	{
		u=t;
		t=t->next;
	}
	n=t->data;
	u->next=NULL;
	free(t);
	printf("Deleted element is %d\n\n",n);
	return;
}

void search(int a)
{

    struct Node *kgf;
    kgf = start;
    while(kgf != NULL){
        if(kgf -> data == a){
            printf("\nThe element is found in the linked list\n\n");
            return;
        }
        kgf = kgf -> next;
    }
    printf("\nThe element is not found in the linked list\n\n");
    return;

}
void display()
{
	struct Node *t;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	printf("No of elements: %d\n",count);
	printf("Elements are: ");
	t=start;
	while(t->next!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("%d ",t->data);
	printf("\n\n");
}



int main()
{
	int ch,data,x;
	while(1)
	{
	    printf("\n----SINGLY LINKED LIST----\n");
		printf("1. INSERT AT BEGINING\n");
		printf("2. INSERT AT ANY POSITION\n");
		printf("3. INSERT AT END\n");
		printf("4. DELETE FROM BEGINING\n");
		printf("5. DELETE AT ANY POSITION\n");
		printf("6. DELETE FROM END\n");
		printf("7. DISPLAY LIST\n");
		printf("8. SEARCH A ELEMENT\n");
		printf("9. EXIT\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch (ch){
		case 1:
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_begin(data);
			break;
        case 2:
            insertAtPosition();
            break;
		case 3:
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_end(data);
			break;
		case 4:
			delete_from_begin();
			break;
        case 5:
            deletePosition();
            break;
		case 6:
			delete_from_end();
			break;
		case 7:
			display();
			break;
		case 8:
		    printf("Enter the value to search:");
		    scanf("%d",&x);
			search(x);
			break;
		case 9:
		    exit(1);
			break;
		default:
			printf("Wrong choice!!!\n");
			break;
		}
	}
	return 0;
}
