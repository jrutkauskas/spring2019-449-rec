#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int data;
} Node;

Node* head = NULL;
Node* tail = NULL;

void enqueue(int data)
{
	Node* n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;

	if(head == NULL && tail == NULL)
	{
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
}

int dequeue()
{
	if(head != NULL)
	{
		Node* temp_head = head;
		int temp_data = head->data;
	
		head = head->next;
	
		free(temp_head);

		if(head == NULL)
		{
			tail = NULL;
		}

		return temp_data;
	}
	return 0;
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	int x = dequeue();
	int y = dequeue();
	int z = dequeue();
	printf("%d, %d, %d, \n",x,y,z);

	return 0;

}




