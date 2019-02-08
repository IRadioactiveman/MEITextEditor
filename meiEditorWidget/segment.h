#ifndef SEGMENT_H
#define SEGMENT_H

#include <string>
#include <vector>
#include "note.h"
using namespace std;

class Segment
{
public:
    Segment();
    void setSyllable(string syl);
    void addNote(Note *n);
    vector<Note*> getNotes();
    vector<float> getNoteValues();
    int  getLength();

private:
    string syllable;
    vector<Note*> notes;
};

#else
class Segment;
#endif // SEGMENT_H
