#include <stdio.h>
#include <stdlib.h>
#include "headers/time_operations.h"
#include "headers/sched_functions.h"
#include "headers/structures.h"
void codei(){
  printf("Hello, I am the task code \n");
}
int main()
{
  struct task tau;
  createTask(1,2,3,1,&tau);
  tau.code=&codei;  
  start(tau);
  return 0;
}
