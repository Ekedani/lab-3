#pragma once

class Queue{
private:
    int *data;
    int size;
public:
    Queue(){
        size = 0;
        data = new int[size];
    }
    void pushBack(int num);
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

