#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class AbstractDMA {
private:
    char * label;
    int rating;
public:
    AbstractDMA(const char * l = "null", int r = 0);
    AbstractDMA(const AbstractDMA & rs);
    virtual ~AbstractDMA();
    virtual AbstractDMA & operator=(const AbstractDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const AbstractDMA & rs);
    virtual void View()const = 0;
};


class baseDMA: public AbstractDMA
{
private:
    int score;
public:
    baseDMA(const char * l = "null", int r = 0, int s = 0);
    baseDMA(const baseDMA & rs);
    ~baseDMA() {}
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
    void View()const;
};


class lacksDMA :public AbstractDMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
             int r = 0);
    lacksDMA(const char * c, const AbstractDMA & rs);
    lacksDMA & operator=(const lacksDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
    void View()const;
};


class hasDMA :public AbstractDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
           int r = 0);
    hasDMA(const char * s, const AbstractDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
    void View()const;
};
#endif