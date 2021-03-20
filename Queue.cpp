#include "Queue.h"

void Queue::pushBack(int num, int priority) {

    //Если размер больше или равен 80%
    if(size + 1 >= 0.8 * capacity){
        int *new_data;
        int *new_priorities;
        if(capacity == 0){
            new_data = new int[size +1 ];
            new_priorities = new int[size + 1];
            capacity = 1;
        }
        else{
            new_data = new int[capacity * 2];
            new_priorities = new int[capacity * 2];
            capacity *= 2;
        }
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

        //Освобождение памяти
        if(size > 0){
            delete[] data;
            delete[] priorities;
        }
        data = new_data;
        priorities = new_priorities;
        size += 1;
    }

    //Без увеличения массивов
    else{
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

        for (int i = position + 1; i <= size; i++){
            data[i] = data[i - 1];
            priorities[i] = priorities[i - 1];
        }
        data[position] = num;
        priorities[position] = priority;
        size += 1;
    }


    //Выделение памяти
    int *new_data = new int[size * 2];
    int *new_priorities = new int[size * 2];
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

    //Освобождение памяти
    if(size > 0){
        delete[] data;
        delete[] priorities;
    }
    data = new_data;
    priorities = new_priorities;
    size += 1;
}

//TODO: Переделать функцию под приоритетную очередь
void Queue::popFront(){
    int *new_data = new int[size-1];
    for(int i = 1; i <= size; i++){
        new_data[i-1] = data[i];
    }
    delete[] data;
    data = new_data;
    size -= 1;
}