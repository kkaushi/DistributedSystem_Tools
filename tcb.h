/* tcb.h 
* Author:	Soumya R Bhuyan & Kuldeep Kaushik
*/

#include<stdio.h>
#include <stdlib.h>
#include <ucontext.h>

/* TCB_t has previous and next pointers along with a ucontext_t field to store a thread context */
struct TCB_t{
	struct TCB_t *prev;
	struct TCB_t *next;
	ucontext_t context;
};

/* Initialize a TCB for a new thread */
struct TCB_t *init_TCB(void (*function), int *stackPtr, int stackSize){

	struct TCB_t *tempTCB = (struct TCB_t *) malloc (sizeof(struct TCB_t));

	getcontext(&tempTCB->context);
	tempTCB->context.uc_stack.ss_sp = stackPtr;
	tempTCB->context.uc_stack.ss_size = stackSize;
	
	makecontext(&tempTCB->context, function, 0);

return tempTCB;
}


