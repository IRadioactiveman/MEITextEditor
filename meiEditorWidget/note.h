#ifndef NOTE_H
#define NOTE_H

#include <string>
using namespace std;

class Note
{
public:
    Note();
    Note(string r);
    Note(int o, string p);
    string getPitch();
    string getRelation();
    float currentPosition;

private:
    int octave;
    string pitch;
    string relation;
};

#else
class Note;
#endif // NOTE_H
