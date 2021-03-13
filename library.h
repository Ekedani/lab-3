#pragma once

#include <iostream>
#include <fstream>

//TODO: Методы isEmpty, getSize, getFront, pushBack, popFront

class Queue{
private:
    int *data;
    int head;
    int tail;
    int size;
public:
    void pushBack(int num);
    void popFront();
    int getFront(){
        return *(data[0]);
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

};

void Queue::pushBack(int num){
    int *new_data = new int[size+1];
    for(int i = 0; i < size; i++){
        new_data[i] = data[i];
    }
    new_data[size] = num;
    data = new_data;
    size += 1;
    delete[] data;
}

void Queue::popFront(){
    int *new_data = new int[size-1];
    for(int i = 1; i <= size; i++){
        new_data[i-1] = data[i];
    }
    data = new_data;
    size -= 1;
    delete[] data;
}