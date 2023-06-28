#ifndef PGM_PGM_FORMAT_H
#define PGM_PGM_FORMAT_H
#include "greymap.h"
// zapis P5
// zwraca 0 gdy problem
int save_greymap( char * fname, Greymap * G );

// odczyt P5
// zwraca NULL, gdy problem
Greymap *load_greymap( char * fname );
void save_matrix(char* file_name, Greymap *greymap);
#endif //PGM_PGM_FORMAT_H
