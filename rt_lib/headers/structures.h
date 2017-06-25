#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <stdio.h>

struct task{
int i;
double D;
double T;
int itN;
void (*code)();
}task;

void printTask(struct task tau);
#endif  //STRUCTURES_H_INCLUDED
