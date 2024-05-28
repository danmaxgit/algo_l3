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


typedef struct
{
    Task *data;
    size_t capacity;
    size_t size;
} vec;


typedef struct Queue 
{
    vec* buff;
} Queue;

vec* init_vec();
void append_vec(vec* a, Task v);
void free_vec(vec* a);
void erase_vec(vec* a);
bool equals_vec(vec* a, vec* b);
int cmp(const void *a, const void *b);
Task pop_vec(vec* a);
void append_q(Queue* q, Task v);
Task pop(Queue* q);

#endif  // COMMON_H_