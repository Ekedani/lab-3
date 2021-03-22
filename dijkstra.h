#include <vector>
#include <climits>
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

class Cell {
public:
    //Публичные атрибуты класса
    int row;
    int column;
    int distance;
    string way;
    //Конструктор по умолчанию
    Cell(){};

    //Конструктор копирования
    Cell(const Cell &cell){
        row = cell.row;
        column = cell.column;
        distance = cell.distance;
        way = cell.way;
    }

    //Остальные конструкторы
    Cell(int row_value, int column_value, int distance_value){
        row = row_value;
        column = column_value;
        distance = distance_value;
        way = "";
    }
    Cell(int row_value, int column_value, int distance_value, string way_to_start){
        row = row_value;
        column = column_value;
        distance = distance_value;
        way = way_to_start;
    }

    //Перегруженные операторы
    friend bool operator== (const Cell &c2, const Cell &c1);
    friend bool operator!= (const Cell &c2, const Cell &c1);
};

void findWay(Cell start, Cell end, char **matrix, vector<vector<int>> visited);
bool tryToAdd(int i, int j, char** matrix, vector<vector<int>> visited);
int manhattanMetric(Cell c1, Cell c2, int movement);
void findWayAStar(Cell start, Cell end, char **matrix, vector<vector<int>> visited);