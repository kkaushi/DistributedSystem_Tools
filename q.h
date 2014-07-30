/* q.h 
* Author:	Soumya R Bhuyan & Kuldeep Kaushik 
*/

#include<stdio.h>
#include <stdlib.h>
#include "tcb.h"

/* creates an empty queue, pointed to by the variable head. */
void InitQueue(struct TCB_t **head){
	*head = NULL;
}

/* adds a queue item, pointed to by “item”, to the queue pointed to by head. */
void AddQueue(struct TCB_t **head, struct TCB_t *item){
	if (*head == NULL){
		//printf("Inside AddQueue in q.h\n");
		*head = item;
		item->next = *head;
		item->prev = *head;
		//printf("1st Item added successfully\n");
	}
	
	else{		
		struct TCB_t *temp;
		temp = (*head)->prev;

		item->next = *head;
		item->prev = temp;
		
		temp->next = item;
		(*head)->prev = item;
	}

}

/* deletes an item from head and returns a pointer to the deleted item */
struct TCB_t *DelQueue(struct TCB_t **head){

	struct TCB_t *delItem;
	if(*head == NULL){
		delItem = NULL;
		//printf("Queue is empty. No item to delete.\n");
	} 
		
	else if (*head == (*head)->prev){
		delItem = *head;
		*head = NULL;
		//printf("Only item was the head. Head deleted.\n");
	}
	
	else{
		delItem = *head;
		struct TCB_t *temp1 = delItem->next;
		struct TCB_t *temp2 = delItem->prev;
		temp1 -> prev = temp2;
		temp2->next = temp1;
		*head = temp1;
		//printf(" Item deleted \n ");

	}

return delItem;
}

/* Moves the header pointer to the next element in the queue. */

void RotateQ(struct TCB_t **head){

	if(*head==NULL)
		{
			printf("Queue empty \n");
		}
     
	else if(*head == (*head)->next)
	{
		printf("Head is the only element. \n");
	}
	
	else
	{
		*head = (*head)->next;
		//printf("Rotation Complete. \n");
	}

}
