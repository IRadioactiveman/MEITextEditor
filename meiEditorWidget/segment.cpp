#include "segment.h"
#include <iostream>

Segment::Segment(){}

void Segment::setSyllable(string syl)
{
    syllable = syl;
}

void Segment::addNote(Note *n)
{
    notes.push_back(n);
}

vector<Note*> Segment::getNotes()
{
    return notes;
}

string Segment::getSyllable()
{
    return syllable;
}

int Segment::getLength()
{
    return notes.size();
}
