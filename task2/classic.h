#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd
{
private:
    char* mySongName;
public:
    Classic();
    Classic(const char*, const char *, const char *, int, double);
    Classic(const Classic&);
    ~Classic();
    Classic & operator=(const Classic & d);
    virtual void Report()const;
};
#endif