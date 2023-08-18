#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
    int Size;
};

struct Node* getnode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    deque->Size = 0;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

int size(struct Deque* deque) {
    return deque->Size;
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = getnode(data);
    
    if (newNode == NULL) {
        printf("OverFlow\n");
    } else {
        if (deque->front == NULL) {
            deque->rear = deque->front = newNode;
        } else {
            newNode->next = deque->front;
            deque->front->prev = newNode;
            deque->front = newNode;
        }
        
        deque->Size++;
    }
}

void insertRear(struct Deque* deque, int data)
{
	struct Node* newNode = getnode(data);
	
	if (newNode == NULL)
		printf("OverFlow\n");
	else {
		if (deque->rear == NULL)
			deque->front = deque->rear = newNode;
		else {
			newNode->prev = deque->rear;
			deque->rear->next = newNode;
			deque->rear = newNode;
		}
		deque->Size++;
	}
}

void deleteFront(struct Deque* deque)
{
	if (isEmpty(deque))
		printf("UnderFlow\n");
	else {
		struct Node* temp = deque->front;
		deque->front = deque->front->next;
		
		if (deque->front == NULL)
			deque->rear = NULL;
		else
			deque->front->prev = NULL;
		free(temp);
		
		deque->Size--;
	}
}

void deleteRear(struct Deque* deque)
{
	if (isEmpty(deque))
		printf("UnderFlow\n");
	else {
		struct Node* temp = deque->rear;
		deque->rear = deque->rear->prev;
		
		if (deque->rear == NULL)
			deque->front = NULL;
		else
			deque->rear->next = NULL;
		free(temp);
		
		deque->Size--;
	}
}

int getFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        return -1;
    }

    return dq->front->data;
}

int getRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        return -1;
    }

    return dq->rear->data;
}

void erase(struct Deque* dq) {
    dq->rear = NULL;
    while (dq->front != NULL) {
        struct Node* temp = dq->front;
        dq->front = dq->front->next;
        free(temp);
    }
    dq->Size = 0;
}

int main() {
    struct Deque dq;
    dq.front = NULL;
    dq.rear = NULL;
    dq.Size = 0;

    printf("Insert element '5' at rear end\n");
    insertRear(&dq, 5);
    printf("Insert element '10' at rear end\n");
    insertRear(&dq, 10);
    printf("Rear end element: %d\n", getRear(&dq));
    deleteRear(&dq);
    printf("After deleting rear element new rear is: %d\n", getRear(&dq));
    printf("Inserting element '15' at front end\n");
    insertFront(&dq, 15);
    printf("Front end element: %d\n", getFront(&dq));
    printf("Number of elements in Deque: %d\n", dq.Size);
    deleteFront(&dq);
    printf("After deleting front element new front is: %d\n", getFront(&dq));

    return 0;
}