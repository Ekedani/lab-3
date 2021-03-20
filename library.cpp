#include "library.h"

char** getMatrix(string way_to_file){
    ifstream file;
    file.open(way_to_file);
    int lines = countNumberOfLines(way_to_file);
    int columns = countNumberOfColumns(way_to_file);
    char **matrix = new char*[lines];
    for(int i = 0; i < lines; i++){
        matrix[i] = new char[columns];
    }
    //TODO: написать запись в матрицу каждого второго символа кроме /n
    return matrix;
}

//TODO: проверить не берется ли лишняя строка
int countNumberOfLines(string way_to_file){
    int result = 0;
    ifstream file;
    file.open(way_to_file);
    while(!file.eof()){
        string tmp = "";
        getline(file, tmp);
        result += 1;
    }
    return result;
}

int countNumberOfColumns(string way_to_file){
    int result = 0;
    ifstream file;
    file.open(way_to_file);
    char tmp = ' ';
    while(tmp != '\n'){
        //TODO: переписать с использованием get
        tmp = ' ';
        result += 1;
    }
    result -= 1;
    return result;
}