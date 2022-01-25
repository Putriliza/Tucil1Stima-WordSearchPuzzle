#include <iostream>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#include "fileToData.h"
using namespace std;

void fileToData(string filename, Puzzle *p, Words *w)
{
    ifstream file(filename.c_str());
    string line;
    char letter;
    bool flag = false;
    int rows = 0, cols = 0, nWord=0;
    int i, j=0;
    
    // parsing puzzle baris pertama untuk menemukan banyak kolom
    getline(file, line);
    istringstream strline(line);
    while (strline>>letter)
    {
        p->setElmt(rows, cols, letter);
        cols++;
    }
    rows++;

    // parsing puzzle baris kedua sampai akhir puzzle
    while (!flag) {
        getline(file, line);
        istringstream strline(line);
        rows++;
        while (strline>>letter)
        {
            if (j >= cols) j = 0;
            i = rows-1;
            p->setElmt(i, j, letter);
            j++;
        }
        if (file.peek() == '\n') flag = true;     // parse puzzle done
    }
    
    // untuk ngeskip blank line pemisah puzzle dan words
    getline(file, line);

    // parsing words yang mau dicari
    while (getline(file, line)) {
        // cout << line << endl;
        w->setWord(nWord, line);
        nWord++;
    }

    p->cols = cols;
    p->rows = rows;
    w->total = nWord;
}