#include "library.h"
#include "Queue.h"
#include "dijkstra.h"
#include <vector>
using namespace std;

int main() {
    string my_way;
    cin >> my_way;
    char **matrix = getMatrix(my_way);

    //Вывод считанной матрицы, для удобства
    for (int i = 0; i < countNumberOfLines(my_way); ++i) {
        for (int j = 0; j < countNumberOfColumns(my_way); ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    Cell start(5, 2, 0);
    Cell end(1, 12, INT_MAX);

    //Матрица для записи посещенных вершин. [i][j]=1 значит посещена
    vector<vector<int>> visited_cells;
    for (int i = 0; i < countNumberOfLines(my_way); ++i) {
        vector<int> row;
        for (int j = 0; j < countNumberOfColumns(my_way); ++j) {
            row.push_back(0);
        }
        visited_cells.push_back(row);
    }

    Graph paths;
}
