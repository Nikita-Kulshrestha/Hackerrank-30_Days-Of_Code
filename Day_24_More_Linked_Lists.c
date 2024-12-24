/* A Node class is provided for you in the editor. A Node object has an integer data field, data,and a 
Node instance pointer,next, pointing to another node (i.e.: the next node in a list).A removeDuplicates 
function is declared, which takes a pointer to the  node of a linked list as a parameter. Complete 
removeDuplicates so that it deletes any duplicate nodes from the list and returns head of the updated list.*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* removeDuplicates(Node *head)
{
    if (head == NULL) 
    {
        return NULL;
    }

    Node* current = head; // Start with the head node
    while (current != NULL && current->next != NULL) 
    {
        if (current->data == current->next->data) 
        {
            Node* temp = current->next;
            current->next = temp->next; 
            free(temp); 
        } else
        {
            current = current->next;
        }
    }

    return head; // Return the updated list
}


Node* insert(Node *head,int data)
{
  Node *p = (Node*)malloc(sizeof(Node));
  p->data = data;
  p->next=NULL;   
  
  if(head==NULL){
   head=p;  
  
  }
  else if(head->next==NULL)
  {
      head->next=p;
      
  }
  else{
  Node *start=head;
  while(start->next!=NULL)
    start=start->next;
  
  start->next=p;   
  
  }
      return head;
}
void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
    head=removeDuplicates(head);
	display(head);
		
}
