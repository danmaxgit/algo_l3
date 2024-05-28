#include "../include/common.h"
#include <stdio.h>
#include <string.h>

vec* init_vec() {
    vec *v = (vec *) malloc(sizeof(vec));
    // v->data->duration = 0;
    // v->data->type = T1;
    v->size = 0;
    v->capacity = 0;
    return v;
}

void append_vec(vec* a, Task v) {
    if (a->size >= a->capacity) {
        a->capacity ? a->capacity *= 2 : a->capacity++;
        a->data = realloc(a->data, a->capacity * sizeof(Task));
    }
    a->data[a->size] = v;
    a->size++;
}

void free_veci(vec* a) {
    free(a->data);
    free(a);
}


void erase_veci(vec* a) {
    a->size = 0;
}

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

bool equals_vec(vec* a, vec* b) {//!!TODO fix if needed 
    if (a->size != b->size)
        return false;
    int *tempa, *tempb;
    tempa = (int *) malloc(sizeof(int) * a->size);
    tempb = (int *) malloc(sizeof(int) * b->size);
    if (tempa && tempb) {
        memcpy(tempa, a->data, sizeof(int) * a->size);
        memcpy(tempb, b->data, sizeof(int) * b->size);
    }

    if (tempa && tempb) {
        qsort((void *)tempa, a->size, sizeof(int), cmp);
        qsort((void *)tempb, b->size, sizeof(int), cmp);
        for (size_t i = 0; i < a->size; i++) {
            if (tempa[i] != tempb[i]) {
                free(tempa);
                free(tempb);
                return false;
            }
        }
    }
    free(tempa);
    free(tempb);
    return true;
}

Task pop_vec(vec* a){
    if (a->size > 0) {
        a->size--;
        return a->data[a->size + 1];
    }
}

void append_q(Queue* q, Task v) {
    append_vec(q->buff, v);
}
Task pop(Queue* q){
    Task temp = {0,0};
    if (q->buff->size > 0) {
        temp = q->buff->data[0];
        for(size_t i = 0; i < q->buff->size - 1; i++){
            q->buff->data[i] = q->buff->data[i + 1];
        }
        q->buff->size--;
        return temp;    
    }
    Task t = {-1, -1};
    return t;
}