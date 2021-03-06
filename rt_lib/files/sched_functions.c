#include "../headers/sched_functions.h"
#include "../headers/structures.h"
#include "../headers/time_operations.h"

inline struct timespec now()
{
  struct timespec begin;
  clock_gettime(CLOCK_REALTIME, &begin);
  return begin;
}


inline int goIdle(struct timespec *Next)
{
  int res=clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, Next, NULL);
  return res;
}







int start(struct task tau)
{
  int i;
  for (i=0;i<tau.itN;i++)
    {
      struct timespec begin = now();
      struct timespec next = add_spec(begin,tospec(tau.T,0));
      (*(tau.code))();
      struct timespec end = now();
      goIdle(&next);
    }
  return 0;
}


void createTask(int i, double D, double T, int itN, struct task *tau)
{


  tau->i = i;

  tau->D = D;

  printf("::: %lf",tau->D);
 
  tau->T = T;
  tau->itN = itN;

}
