#include "../headers/structures.h"

void printTask(struct task tau)
{
  printf("[Task: i %d, D: %lf, T: %lf] \n", tau.i, tau.D, tau.T);
}
