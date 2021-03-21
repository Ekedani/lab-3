#include <vector>
#include <limits.h>
using namespace std;
#include "dijkstra.h"

Graph make_graph(char **matrix, int rows, int columns, vector<vector<int>> &visited){
    int V = 0;
    vector<pair<Cell, Cell>> edges;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j]=' '){
              V++;
              visited[i][j] = 1;
              if(i>=1 && matrix[i-1][j]==' ') {
                  //TODO: добавить как соседа
              }

              if(i<rows-1 && matrix[i+1][j]==' '){
                  //TODO: добавить как соседа
              }

              if(j>=1 && matrix[i][j-1]==' '){
                  //TODO: добавить как соседа
              }

              if(j<columns-1 && matrix[i][j+1]==' '){
                  //TODO: добавить как соседа
              }

            }
        }
    }
    //не скомпилит , очевидно, сначала обработать , потом создать граф, потом его вернуть
}