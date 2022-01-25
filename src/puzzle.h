#ifndef __PUZZLE_H
#define __PUZZLE_H

#include <string>
using namespace std;

class Puzzle {
    public:
        int rows, cols;
        char ** matrix;


        //constructor
        Puzzle();

        Puzzle(int x, int y);

        // Puzzle(int x, int y, char val);

        //destructor
        ~Puzzle();

        //setter isi Puzzle
        void setElmt(int x, int y, char val);

        void setDefault();

        //getter
        char getElmt(int x, int y);

        //display
        void displayPuzzle();

        void setResult(int frow, int fcol, string found, string w);

};

#endif