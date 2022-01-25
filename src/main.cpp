#include <iostream>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#include "puzzle.h"
#include "words.h"
#include "search.h"
#include "fileToData.h"
using namespace std;

int main()
{
    Puzzle* puzzle1 = new Puzzle(50,50);
    Words* words1 = new Words(20);
    double durationTotal = 0;
    int countTotal = 0;

    string filename;
    cout << "Masukkan nama file: ";
    cin >> filename;
    filename = "../test/" + filename;
    fileToData(filename, puzzle1, words1);

    for (int i=0; i<words1->total; i++)
    {
        Search* s = new Search();
        string str = words1->getWord(i);

        // auto start = chrono::high_resolution_clock::now();
        chrono::steady_clock sc;
        auto start = sc.now();

        s->find(puzzle1, str);
        // cout << endl << s->frow << " " << s->fcol << " " << s->found;

        auto end = sc.now();
        // auto stop = chrono::high_resolution_clock::now();
        
        // long long duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        auto duration = static_cast<std::chrono::duration<double>>(end-start);

        Puzzle* out = new Puzzle(puzzle1->rows,puzzle1->cols);
        out->setResult(s->frow,s->fcol, s->found, str);
        cout << endl << str << endl;
        out->displayPuzzle();
        cout << "Perbandingan huruf: " << s->count << endl;
        // cout << "Durasi: " << duration.count() << " detik" << endl;

        durationTotal += duration.count();
        countTotal += s->count;
    }

    cout << endl << "Total durasi: " << durationTotal << " detik" << endl;
    cout << "Total perbandingan huruf: " << countTotal << endl;


    string quit;
    cout << "Press anything to exit: ";
    cin >> quit;

    return 0;
}