#pragma once

class Queue{
private:
    int *data;
    int *priorities;
    int size;
    int capacity;
public:
    Queue(){
        size = 0;
        capacity = 0;
        data = new int[size];
        priorities = new int[size];
    }
    void pushBack(int num, int priority);
    void popFront();
    int getFront(){
        return data[0];
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

