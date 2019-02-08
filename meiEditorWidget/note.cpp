#include "note.h"

Note::Note(int o, string p)
{
    octave = o;
    pitch = p;
}

string Note::getPitch()
{
    return pitch;
}
