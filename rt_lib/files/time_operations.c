#include "../headers/time_operations.h"
struct unit_conv {
    long mul;
    long div;
};
const struct unit_conv conv_table[] = {
    {1L, 1000000000L},  // SEC
    {1000L, 1000000L},  // MILLI
    {1000000L, 1000L},  // MICRO
    {1000000000L, 1L}   // NANO
};

struct timespec tospec(double a, int Unit)
{
  struct timespec res;
  res.tv_sec = a/conv_table[Unit].mul;
  res.tv_nsec = a*conv_table[Unit].div  - res.tv_sec*conv_table[Unit].div;
  return res;
}
double toUnit(struct timespec a,int Unit)
{
  return a.tv_sec*conv_table[Unit].mul + a.tv_nsec/(double)(conv_table[Unit].div);
}

struct timespec diff_spec(struct timespec a, struct timespec b){
  struct timespec res;
  res.tv_sec= a.tv_sec - b.tv_sec;
  res.tv_nsec= a.tv_nsec - b.tv_nsec;
  if (res.tv_nsec < 0)
    {
      res.tv_sec = res.tv_sec  - 1;
      res.tv_nsec = 1000000000 + res.tv_nsec;
    }
  return res;
}
struct timespec add_spec(struct timespec a, struct timespec b){
  struct timespec res;
  res.tv_sec= a.tv_sec + b.tv_sec;
  res.tv_nsec= a.tv_nsec + b.tv_nsec;
  if (res.tv_nsec >= 1000000000 )
    {
      res.tv_sec = res.tv_sec + 1;
      res.tv_nsec = res.tv_nsec - 1000000000;
    }
  return res;

}

int less(struct timespec a, struct timespec b){
  if (a.tv_sec > b.tv_sec) return 0;
  else if (a.tv_sec == b.tv_sec)
    if (a.tv_nsec > b.tv_nsec)
      return 0;
    else 
      return 1;
  else return 1;
  return -1;
}

int equal(struct timespec a, struct timespec b){
  if (a.tv_sec == b.tv_sec && a.tv_nsec == b.tv_nsec) return 1;
  return 0;
}


void printspec(struct timespec a)
{
  printf("(tvsec: %d, ", a.tv_sec);
  printf("tvnsec: %llu) \n", a.tv_nsec);
}
