#ifndef NOTE_H
#define NOTE_H

#include <string>
using namespace std;

class Note
{
public:
    Note(int o, string p);
private:
    int octave;
    string pitch;
};

#else
class Note;
#endif // NOTE_H
