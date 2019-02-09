#include "note.h"

Note::Note()
{
    pitch = "undefined";
}

Note::Note(string r)
{
    pitch = "undefined";
    relation = r;
}

Note::Note(int o, string p)
{
    octave = o;
    pitch = p;
}

string Note::getPitch()
{
    return pitch;
}

string Note::getRelation()
{
    return relation;
}
