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
    vector<Cell> cells_in_memory;
    int num_of_visited_cells = 0;

    //Поиск пути пока не придем в конечную точку
    while(end != current_cell){
        cout << "Current cell is: " << current_cell.row << " and " << current_cell.column << endl;
        cout << "Distance is: " << current_cell.distance << endl;

        //Сохранение в памяти для поиска обратного пути рекурсией
        cells_in_memory.push_back(current_cell);

        //Добавление в очередь соседних вершин
        if(tryToAdd(current_cell.row - 1, current_cell.column, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row - 1, current_cell.column, current_cell.distance + 1, current_cell.way + "UP "), current_cell.distance + 1);
        }
        if(tryToAdd(current_cell.row + 1, current_cell.column, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row + 1, current_cell.column, current_cell.distance + 1, current_cell.way + "DOWN "), current_cell.distance + 1);
        }
        if(tryToAdd(current_cell.row, current_cell.column + 1, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row, current_cell.column + 1, current_cell.distance + 1, current_cell.way + "RIGHT "), current_cell.distance + 1);
        }
        if(tryToAdd(current_cell.row, current_cell.column - 1, matrix, visited)){
            list_of_cells.pushBack(Cell(current_cell.row, current_cell.column - 1, current_cell.distance + 1, current_cell.way + "LEFT "), current_cell.distance + 1);
        }

        //Отмечаем клетку как посещеннную
        visited[current_cell.row][current_cell.column] = 1;
        num_of_visited_cells += 1;

        //Обновление текущей вершины
        current_cell = list_of_cells.getFront();
        list_of_cells.popFront();
    }
    cout << current_cell.way << endl;
    string way = current_cell.way; //Не хочу портить ориг
    string temp = "";
    int r = start.row, c = start.column;//Бегаем по матрице
    matrix[r][c] = 'A';
    int index = 0; //Храним позицию пробела
    int i = 66; //Используем ASCII-коды
    while(index!=string::npos) {
        if (i == 91) i=97; //там в таблице аски будет разрыв
        index = way.find(' ');
        temp = way.substr(0, index);
        if (temp=="UP") {
            r-=1;
        }
        if (temp=="RIGHT") {
            c+=1;
        }
        if (temp=="DOWN") {
            r+=1;
        }
        if (temp=="LEFT") {
            c-=1;
        }
        matrix[r][c]=char(i);
        i++;
        way = way.substr(index + 1); //ну можно было erase, но вот так
    }
}

//Проверяет посещалась ли вершина ранее и проходима ли она
bool tryToAdd(int i, int j, char** matrix, vector<vector<int>> visited){
    bool result = false;
    if(matrix[i][j] != 'X' && visited[i][j] != 1){
        result = true;
    }
    return result;
}

//A*
int manhattanMetric(Cell c1, Cell c2){

    //В оценке эвристики оцениваем учитываем так же финальную клетку
    int result = (abs(c1.row - c2.row) + abs(c1.distance - c2.distance) + 1) * 10;
    return result;
}