#include <vector>
#include <limits.h>
#include "Queue.h"
#include <iostream>
using namespace std;

class Cell {
public:
    //Публичные атрибуты класса
    int row;
    int column;
    int distance;
    Cell *parent;

    //Конструктор по умолчанию
    Cell(){};

    //Конструктор копирования
    Cell(const Cell &cell){
        row = cell.row;
        column = cell.column;
        distance = cell.distance;
        parent = cell.parent;
    }

    //Остальные конструкторы
    Cell(int row_value, int column_value, int distance_value){
        row = row_value;
        column = column_value;
        distance = distance_value;
    }
    Cell(int row_value, int column_value, int distance_value, Cell *parent_cell){
        row = row_value;
        column = column_value;
        distance = distance_value;
        parent = parent_cell;
    }

    //Перегруженные операторы
    friend bool operator== (const Cell &c2, const Cell &c1);
    friend bool operator!= (const Cell &c2, const Cell &c1);
};

void findWay(Cell start, Cell end, char **matrix, vector<vector<int>> visited);
bool tryToAdd(int i, int j, char** matrix, vector<vector<int>> visited);