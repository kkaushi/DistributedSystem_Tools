/* thread_test.c
* Author:	Soumya R Bhuyan & Kuldeep Kaushik
*/

#include<stdio.h>
#include "threads.h"

void function1();
void function2();
void function3();
void function4();

int global=0;

int main()
{
  InitQueue(&ReadyQ);

  start_thread(function1);
  start_thread(function2);
  start_thread(function3);
  start_thread(function4);

  run();

  return 0;
}

void function1()
{
   int local = 0;
   
	while (1){
	        printf("Inside function1 :  global = %d  local = %d\n", global, local);
	        sleep(1);

	        global++; local++;
	        printf("After incrementing both global and local in function1 : global = %d  local = %d\n", global, local);
	        sleep(1);
		
		yield();

        }//End of while
}

void function2()
{
   int local = 0;
   
	while (1){
	        printf("Inside function2 :  global = %d  local = %d\n", global, local);
	        sleep(1);

	        global++; local++;
	        printf("After incrementing both global and local in function2 : global = %d  local = %d\n", global, local);
	        sleep(1);

		yield();

        }//End of while
}

void function3()
{
   int local = 0;
   
	while (1){
	        printf("Inside function3 :  global = %d  local = %d\n", global, local);
	        sleep(1);

	        global++; local++;
	        printf("After incrementing both global and local in function3 : global = %d  local = %d\n", global, local);
	        sleep(1);

		yield();

        }//End of while
}

void function4()
{
   int local = 0;
   
	while (1){
	        printf("Inside function4 :  global = %d  local = %d\n", global, local);
	        sleep(1);

	        global++; local++;
	        printf("After incrementing both global and local in function4 : global = %d  local = %d\n", global, local);
	        sleep(1);

		yield();

        }//End of while
}
