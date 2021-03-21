#include "library.h"

//TODO: добавить проверку на успешность открытия файла
char** getMatrix(string way_to_file){
    ifstream file;
    file.open(way_to_file);
    //Находим размерность матрицы
    int lines = countNumberOfLines(way_to_file);
    cout << "lines:" << lines << endl;
    int columns = countNumberOfColumns(way_to_file);
    cout << "columns:" << columns << endl;

    //Создание матрицы-лабиринта
    char **matrix = new char*[lines];
    for(int i = 0; i < lines; i++){
        matrix[i] = new char[columns];
    }

    //Заполнение матрицы, не учитывая пробелы
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < 2*columns; j++){
            if(j==2*columns-1) {
                char tmp;
                tmp = file.get();
                continue;
            }
            if(j % 2 == 0){
                matrix[i][j/2] = file.get();
            }
            else{
                char tmp;
                tmp = file.get();
            }
        }
    }
    file.close();
    return matrix;
}

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