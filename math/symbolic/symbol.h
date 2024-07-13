#ifndef SYMBOL_H
#define SYMBOL_H
struct symbol
{

    union
    {
        int i;
        float f;
        char c;
        char *s;
    } val;
};
#endif