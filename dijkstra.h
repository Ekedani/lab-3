#include <vector>
#include <limits.h>
#include "Queue.h"
using namespace std;

class Cell {
public:
    int row;
    int column;
    int distance;
    Cell *parent;
    Cell(){};
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
};

bool operator==(const Cell &c2, const Cell &c1){
    bool result = false;
    if(c1.row == c2.row && c1.column == c2.column){
        result = true;
    }
    return result;
}

bool operator!=(const Cell &c2, const Cell &c1){
    return !(c1 == c2);
}

void findWay(Cell start, Cell end, char **matrix, vector<vector<int>> visited);
bool tryToAdd(int i, int j, char** matrix, vector<vector<int>> visited);