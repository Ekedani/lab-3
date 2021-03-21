#include "dijkstra.h"

//Перегрузка операторов класса Cell
bool operator== (const Cell &c2, const Cell &c1){
    bool result = false;
    if(c1.row == c2.row && c1.column == c2.column){
        result = true;
    }
    return result;
}

bool operator!= (const Cell &c2, const Cell &c1){
    return !(c1 == c2);
}

//Поиск пути по алгоритму Дейкстры
void findWay(Cell start, Cell end, char **matrix, vector<vector<int>> visited){
    Queue<Cell> list_of_cells;
    Cell current_cell = start;

    //Поиск пути пока не придем в конечную точку
    while(end != current_cell){

        //Добавление в очередь соседних вершин
        if(tryToAdd(current_cell.row - 1, current_cell.column, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row - 1, current_cell.column, current_cell.distance + 1, &current_cell), current_cell.distance + 1);
        }
        if(tryToAdd(current_cell.row + 1, current_cell.column, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row + 1, current_cell.column, current_cell.distance + 1, &current_cell), current_cell.distance + 1);
        }
        if(tryToAdd(current_cell.row, current_cell.column + 1, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row, current_cell.column + 1, current_cell.distance + 1, &current_cell), current_cell.distance + 1);
        }
        if(tryToAdd(current_cell.row, current_cell.column - 1, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row, current_cell.column - 1, current_cell.distance + 1, &current_cell), current_cell.distance + 1);
        }

        //Отмечаем клетку как посещеннную
        visited[current_cell.row][current_cell.column] = 1;

        //Обновление текущей вершины
        current_cell = list_of_cells.getFront();
        list_of_cells.popFront();
    }
    do{
        matrix[current_cell.row][current_cell.column] = '3';
        if(current_cell != start){
            current_cell = *(current_cell.parent);
        }
    }
    while(current_cell != start);
}

//Проверяет посещалась ли вершина ранее и проходима ли она
bool tryToAdd(int i, int j, char** matrix, vector<vector<int>> visited){
    bool result = false;
    if(matrix[i][j] != 'X' && visited[i][j] != 1){
        result = true;
    }
    return result;
}