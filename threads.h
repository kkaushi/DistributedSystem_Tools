/* threads.h 
* Author:	Soumya R Bhuyan & Kuldeep Kaushik
*/

#include<stdio.h>
#include <stdlib.h>
#include "q.h"

struct TCB_t *ReadyQ;
int const stackSize = 8192;

void start_thread(void (*function)(void))
{
	void *stackPtr = (void *) malloc(stackSize);
	struct TCB_t *tcbPtr;
	
	tcbPtr = init_TCB(function, stackPtr, stackSize);

	AddQueue(&ReadyQ, tcbPtr);
}

void run()

{   // real code

    ucontext_t parent;     // get a place to store the main context, for faking

    getcontext(&parent);   // magic sauce

    swapcontext(&parent, &(ReadyQ->context));  // start the first thread
}
 

void yield()
{	
	struct TCB_t *currContext;
	currContext = ReadyQ;

	RotateQ(&ReadyQ);

	swapcontext(&(currContext->context), &(ReadyQ->context));
}

