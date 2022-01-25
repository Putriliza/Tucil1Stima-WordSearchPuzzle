#include <iostream>
#include <stdlib.h>
#include <string>
#include "puzzle.h"
#include <bits/stdc++.h>
using namespace std;

Puzzle::Puzzle()
{
    rows = 0;
    cols = 0;
}

Puzzle::Puzzle(int x, int y)
{
    rows = x;
    cols = y;
    matrix = new char *[rows];
    for (int i=0; i<rows; i++)
    {
        matrix[i] = new char[cols];
    }
}

// Puzzle::Puzzle(int x, int y, char val)
// {
//     rows = x;
//     cols = y;
//     for (int i=0; i<rows; i++)
//     {
//         for (int j=0; j<cols; j++)
//         {
//             setElmt(i,j,val);
//         }
//     }
// }


Puzzle::~Puzzle()
{
    // dealloc();
}

void Puzzle::setElmt(int x, int y, char val)
{
    matrix[x][y] = val;
}

void Puzzle::setDefault()
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            setElmt(i,j,'-');
        }
    }
}

char Puzzle::getElmt(int x, int y)
{
    return matrix[x][y];
}

void Puzzle::displayPuzzle()
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

}

// SET BERDASAR HASIL PENCARIAN
void Puzzle::setResult(int frow, int fcol, string found, string w)
{
    setDefault();
    if (found == "LR") for (int j=fcol; j<fcol+w.length(); j++) setElmt(frow,j,w[j-fcol]);

    // else if (found == "RL") for (int j=fcol; j>fcol-w.length(); j--) setElmt(frow,j,w[fcol-j]);
    else if (found == "RL") for (int j=fcol-w.length()+1; j<fcol+1; j++) setElmt(frow,j,w[fcol-j]);

    else if (found == "UD") for (int i=frow; i<frow+w.length(); i++) setElmt(i,fcol,w[i-frow]);

    // else if (found == "DU") for (int i=frow; i>frow-w.length(); i--) setElmt(i,fcol,w[frow-i]);
    else if (found == "DU") for (int i=frow-w.length()+1; i<frow+1; i++) setElmt(i,fcol,w[frow-i]);

    else if (found == "ULDR") for (int i=frow; i<frow+w.length(); i++) setElmt(i,fcol-frow+i,w[i-frow]);

    // else if (found == "DRUL") for (int i=frow; i>frow-w.length(); i--) setElmt(i,fcol-frow+i,w[frow-i]);
    // else if (found == "DRUL") for (int j=fcol; j>fcol-w.length(); j--) setElmt(frow-fcol+j,j,w[fcol-j]);
    else if (found == "DRUL") for (int j=fcol-w.length()+1; j<fcol+1; j++) setElmt(frow-fcol+j,j,w[fcol-j]);

    else if (found == "URDL") for (int i=frow; i<frow+w.length(); i++) setElmt(i,fcol+frow-i, w[i-frow]);

    // else if (found == "DLUR") for (int i=frow; i>frow-w.length(); i--) setElmt(i,fcol+frow-i,w[frow-i]);
    else if (found == "DLUR") for (int j=fcol; j<fcol+w.length(); j++) setElmt(frow+fcol-j,j,w[j-fcol]);
}
