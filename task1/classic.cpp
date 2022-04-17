#include "classic.h"
#include <iostream>
#include <string>
#include <cstring>

Classic::Classic() : Cd() {
    mySongName = nullptr;
}

Classic::Classic(const char* song, const char * s1, const char * s2, int n , double x) {
    int len = strlen(song);
    mySongName = new char[len + 1];
    strcpy(mySongName, song);
}

Classic::Classic(const Classic & s) :Cd(s) {
    int len = strlen(s.mySongName);
    mySongName = new char[len + 1];
    strcpy(mySongName, s.mySongName);
}

Classic::~Classic() {
    delete[] mySongName;
    mySongName = nullptr;
}

Classic & Classic::operator=(const Classic & d) {
    if (this == &d)
        return *this;
    Cd::operator=(d);
    delete[] mySongName;
    int len = strlen(d.mySongName);
    mySongName = new char[len + 1];
    strcpy(mySongName, d.mySongName);
    return *this;
}

void Classic::Report()const {
    if (mySongName) {
        Cd::Report();
        std::cout << "mySongName: " << mySongName << std::endl;
    }
    else {
        Cd::Report();
        std::cout << "mySongName: no name\n";
    }
}