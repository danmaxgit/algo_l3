#include "stdio.h"
#include "../include/common.h"

// ./output/main < ./output/task.txt 
//gf2
int main(){
    Array* gen = init_arr(100);
    int size = 0;
    Task temp = {T1, 3};
    append_arr(gen, encode(temp.type, temp.duration));
    temp.type = T2;
    temp.duration = 3;
    append_arr(gen, encode(temp.type, temp.duration));
    temp.type = T3;
    temp.duration = 3;
    append_arr(gen, encode(temp.type, temp.duration));
    temp.type = T1;
    temp.duration = 4;
    append_arr(gen, encode(temp.type, temp.duration));
    temp.type = T1;
    temp.duration = 1;
    append_arr(gen, encode(temp.type, temp.duration));
    // scanf("%d", &size);
    // for(int i = 0; i < size; i++){
        // scanf("%d %d", &temp.type, &temp.duration);
        // append_arr(gen, encode(temp.type, temp.duration));
    // }
    
    Array* stack = init_arr(100);
    CPU* cpus = (CPU*)malloc(sizeof(CPU) * 3);
    cpus[0].type = T1;
    cpus[1].type = T2;
    cpus[2].type = T3;
    Task t;
    while (gen->index > 0 || stack->index > 0) {
        if (gen->index > 0) {
            t = decode(pop_front(gen));
            switch (t.type) {
                case T1:
                    if (cpus[0].task.duration <= 0) {
                        cpus[0].task = t;
                    }
                    else {
                        append_arr(stack, encode(t.type, t.duration));
                    }
                    break;
                case T2:
                    if (cpus[1].task.duration <= 0) {
                        cpus[1].task = t;
                    }
                    else {
                        append_arr(stack, encode(t.type, t.duration));
                    }
                    break;
                case T3:
                    if (cpus[2].task.duration <= 0) {
                        cpus[2].task = t;
                    }
                    else {
                        append_arr(stack, encode(t.type, t.duration));
                    }
                    break;
            }
        }
        for(int i = 0; i < 3; i++){
            if (cpus[i].task.duration > 0) {
                cpus[i].task.duration--;
            }
        }
        if (stack->index > 0) {
            for (int i = 0; i < 3; i++) {
                if(cpus[i].type == decode(stack->data[stack->index]).type && cpus[i].task.duration <= 0){
                    cpus[i].task = decode(pop(stack));
                }
            }
        }
        printf("cpus:{%d %d %d} %d %d\n", cpus[0].task.duration,\
        cpus[1].task.duration,\
        cpus[2].task.duration,\
        gen->index,\
        stack->index);
    }
    
    
    free_arr(stack);
    free_arr(gen);
    
    free(cpus);
    return 0;
}