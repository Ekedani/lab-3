#include "dijkstra.h"

void findWay(Cell start, Cell end, char **matrix, vector<vector<int>> visited){
    Queue<Cell> list_of_cells;
    Cell current_cell = start;
    //TODO: перегрузить операцию сровнения для класса Cell по координатам
    //TODO: обновить приоритетность очереди от меньшего к большему
    while(start != current_cell){

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

        //Обновление текущей вершины
        current_cell = list_of_cells.getFront();
        list_of_cells.popFront();
    }
    //TODO: написать рекурсивную функцию, что принимает в себя Start и через parent ищет путь в начальную вершину
}

//Проверяет посещалась ли вершина ранее и проходима ли она
bool tryToAdd(int i, int j, char** matrix, vector<vector<int>> visited){
    bool result = false;
    if(matrix[i][j] != 'X' && visited[i][j] != 1){
        result = true;
    }
    return result;
}