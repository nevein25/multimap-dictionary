#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define MAX 20


typedef int Type;
typedef struct{

    Type key;
    Type value[MAX];
    int sizeValue;
}Dictionary;

typedef Dictionary EntryType;
#endif
