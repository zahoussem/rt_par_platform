#ifndef SCHED_FUNCTIONS_H_INCLUDED
#define SCHED_FUNCTIONS_H_INCLUDED

#include <time.h>
#include "structures.h"

struct timespec now();
int goIdle(struct timespec* Next);
int start(struct task tau);
void createTask(int i, double D, double T, int itN, struct task *tau);
#endif
