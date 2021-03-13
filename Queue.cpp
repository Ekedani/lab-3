#include "Queue.h"

//TODO: Учесть удаление массива

void Queue::pushBack(int num){
    int *new_data = new int[size+1];
    for(int i = 0; i < size; i++){
        new_data[i] = data[i];
    }
    new_data[size] = num;
    data = new_data;
    size += 1;
}

void Queue::popFront(){
    int *new_data = new int[size-1];
    for(int i = 1; i <= size; i++){
        new_data[i-1] = data[i];
    }
    data = new_data;
    size -= 1;
}