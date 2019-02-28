#include <stdio.h>
#include <stdlib.h>

// Code for a basic, linked implementation of a Queue data structure in C.
// Only implements make and delete, and enqueue and dequeue, uses a struct for the head and tail data, so we can make multiple queues.

// Ideally, you'd pull this queue code out into a separate C and H file, so you could use it in your later projects with a simple #include "MyQueue.h" and then giving the c file to the compiler.

// Node definition, only stores an integer.  We can get O(1) enqueues and dequeues using only a next reference
typedef struct Node
{
	struct Node* next;
	void* data;
} Node;

// Struct that holds everything we need for a queue
typedef struct Queue
{
	struct Node* head;
	struct Node* tail;
	unsigned int size;
} Queue;

// Makes a new queue for you
//  You MUST use this function to make a queue.  Don't try to do it on your own or the queue might not work. (If you didn't initialize correctly, for example)
Queue* new_queue()
{
	Queue* q = malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	
	return q;
}




// Enqueues the data passed in.  
// Adds a new node to the tail of the queue.
void enqueue(Queue* queue, void* data)
{
	if(data != NULL) 	// Nulls are not allowed to be stored in the queue, we use them as a sort-of sentinel value to tell whether you were able to dequeue something
	{
		queue->size++;
		
		Node* n = malloc(sizeof(Node));  // Make a new node
		n->data = data; 	// Set its data to the data the user passed in.
		n->next = NULL;	// Initialize next to NULL so we don't have a pointer with garbage in it.

		if(queue->head == NULL && queue->tail == NULL)  // If the queue is empty, then the head and tail will be NULL, so we should make them both point at the only node in the chain
		{
			queue->head = n;
			queue->tail = n;
		}
		else	// Just append this at the end of the chain to enqueue, then move the tail pointer forward.
		{
			queue->tail->next = n;
			queue->tail = n;
		}
	}	
}


// Removes an item from the queue and returns it.  
// Just takes the head node and the data from it, then moves the head pointer forward and frees the old node.
void* dequeue(Queue* queue)
{
	if(queue->head != NULL)	// If the head is not NULL, then there's something in the queue we can actually return.
	{
		queue->size--;
		
		Node* temp_head = queue->head;	// Need to keep a reference to the old head because once we move the pointer forward, we would lose access to it and be unable to free it
		void* temp_data = queue->head->data;	// Also need to store the data we're dequeueing
	
		queue->head = queue->head->next;	// Move the head pointer forward.
	
		free(temp_head);	// Must free the old node AFTER we've used the data in it and moved the head forward (using the next reference inside the node)

		if(queue->head == NULL)	// If we removed the last node.
		{
			queue->tail = NULL;	// Set the tail to NULL so we know we need to reinitialize the queue.
		}

		return temp_data;	// Return the user's data.
	}
	return NULL;	// If the queue is empty, we just return NULL.

}

void delete_queue(Queue* queue)
{
	while(dequeue(queue) != NULL){};	// This will dequeue until it runs out of entries in the queue, emptying it.  
										// When the queue is empty, dequeue(...) returns NULL, so the loop will break
										
	free(queue);	// Now we can free the actual queue struct
}

// Test the queue.  Add 3 integers, remove them, and print them.  Make sure they follow FIFO.  Tests delete as well.
int main()
{
	Queue* q = new_queue();	// Makes a new queue.
	
	int arr[] = {10, 20, 30};	// Need to have pointers to the data we want to enqueue, so we'll just put them in this array to make it simpler.
	
	enqueue(q, &arr[0]);
	enqueue(q, &arr[1]);
	enqueue(q, &arr[2]);

	int* x = dequeue(q);
	int* y = dequeue(q);
	int* z = dequeue(q);
	
	printf("%d, %d, %d, \n",*x,*y,*z);  //Should print '10, 20, 30, '

	// Now test the full deletion of the queue.
	
	// Add some more stuff
	enqueue(q, &arr[0]);
	enqueue(q, &arr[1]);
	enqueue(q, &arr[2]);
	
	delete_queue(q);	// Just delete the queue, everything left on it should also be deleted.  Check with valgrind :-)
		
	return 0;

}




