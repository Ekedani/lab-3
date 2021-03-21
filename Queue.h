#pragma once

template <class T>
class Queue{
private:
    T *data;
    int *priorities;
    int size;
    int capacity;
public:
    Queue(){
        size = 0;
        capacity = 0;
        data = new T[size];
        priorities = new int[size];
    }

    //Возвращает значение из вершины очереди
    T getFront(){
        return data[0];
    }

    //Возвращает размер очереди
    int getSize(){
        return size;
    }

    //Проверяет очередь на пустоту
    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    //Удаляет первый элемент очереди
    void popFront(){
        for(int i = 1; i <= size; i++){
            data[i-1] = data[i];
            priorities[i - 1] = priorities[i];
        }
        size -= 1;
    }

    //Добавляет элемент в конец очереди
    void pushBack(T obj, int priority) {

        //Если размер больше или равен 80%
        if(size + 1 >= 0.8 * capacity){
            T *new_data;
            int *new_priorities;
            if(capacity == 0){
                new_data = new T[size +1 ];
                new_priorities = new int[size + 1];
                capacity = 1;
            }
            else{
                new_data = new T[capacity * 2];
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
            new_data[position] = obj;
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
            data[position] = obj;
            priorities[position] = priority;
            size += 1;
        }
    }
};

