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
    void addNote(Note n);

private:
    string syllable;
    vector<Note> notes;
};

#else
class Segment;
#endif // SEGMENT_H
