#include "Queue.h"

void Queue::pushBack(int num){
    int *new_data = new int[size+1];
    for(int i = 0; i < size; i++){
        new_data[i] = data[i];
    }
    new_data[size] = num;
    delete[] data;
    data = new_data;
    size += 1;
}

void Queue::popFront(){
    int *new_data = new int[size-1];
    for(int i = 1; i <= size; i++){
        new_data[i-1] = data[i];
    }
    delete[] data;
    data = new_data;
    size -= 1;
}