#include <iostream>
#include <string>
#include <cstring>
#include "cd.h"

Cd::Cd(const char * s1, const char * s2, int n, double x) : selection (n), playtime(x){
    strcpy(performesrs, s1);
    strcpy(label,s2);
};

Cd::Cd(const Cd & d) : selection(d.selection), playtime(d.playtime){
    strcpy(performesrs, d.performesrs);
    strcpy(label, d.label);
}

Cd::Cd() : selection(0), playtime(0) {
    performesrs[0] = '\0';
    label[0] = '\0';
}

void
Cd::Report() const {
    std::cout << "\nperformers:" << performesrs << ", label: " << label << ", selection: " << selection <<
    ", playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d){
    if (this == &d)
        return *this;
    selection = d.selection;
    playtime = d.playtime;
    strcpy(performesrs, d.performesrs);
    strcpy(label, d.label);
    return *this;
}