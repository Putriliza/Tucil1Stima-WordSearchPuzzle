#ifndef __SEARCH_H
#define __SEARCH_H

#include <string>
#include "puzzle.h"
#include "words.h"
using namespace std;

class Search{
    public:
        string found;       // "none" jika kata belum ditemukan, indikasi arah jika kata sudah ditemukan
        int frow,fcol;      // indeks penunjuk huruf pertama kata yang ditemukan pada matrix
        int count;          // jumlah total perbandingan huruf untuk pencarian 1 kata pada puzzle

        //constructor
        Search();

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