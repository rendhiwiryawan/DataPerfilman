#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

//Double Linked List

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

#define nextC(A) A->nextC
#define prevC(A) A->prevC
#define firstC(A) A.firstC
#define lastC(A) A.lastC
#define infoC(A) A->infoC
#define null NULL

struct aktor
{
    int idAktor,rate;
    string namaAktor;
    char jenisKelamin;
};

typedef aktor infotypeC;
typedef struct elmlistC *addressC;

struct elmlistC
{
    infotypeC infoC;
    addressC nextC;
    addressC prevC;
};

struct listC
{
    addressC firstC;
    addressC lastC;
};

addressC alokasiC(infotypeC x);
void dealokasiC(addressC &P);
void create_listC(listC &L);
void insertChild(listC &L, addressC P);
//void insertlastChild(listC &L, addressC P);
//void insertafterChild(listC &L, adrressC P, addressC Prec );
void delete_firstC(listC &L, addressC &P);
void delete_lastC(listC &L, addressC &P);
void delete_afterC(listC &L, addressC &P);
void deleteChild(listC &L, addressC P);

void viewChild (listC L);

addressC findElmChild(listC L, int x);
addressC findElmNamaAktor(listC L, string y);

void cariChild(listC L);
void menuEditChild(listC &L);
void insertChildFirst(listC &L);
void menuDeleteChild(listC &L);


#endif // CHILD_H_INCLUDED
