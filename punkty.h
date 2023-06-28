#ifndef PGM_PUNKTY_H
#define PGM_PUNKTY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double x;
    double y;
    int poziom;
}Punkt;

typedef struct
{
    size_t ilosc;
    Punkt *pkt;
}Lamana;

Lamana * nowa_lamana( size_t N );
void zwolnij_lamana( Lamana * );
Punkt * nowe_wierzcholki( Lamana * L, size_t N );
Punkt * polaczone_lamane( Lamana * L, Lamana * P, Lamana ** W);
void wielokat_foremny( Lamana * W, Punkt * srodek, double promien, double kat);
void ustaw_poziomy_cykl( Lamana * L, int * p, int dlg );
#endif //PGM_PUNKTY_H
