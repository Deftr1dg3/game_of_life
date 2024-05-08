
#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
// Dor sleep function and usleep
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int **create_field(int rows, int cols);
void init_field(int **field, int rows, int cols);
void next_field_state(int ***field, int rows, int cols);
void free_field(int ***field, int rows);

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

#endif