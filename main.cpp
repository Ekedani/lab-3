#include "library.h"
#include "dijkstra.h"
#include <vector>
using namespace std;

int main() {

    //Ввод пути к файлу лабиринта
    //E:\my-repos\lab-3\labyrinth.txt
    string my_way;
    cout << "Input a way to the file" << endl; cin >> my_way;

    //Форматирование матрицы для работы с ней
    char **matrix = getMatrix(my_way);

    //Ввод координат начала и конца пути
    Cell start(5, 1, 0);
    Cell end(1, 6, INT_MAX);

    //Матрица для записи посещенных вершин. [i][j]=1 значит посещена
    vector<vector<int>> visited_cells;
    for (int i = 0; i < countNumberOfLines(my_way); ++i) {
        vector<int> row;
        for (int j = 0; j < countNumberOfColumns(my_way); ++j) {
            row.push_back(0);
        }
        visited_cells.push_back(row);
    }

    //Функция поиска пути, которая изменяет начальную матрицу
    findWay(start, end, matrix, visited_cells);

    //Вывод обработанной матрицы
    for (int i = 0; i < countNumberOfLines(my_way); ++i) {
        for (int j = 0; j < countNumberOfColumns(my_way); ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
