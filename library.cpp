#include "library.h"

char** getMatrix(string way_to_file){
    ifstream file;
    file.open(way_to_file);

    //Находим размерность матрицы
    int lines = countNumberOfLines(way_to_file);
    int columns = countNumberOfColumns(way_to_file);

    //Создание матрицы-лабиринта
    char **matrix = new char*[lines];
    for(int i = 0; i < lines; i++){
        matrix[i] = new char[columns];
    }

    //Заполнение матрицы, не учитывая пробелы
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns * 2; j++){
            if(j % 2 == 0){
                matrix[lines][columns/2] = file.get();
            }
            else{
                file.get();
            }
        }
    }
    file.close();
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
    file.close();
    return result;
}

int countNumberOfColumns(string way_to_file){
    int result = 0;
    ifstream file;
    file.open(way_to_file);
    char tmp = ' ';

    //Ищем количество символов в строке
    while(tmp != '\n'){
        tmp = ' ';
        tmp = file.get();
        result += 1;
    }

    //Учитываем пробелы в строке
    if(result % 2 == 0){
        result /= 2;
    }
    else{
        result /= 2 + 1;
    }
    file.close();
    return result;
}