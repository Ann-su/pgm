#include "punkty.h"
#include <math.h>

Lamana *nowa_lamana( size_t N )
{
    Lamana *new_lamana = (Lamana *) malloc( sizeof( Lamana )); //assign memory for new lamana
    if ( new_lamana == NULL) return NULL;
    new_lamana->ilosc = N; //assign ilosc to N of Lamana
    new_lamana->pkt = (Punkt *) malloc(N * sizeof( Punkt )); //assign memory for array pkt of Lamana
    if (new_lamana->pkt == NULL)
    {
        free( new_lamana );
        return NULL;
    }
    return new_lamana;
}

void zwolnij_lamana( Lamana *lamana )
{
    if ( lamana == NULL) return;
    free( lamana->pkt );
    free( lamana );
}

Punkt *nowe_wierzcholki( Lamana *L, size_t N )
{
    Punkt *new_punkty = (Punkt *) malloc( N * sizeof( Punkt ));
    if ( new_punkty == NULL) return NULL;
    if (L->ilosc < N )
        N = L->ilosc;
    for ( size_t i = 0; i < N; i++ )
    {
        new_punkty[i].x = L->pkt[i].x;
        new_punkty[i].y = L->pkt[i].y;
    }
    free( L->pkt );
    L->ilosc = N;
    L->pkt = new_punkty;
    return L->pkt;
}

Punkt *polaczone_lamane( Lamana *L, Lamana *P, Lamana **W )
{
    (*W)->pkt = (Punkt *) malloc((L->ilosc + P->ilosc) * sizeof( Punkt ));
    if ((*W)->pkt == NULL) return NULL;
    for (int i = 0; i < L->ilosc; i++ )
    {
        (*W)->pkt[i] = L->pkt[i];
    }
    for (int i = 0; i < P->ilosc; i++ )
    {
        (*W)->pkt[L->ilosc + i] = P->pkt[i];
    }
    return (*W)->pkt;
}

void wielokat_foremny( Lamana *W, Punkt *srodek, double promien, double kat )
{
    size_t l_wierzch = W->ilosc;
    double kat_miedzy_wierzch = 2.0 * M_PI / (double) l_wierzch;
    double kat_pocz = kat;
    for ( size_t i = 0; i < l_wierzch; i++ )
    {
        W->pkt[i].x = srodek->x + promien * cos(kat_pocz + (double) i * kat_miedzy_wierzch );
        W->pkt[i].y = srodek->y;
    }
}

void ustaw_poziomy_cykl( Lamana *L, int *p, int dlg )
{
    for (size_t i = 0; i < L->ilosc; i++ )
    {
        L->pkt[i].y = p[i % dlg];
    }
}