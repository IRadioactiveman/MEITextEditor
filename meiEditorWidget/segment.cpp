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

vector<float> Segment::getNoteValues()
{
    vector<float> values;

    for(int i = 0; i < notes.size(); i++)
    {
        if(notes[i]->getPitch().compare("c") == 0)
        {
            values.push_back(-0.2);
        }
        if(notes[i]->getPitch().compare("d") == 0)
        {
            values.push_back(-0.1);
        }
        if(notes[i]->getPitch().compare("e") == 0)
        {
            values.push_back(0.0);
        }
        if(notes[i]->getPitch().compare("f") == 0)
        {
            values.push_back(0.1);
        }
        if(notes[i]->getPitch().compare("g") == 0)
        {
            values.push_back(0.2);
        }
        if(notes[i]->getPitch().compare("a") == 0)
        {
            values.push_back(0.3);
        }
        if(notes[i]->getPitch().compare("h") == 0)
        {
            values.push_back(0.4);
        }
        if(notes[i]->getPitch().compare("undefined") == 0)
        {
            values.push_back(0.5);
        }
    }

    return values;
}

int Segment::getLength()
{
    return notes.size();
}
