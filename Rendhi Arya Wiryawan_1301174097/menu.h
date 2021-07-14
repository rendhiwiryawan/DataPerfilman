#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

void openning();
void closing();
void menuUtama();
void menuFilm(listR &R, listP &P, listC &C);
void menuPemain(listR &R, listP &P, listC &C);
void menuRelasi(listR &R, listP &P, listC &C);

#endif // MENU_H_INCLUDED
