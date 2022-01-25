#include <iostream>
#include <stdlib.h>
#include "words.h"
#include <string>
using namespace std;

Words::Words()
{
    total = 0;
}

Words::Words(int new_total)
{
    total = new_total;
    words = new string[total];
}


void Words::setWord(int i, string newWord)
{
    words[i] = newWord;
}

string Words::getWord(int i)
{
    return words[i];
}

void Words::display()
{
    for (int i=0; i<total; i++)
    {
        cout << words[i] << endl;
    }
}