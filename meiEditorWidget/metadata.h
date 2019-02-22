#ifndef METADATA_H
#define METADATA_H

#include <string>
#include <vector>
using namespace std;

class MetaData
{
public:
    metaData();
    string create();

private:
    string *title;
    string *composer;
    string *availability;
    string *comments;
    vector<string*> authors;

};

#endif // METADATA_H
