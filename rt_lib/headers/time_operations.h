#ifndef TIME_OPERATIONS_H_INCLUDED
#define TIME_OPERATIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct timespec diff_spec(struct timespec a, struct timespec b);
struct timespec add_spec(struct timespec a, struct timespec b);
struct timespec diff_unit(struct timespec a, double b);
struct timespec add_unit(struct timespec a, double b);
int less(struct timespec a, struct timespec b);
struct timespec tospec(double a, int Unit);
double toUnit(struct timespec a, int Unit);

#endif // TIME_OPERATIONS_H_INCLUDED
