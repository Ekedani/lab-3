#include <vector>
using namespace std;

class Cell {
public:
    int row;
    int column;
    int distance;
    Cell(int row_value, int column_value, int distance_value){
        row = row_value;
        column = column_value;
        distance = distance_value;
    }
};

class Graph {
public:
    int V; //количество вершин
    vector<pair<Cell, Cell>> edges;
};
