#include <vector>
using namespace std;

class Cell {
public:
    int row;
    int column;
    int distance;
    Cell *parent;
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

class Graph {
public:
    int V; //количество вершин
    vector<pair<Cell, Cell>> edges;
};
