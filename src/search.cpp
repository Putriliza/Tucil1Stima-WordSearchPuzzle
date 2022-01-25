#include <iostream>
#include <stdlib.h>
#include <string>
#include "puzzle.h"
#include "words.h"
#include "search.h"
#include<bits/stdc++.h>
using namespace std;

//constructor
Search::Search()
{
    found = "none";
    count = 0;
}

//destructor
Search::~Search()
{

}

void Search::find(Puzzle *p, string w)
{
    int i=0;
    int j;
    while (found == "none" && i<p->rows)
    {
        j=0;
        while (found == "none" && j<p->cols)
        {
            count++;
            if (p->getElmt(i,j) == w[0])
            {
                horizontal_LR(p, w, i, j);
                horizontal_RL(p, w, i, j);
                vertical_UD(p, w, i, j);
                vertical_DU(p, w, i, j);
                diagonal_ULDR(p, w, i, j);
                diagonal_DRUL(p, w, i, j);
                diagonal_URDL(p, w, i, j);
                diagonal_DLUR(p, w, i, j);
            }
            j++;
        }
        i++;
    }
    frow = i-1;
    fcol = j-1;
}

void Search::horizontal_LR(Puzzle *p, string w, int cRow, int cCol)
{
    if (cCol < p->cols - w.length() + 1)
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow, cCol+k) == w[k])
            {
                if (k==w.length()-1) found = "LR";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::horizontal_RL(Puzzle *p, string w, int cRow, int cCol)
{
    if (cCol >= w.length() - 1)
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow, cCol-k) == w[k])
            {
                if (k==w.length()-1) found = "RL";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::vertical_UD(Puzzle *p, string w, int cRow, int cCol)
{
    if (cRow < p->rows - w.length() + 1)
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow+k, cCol) == w[k])
            {
                if (k==w.length()-1) found = "UD";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::vertical_DU(Puzzle *p, string w, int cRow, int cCol)
{
    if (cRow >= w.length() - 1)
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow-k, cCol) == w[k])
            {
                if (k==w.length()-1) found = "DU";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::diagonal_ULDR(Puzzle *p, string w, int cRow, int cCol)
{
    if ((cCol < p->cols - w.length() + 1) && (cRow < p->rows - w.length() + 1))
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            if (p->getElmt(cRow+k, cCol+k) == w[k])
            {
                count++;
                if (k==w.length()-1) found = "ULDR";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::diagonal_DRUL(Puzzle *p, string w, int cRow, int cCol)
{
    if ((cRow >= w.length() - 1) && (cCol >= w.length() - 1))
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow-k, cCol-k) == w[k])
            {
                if (k==w.length()-1) found = "DRUL";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::diagonal_URDL(Puzzle *p, string w, int cRow, int cCol)
{
    if ((cRow < p->rows - w.length() + 1) && (cCol >= w.length() - 1))
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow+k, cCol-k) == w[k])
            {
                if (k==w.length()-1) found = "URDL";
            }
            else foundtmp =  false;
            k++;
        }
    }
}

void Search::diagonal_DLUR(Puzzle *p, string w, int cRow, int cCol)
{
    if ((cRow >= w.length() - 1) && (cCol < p->cols - w.length() + 1))
    {
        int k=1;
        bool foundtmp = true;
        while (foundtmp && k<w.length())
        {
            count++;
            if (p->getElmt(cRow-k, cCol+k) == w[k])
            {
                if (k==w.length()-1) found = "DLUR";
            }
            else foundtmp =  false;
            k++;
        }
    }
}