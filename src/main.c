#include "stdio.h"
#include "../include/common.h"
#include <stdlib.h>

// ./output/main < ./output/task.txt 

int main(int argc, char** argv){
    Queue* gen = malloc(sizeof(Queue));
    gen->buff = init_vec();
    int size = 0;
    scanf("%d", &size);
    printf("%d\n", size);
    Task temp = {T1, 0};
    for(int i = 0; i < size; i++){
        scanf("%d %d", &temp.type, &temp.duration);
        append_q(gen, temp);
    }

    vec* stack = init_vec();
    CPU* cpus = (CPU*)malloc(sizeof(CPU) * 3);
    cpus[0].type = T1;
    cpus[1].type = T2;
    cpus[2].type = T3;
    Task t;
    while (gen->buff->size > 0 || stack->size > 0) {
        t = pop(gen);
        switch (t.type) {
            case T1:
                if (cpus[0].task.duration <= 0) {
                    cpus[0].task = t;
                }
                else {
                    append_vec(stack, t);
                }
                break;
            case T2:
                if (cpus[1].task.duration <= 0) {
                    cpus[1].task = t;
                }
                else {
                    append_vec(stack, t);
                }
                break;
            case T3:
                if (cpus[2].task.duration <= 0) {
                    cpus[2].task = t;
                }
                else {
                    append_vec(stack, t);
                }
                break;
        }
        for(int i = 0; i < 3; i++){
            cpus[i].task.duration--;
        }
        if (stack->size > 0) {
            for (int i = 0; i < 3; i++) {
                if(cpus[i].type == stack->data[stack->size].type && cpus[i].task.duration <= 0){
                    cpus[i].task = pop_vec(stack);
                }
            }
        }
        printf("cpus:{%d %d %d} %ld %ld\n", cpus[0].task.duration,\
        cpus[1].task.duration,\
        cpus[2].task.duration,\
        gen->buff->size,\
        stack->size);
    }
    
    
    // free_vec(stack);
    //free_vec(gen->buff);
    free(stack->data);
    free(stack);
    free(gen->buff->data);
    free(gen->buff);

    free(gen);
    free(cpus);
    return 0;
}