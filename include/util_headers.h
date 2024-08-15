

#ifndef UTIL_HEADERS_H
#define UTIL_HEADERS_H

int int_pow(int n, int p);
int polynomial_hash(char *str);
int cycle_shift(char *str);
void print_int_arr(int *arr, int len);
int random_range(int min, int max);
int true_random_range(int min, int max);

#define ABS(x) (x * ((x >= 0) - (x < 0)))

#endif