#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

//Single linked list

#include <iostream>

#include "parent.h"
#include "child.h"

using namespace std;

#define firstR(A) A.firstR
#define nextR(A) A->nextR
#define parent(A) A->parent
#define child(A) A->child
#define null NULL

typedef struct elmlistR *addressR;

struct elmlistR
{
    addressR nextR;
    addressP parent;
    addressC child;
};

struct listR
{
    addressR firstR;
};

void create_listR(listR &L);
void insert_firstR(listR &L, addressR P);
void insert_lastR(listR &L, addressR P);
void insert_afterR(listR &L, addressR Prec, addressR P);
void delete_firstR(listR &L, addressR &P);
void delete_lastR(listR &L, addressR &P);
void delete_afterR(listR &L, addressR Prec, addressR &P);
void deleteRelasi(listR &L, listP P, listC C);

void deleteParentR (listR &R, listP &P, listC C);
void deltet6eChildR (listR &R, listP P, listC &C);

addressR getLastR (listR L);
bool cekRelasi (listR &R, int x, int y);

addressR alokasiR (addressP P, addressC C);
void dealokasiR (addressR);
addressR findElmR (listR L, addressP P, addressC C);
void tambahRelasi (listR &R, listP P, listC C);

void printPemainR(listR L, listP P, listC C);
void printFilmR (listR L, listP P, listC C);
void goPrint (listR L, listP K, listC M);
void printSemua(listR L,listP P, listC Q, string Film);
void pemainTop(listR, listP P, listC &C);


#endif // RELASI_H_INCLUDED
