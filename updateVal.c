#include<stdio.h>
#include<stdlib.h>

//declaring a structure
typedef struct Node{
	struct Node* next;
	int data;
}Node;

//createNewNode function
Node* createNewNode(int data){
	//using malloc() function to allocate memory to newly created node.
	Node* newNode = (Node*)malloc(sizeof(Node));

	//initializing the newly created node.
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}


//function to insert at Last.
Node* insertAtLast(Node* head,int val){
	//creating a newNode
	Node* last = (Node*)malloc(sizeof(Node));	//Allocating memory to it dynamically.
	
	//Initializing the lastNode
	last->data = val;
	last->next = NULL;

	//using a temporary node to store head,traverse and prevent losing the actual head node.
	Node* temp = head;

	while( temp->next != NULL){
		temp = temp->next;
	}

	temp->next = last;	//adding the lastNode.
	last->next = NULL;	//make the lastNode point to NULL

	return head;
}

//function to update all values of given node
void updateAllNodeValues(Node* head,int updateBy){
	
	//Using temp Node.
	Node* temp = head;
	
	while(temp != NULL){
		printf("%d->",temp->data+updateBy);
		temp = temp->next;
	}
	
	printf("NULL\n");

	//lets try to print the next temp data.Since the temp is terminated , access temp->data will lead to invalid memory access.
	printf("Showing Invalid memory access:Since temp is terminated access the temp data futher causes invalid memory issue %d",temp->data);
	
} 


//function to print the linkedlist node.
void printList(Node* head){
	Node* temp = head;

	while( temp != NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}

	printf("NULL\n");

}

int main(){
	printf("\tPrinting node values using linkedlist.\n");

	Node* head = createNewNode(10);
	head->next = createNewNode(12);
	head->next->next = createNewNode(14);
	head->next->next->next = createNewNode(16);

	printList(head);

	printf("Inserting a node 18 after node %d.\n",head->next->next->next->data);
	head  = insertAtLast(head,18);
	printList(head);

	printf("\tPrinting Linkedlist with updated Values.\n");
	
	printf("Enter value to update linkedList nodes by-");
	int val;
	scanf("%d",&val);
	
	updateAllNodeValues(head,val);
	return 0;
}
