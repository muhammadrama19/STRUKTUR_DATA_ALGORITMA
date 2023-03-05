#ifndef header_H
#define header_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define Rear(n) (n).front->prev

typedef char infotype;
typedef struct tnode *address;
typedef struct tnode
{
    infotype data;
    address prev;
    address next;
} nodes;

typedef struct
{
    address front;
} List;

infotype scanfChar();
void printDetail(nodes Data);
void caseInsert(List *Data);
void caseDelete(List *Data);
void createList(List *Data);
void printAll(List Data);
void printAllReverse(List Data);
bool isEmpty(List Penunjuk);
address Alokasi(infotype X);
void insert_front(List *Penunjuk, infotype new_data);
// void insert_rear(List *Penunjuk, infotype new_data);
// void insertBetween(List *Penunjuk, infotype prev_data, infotype new_data);
address search(List *Penunjuk, infotype key);
// void delete_front(List *Penunjuk);
void delete_rear(List *Penunjuk);
// void delete_search(List *Penunjuk, infotype key);
infotype getfront(List Penunjuk);
infotype getrear(List Penunjuk);
#endif
