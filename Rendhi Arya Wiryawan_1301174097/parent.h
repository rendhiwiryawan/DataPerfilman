#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

//List Circular single

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define firstP(A) A.firstP
#define nextP(A) A->nextP
#define infoP(A) A->infoP
#define null NULL

struct Film
{
    int kodeFilm;
    string namaFilm;
    string durasi;
    int tahun;
};

typedef Film infotypeP;
typedef struct elmlistP *addressP;

struct elmlistP
{
    infotypeP infoP;
    addressP nextP;
};


struct listP
{
    addressP firstP;
};

addressP alokasiP (infotypeP data);
addressP dealokasiP (listP l, addressP &a);
void create_listP (listP &l);

void insert_firstP (listP &l, addressP a);
void insert_lastP (listP &l, addressP a);
void insert_afterP (listP &l, addressP Prec, addressP a);

void delete_firstP (listP &l, addressP &a);
void delete_lastP (listP &l, addressP &a);
void delete_afterP (listP &l, addressP Prec, addressP &a);

void print_infoP (listP l);

addressP findElmKodeFilm (listP l, int x);
addressP findElmNamaFilm (listP l, string y);
addressP getLastP (listP l);

void menuCari(listP &l);
void editParent (listP &l);
void insertParentSort (listP &l);
void hapusFilm (listP &l);

#endif // PARENT_H_INCLUDED
