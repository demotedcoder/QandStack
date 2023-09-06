#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>


/*

		----------------------------------------------
		Queue and Stack implemented using Linked Lists
						demotedc0der
		----------------------------------------------

*/


typedef struct Node {
	int value;
	Node* next;
}Node;

Node* temp, * front = NULL, * rear = NULL;

Node* getNode() {
	Node* new_node = (Node*)malloc(sizeof(Node));
	return new_node;
}

Node* push(Node* first, int d) {
	temp = getNode();
	temp->value = d;
	temp->next = first;
	return temp;
}

Node* pop(Node* first) {
	if (first == NULL) {
		printf("[!] Stack is empty\n");
		return first;
	}
	temp = first;
	first = first->next;
	printf("Element popped from stack %d\n", temp->value);
	free(temp);
	return first;
}

void displayStack(Node* first) {
	if (first == NULL) {
		printf("[!] Stack is empty\n");
		return;
	}
	temp = first;
	printf("======Stack=======\n");
	while (temp != NULL) {
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	printf("==================\n");
}

void pushQ(int d) {
	if (rear == NULL) {
		rear = getNode();
		rear->next = NULL;
		rear->value = d;
		front = rear;
	}
	else {
		temp = getNode();
		rear->next = temp;
		temp->value = d;
		temp->next = NULL;
		rear = temp;
	}
}

void deQ() {
	temp = front;
	if (front == NULL) {
		printf("[!] Queue is empty\n");
		return;
	}
	else {
		if (temp->next != NULL) {
			temp = temp->next;
			free(front);
			front = temp;
		}
		else {
			free(front);
			front = NULL;
			rear = NULL;
		}
	}
}

void displayQueue() {
	printf("\n");
	temp = front;
	if ((front == NULL) && (rear == NULL)) {
		printf("[!] Queue is empty\n");
		return;
	}
	printf("======Queue=======\n");
	while (temp != NULL) {
		printf("%d \n", temp->value);
		temp = temp->next;
	}
	printf("==================\n");
}

int main() {
	Node* first = NULL;
	int choice;
	int e;
	while (1) {
		printf("[Stack]\n1 push \n2 pop \n3 display \n\n4 exit\n \n[Queue]\n5 enqueue \n6 dequeue \n7 display\n\n\tOption: ");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("[Stack]Enter element to push -> ");
			scanf_s("%d", &e);
			first = push(first, e);
			break;
		case 2:
			first = pop(first);
			break;
		case 3:
			displayStack(first);
			break;
		case 4:
			exit(3);
		case 5:
			printf("[Queue]Enter element to enqueue -> ");
			scanf_s("%d", &e);
			pushQ(e);
			break;
		case 6:
			deQ();
			break;
		case 7:
			displayQueue();
			break;
		default:
			break;
		}
	}
	system("pause");
}