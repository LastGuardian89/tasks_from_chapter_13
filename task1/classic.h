#ifndef TASK1_CLASSIC_H
#define TASK1_CLASSIC_H
#include "cd.h"

class Classic : public Cd{
private:
    char* mySongName;
public:
    Classic();
    Classic(const char*, const char *, const char *, int, double);
    Classic(const Classic&);
    ~Classic();
    Classic & operator=(const Classic & d);
    virtual void Report() const;
};


#endif //TASK1_CLASSIC_H
