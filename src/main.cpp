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
        Puzzle* out = new Puzzle(puzzle1->rows,puzzle1->cols);
        chrono::steady_clock sc;
        
        auto start = sc.now();

        // ALGORITMA BRUTEFORCE PENCARIAN KATA
        // menghasilkan indeks ditemukannya huruf pertama kata dan arah
        // yang kemudian akan di set ke matrix hasil
        s->find(puzzle1, str);
        out->setResult(s->frow,s->fcol, s->found, str);
        // cout << endl << s->frow << " " << s->fcol << " " << s->found;

        auto end = sc.now();

        cout << endl << str << endl;
        out->display();
        cout << "Perbandingan huruf: " << s->count << endl;

        auto duration = static_cast<std::chrono::duration<double>>(end-start);
        durationTotal += duration.count();
        countTotal += s->count;
    }

    cout << "\n------------------------------------------------------\n";
    cout << "Total durasi: " << durationTotal << " detik\n";
    cout << "Total perbandingan huruf keseluruhan: " << countTotal << "\n";

    string dummy;
    cout << "\nPress anything to exit (then enter): ";
    cin >> dummy;

    return 0;
}