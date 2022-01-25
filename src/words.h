#ifndef __WORD_H
#define __WORD_H

#include <string>
using namespace std;

class Words{
    public:
        int total;
        string * words;

        //constructor
        Words();
        Words(int new_total);

        //setter
        void setWord(int i, string newWord);

        //getter
        string getWord(int i);

        //display
        void display();
};

#endif