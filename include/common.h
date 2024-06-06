#ifndef COMMON_H_
#define COMMON_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum Types {
    T1,
    T2,
    T3
} Types;

typedef struct Task {
    Types type;
    int duration;
} Task;

typedef struct CPU {
    Types type;
    Task task;
} CPU;


typedef struct Array {
    int *data;
    int len;
    int index;
} Array;


Array* init_arr(int size);
void append_arr(Array* a, int v);
void erase_vec(Array* a);
bool equals_vec(Array* a, Array* b);
int cmp(const void *a, const void *b);
int pop(Array* a);
int pop_front(Array* a);
int encode(Types t, int duration);
Task decode(int v);
void free_arr(Array* a);
#endif  // COMMON_H_