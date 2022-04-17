#include "dma.h"
#include <cstring>

AbstractDMA::AbstractDMA(const char * l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
AbstractDMA::AbstractDMA(const AbstractDMA & rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}
AbstractDMA::~AbstractDMA() {
    delete[] label;
}

AbstractDMA & AbstractDMA::operator=(const AbstractDMA & rs) {
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const AbstractDMA & rs) {
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

void AbstractDMA::View() const {
    std::cout << "\nLavel: " << label << ", Rating: " << rating << std::endl;
}


baseDMA::baseDMA(const char * l, int r, int s) :AbstractDMA(l, r), score(s) {}
baseDMA::baseDMA(const baseDMA & rs) : AbstractDMA(rs) {
    score = rs.score;
}

baseDMA & baseDMA::operator=(const baseDMA & rs) {
    if (this == &rs)
        return *this;
    AbstractDMA::operator=(rs);
    score = rs.score;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs) {
    os << (const AbstractDMA &)rs;
    os << rs.score << std::endl;
    return os;
};

void baseDMA::View() const {
    AbstractDMA::View();
    std::cout << "\nScore: " << score << std::endl;
}



lacksDMA::lacksDMA(const char * c, const char * l, int r): AbstractDMA(l, r){
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const AbstractDMA & rs): AbstractDMA(rs){
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA & lacksDMA::operator=(const lacksDMA & rs) {
    if (this == &rs)
        return *this;
    AbstractDMA::operator=(rs);
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
    return *this;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls){
    os << (const AbstractDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

void lacksDMA::View() const {
    AbstractDMA::View();
    std::cout << "\nColor: " << color << std::endl;
}


hasDMA::hasDMA(const char * s, const char * l, int r): AbstractDMA(l, r){
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const AbstractDMA & rs): AbstractDMA(rs){
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs): AbstractDMA(hs){
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA(){
    delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs){
    if (this == &hs)
        return *this;
    AbstractDMA::operator=(hs);
    delete[] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs){
    os << (const AbstractDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

void hasDMA::View() const {
    AbstractDMA::View();
    std::cout << "\nStyle: " << style << std::endl;
}