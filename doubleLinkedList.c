#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node *prev, *next;
};
struct node* start = NULL;


void traverse()
{
	// List is empty
	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	// Else print the Data
	struct node* temp;
	temp = start;
	while (temp != NULL) {
		printf(" %d,", temp->info);
		temp = temp->next;
	}
}
/*This funstion reverses change the current and next
void reverse()
{
    struct node *current, *temp1, *temp2,*last,*ins;

    current = start;
    last = start;
     while(last->next != NULL){
        last = last->next;
     }
    while(current != NULL)
    {
        temp2 = current;
        temp1 = current->next;
        current->next = current->prev;
        current->prev = temp1;
        current = temp1;
    }

    ins = start;
    start = temp2;
    last = ins;

    printf("LIST REVERSED SUCCESSFULLY.\n");
}
*/

void reverse() {
    struct node *ptr;
    struct node *last = start;
    struct node *current;
    int i = 1;
    int j = 1;

    while(last != NULL){
        current = last;
        last = last -> next;
        i++;
    }
    printf("\nLOGIC: %d\n",i);
    ptr = current;
    printf("Reverse traversal:\n");
   while(ptr != NULL) {
      printf(" %d,",ptr->info);
      ptr = ptr->prev;
      j++;

   }
   printf("\nLOGIC: %d\n",j);
   printf("\n");
}

//PROBLEM solved IN INSERT AT FIRST
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;

	temp->next = start;
	if(start != NULL){
        start -> prev = temp;
	}
	start = temp;
}


void insertAtEnd()
{
	int data;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;

	if (start == NULL) {

		start = temp;
	}


	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

//PROBLEM solved IN INSERT AT POSITION
void insertAtPosition()
{
	int data, pos, i = 1;
	struct node *temp, *newnode,*prevnext;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;


	printf("\nEnter position : ");
	scanf("%d", &pos);

	if (start == NULL) {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}


	else if (pos == 1) {
	insertAtFront();
	}


	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	temp = start;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		prevnext = temp -> next;
		prevnext -> prev = newnode;
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
	}
}


void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}


void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}


void deletePosition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;

	// If DLL is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Otherwise
	else {
		// Position to be deleted
		printf("\nEnter position : ");
		scanf("%d", &pos);

		// If the position is the first node
		if (pos == 1) {
			deleteFirst(); // im,proved by Jay Ghughriwala on GeeksforGeeks
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}

		// Traverse till position
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		// Change Links
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

		// Free memory
		free(position);
	}
}

void search()
{
    int a;
    printf("Enter the element to search:");
    scanf("%d",&a);
    struct node *kgf;
    kgf = start;
    while(kgf != NULL){
        if(kgf -> info == a){
            printf("\nThe element is found in the linked list\n\n");
            return;
        }
        kgf = kgf -> next;
    }
    printf("\nThe element is not found in the linked list\n\n");
    return;

}

int main()
{
	int choice;
	while (1) {
        printf("\n------DOUBLY LINKED LIST------\n");
		printf("1. Display\n");
		printf("2. Insertion at starting\n");
		printf("3. Insertion at end\n");
		printf("4. Insertion at any position\n");
		printf("5. Deletion of first element\n");
		printf("6. Deletion of last element\n");
		printf("7. Deletion element at any position\n");
		printf("8. Reverse traversal\n");
		printf("9. Search a element\n");
		printf("10. Exit\n");
		printf("\nEnter Choice :");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
        case 8:
            reverse();
            break;
        case 9:
            search();
            break;
		case 10:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			break;
		}
	}
	return 0;
}
