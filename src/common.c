#include "../include/common.h"
#include "stdlib.h"
#include "stdio.h"
#include <strings.h>

Array* init_arr(int size){
    Array* res = (Array*)malloc(sizeof(Array));
    res->len = size;
    res->index = 0;
    res->data = (int*)malloc(sizeof(int)* size);
    return res;
}

void free_arr(Array* a){
    free(a->data);
    free(a);
}
void append_arr(Array* a, int v){
    if (a->index < a->len) {
        a->data[a->index] = v;
        a->index++;
    }
    else {
        fprintf(stderr, "overflow array");
        return;
    }
}
void erase_vec(Array* a){
    a->index = 0;
}
bool equals_vec(Array* a, Array* b){
    if (a->index != b->index) {
        return false;
    }
    else{
        for (int i = 0; i < a->index; i++) {
            if (a->data[i] != b->data[i]) {
                return false;
            }
        }
    }
    return true;
}
int pop(Array* a){
    if (a->index > 0) {
        a->index--;
        return a->data[a->index + 1];
    }
    else {
        fprintf(stderr, "None elements in array");
    }
}
int pop_front(Array* a){
    if (a->index > 0) {
        int res = a->data[0];
        for (int i = 0; i < a->index - 1; i++) {
            a->data[i] = a->data[i + 1];
        }
        a->index--;
        return res;
    }
    else {
        fprintf(stderr, "None elements in array");
    }
}
int encode(Types t, int duration){
    int res = 0;
    res = t % 2 << 0 | t / 2 << 1;
    res |= duration % 2 << 2 | duration / 2 << 3 | \
    duration / 4 << 4 | duration / 8 << 5 | \
    duration / 16 << 6 | duration / 32 << 7;
    return res; 
}
Task decode(int v){
    Task t = {0, 0};
    t.type = (v & (1 << 0)) + (v & (1 << 1));
    t.duration = (v & (1 << 2)) + (v & (1 << 3)) + \
                 (v & (1 << 4)) + (v & (1 << 5)) + \
                 (v & (1 << 6)) + (v & (1 << 7));
    t.duration /= 4;
    return t;
}