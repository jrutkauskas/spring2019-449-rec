#include <stdio.h>
#include <stdlib.h>

// Code for a basic, linked implementation of a Queue data structure in C.
// Only implements enqueue and dequeue, uses a global head and tail reference, so we can only make one queue.


// Node definition, only stores an integer.  We can get O(1) enqueues and dequeues using only a next reference
typedef struct Node
{
	struct Node* next;
	int data;
} Node;


// Global definitions of head and tail; you could put these in a struct to make be able to manage multiple queues.
// Initialized to NULL since the queue starts out empty.
Node* head = NULL;
Node* tail = NULL;


// Enqueues the data passed in.  
// Adds a new node to the tail of the queue.
void enqueue(int data)
{
	Node* n = malloc(sizeof(Node));  // Make a new node
	n->data = data; 	// Set its data to the data the user passed in.
	n->next = NULL;	// Initialize next to NULL so we don't have a pointer with garbage in it.

	if(head == NULL && tail == NULL)  // If the queue is empty, then the head and tail will be NULL, so we should make them both point at the only node in the chain
	{
		head = n;
		tail = n;
	}
	else	// Just append this at the end of the chain to enqueue, then move the tail pointer forward.
	{
		tail->next = n;
		tail = n;
	}
}


// Removes an item from the queue and returns it.  
// Just takes the head node and the data from it, then moves the head pointer forward and frees the old node.
int dequeue()
{
	if(head != NULL)	// If the head is not NULL, then there's something in the queue we can actually return.
	{
		Node* temp_head = head;	// Need to keep a reference to the old head because once we move the pointer forward, we would lose access to it and be unable to free it
		int temp_data = head->data;	// Also need to store the data we're dequeueing
	
		head = head->next;	// Move the head pointer forward.
	
		free(temp_head);	// Must free the old node AFTER we've used the data in it and moved the head forward (using the next reference inside the node)

		if(head == NULL)	// If we removed the last node.
		{
			tail = NULL;	// Set the tail to NULL so we know we need to reinitialize the queue.
		}

		return temp_data;	// Return the user's data.
	}
	return 0;	// Not optimal!!!!!!!  This method must return something (or crash) so we have to return something if the queue is empty
				// In Java, we would throw an exception, but here we'll just return zero as an example.
}

// Test the queue.  Add 3 integers, remove them, and print them.  Make sure they follow FIFO.
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	int x = dequeue();
	int y = dequeue();
	int z = dequeue();
	printf("%d, %d, %d, \n",x,y,z);  //Should print '10, 20, 30, '

	return 0;

}




