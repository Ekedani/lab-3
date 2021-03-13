#include "Queue.h"

void Queue::pushBack(int num, int priority) {
    int *new_data = new int[size + 1];
    int *new_priorities = new int[size + 1];
    int position;
    if(size == 0){
        position = 0;
    }
    else{
        position = 0;
        while (position < size){
            if (priorities[position] < priority){
                break;
            }
            position += 1;
        }
    }
    for (int i = 0; i < position; i++){
        new_data[i] = data[i];
        new_priorities[i] = priorities[i];
    }

    //Вставка элемента в массив
    new_data[position] = num;
    new_priorities[position] = priority;

    for (int i = position + 1; i <= size; i++){
        new_data[i] = data[i - 1];
        new_priorities[i] = priorities[i - 1];
    }
    if(size > 0){
        delete[] data;
        delete[] priorities;
    }
    data = new_data;
    priorities = new_priorities;
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