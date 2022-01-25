#ifndef __SEARCH_H
#define __SEARCH_H

#include <string>
#include "puzzle.h"
#include "words.h"
using namespace std;

class Search{
    public:
        string found;  //init "none" artinya belum ketemu
        int frow,fcol; //indeks awal ditemukan
        int count;     //jumlah total perbandingan huruf

        //constructor
        Search();

        //destructor
        ~Search();

        void find(Puzzle *p, string w);
        void horizontal_LR(Puzzle *p, string w, int cRow, int cCol);
        void horizontal_RL(Puzzle *p, string w, int cRow, int cCol);
        void vertical_UD(Puzzle *p, string w, int cRow, int cCol);
        void vertical_DU(Puzzle *p, string w, int cRow, int cCol);
        void diagonal_ULDR(Puzzle *p, string w, int cRow, int cCol);
        void diagonal_DRUL(Puzzle *p, string w, int cRow, int cCol);
        void diagonal_URDL(Puzzle *p, string w, int cRow, int cCol);
        void diagonal_DLUR(Puzzle *p, string w, int cRow, int cCol);
};

#endif