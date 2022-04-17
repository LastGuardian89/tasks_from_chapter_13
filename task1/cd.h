#ifndef CH_H
#define CH_H

class Cd{
private:
    char performesrs[50];
    char label[20];
    int selection;
    double playtime;
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd(){}
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};
#endif