#include "segment.h"

Segment::Segment(){}

void Segment::setSyllable(string syl)
{
    syllable = syl;
}

void Segment::addNote(Note n)
{
    notes.push_back(n);
}
