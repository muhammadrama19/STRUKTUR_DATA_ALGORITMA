#ifndef header_H
#define header_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef char infotype;
typedef struct tnode *address;
typedef struct tnode
{
    infotype data;
    address next;
} nodes;

typedef struct
{
    address top;
    address bottom;
} List;

void createList(List *Data);
address Alokasi(infotype X);
bool isEmpty(List Penunjuk);
void push(List *Penunjuk, infotype new_data);
void printAll(List Data);
void pop(List *Penunjuk);
#endif
