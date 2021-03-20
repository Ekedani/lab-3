#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Cell{
    int i_coord;
    int j_coord;
    Cell(int i, int j){
        i_coord = i;
        j_coord = j;
    }
};

char** getMatrix(string way_to_file);
int countNumberOfLines(string way_to_file);
int countNumberOfColumns(string way_to_file);



