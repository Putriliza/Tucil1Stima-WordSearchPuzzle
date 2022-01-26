#ifndef __PUZZLE_H
#define __PUZZLE_H

#include <string>
using namespace std;

class Puzzle {
    public:
        int rows, cols;     // jumlah baris dan kolom efektif
        char ** matrix;     // matrix untuk menyimpan puzzle

        //constructor
        Puzzle();
        Puzzle(int x, int y);

        //setter isi Puzzle
        void setElmt(int x, int y, char val);
        void setDefault();
        void setResult(int frow, int fcol, string found, string w);

        //getter
        char getElmt(int x, int y);

        //display
        void display();
};

#endif