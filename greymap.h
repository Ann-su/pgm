#ifndef PGM_GREYMAP_H
#define PGM_GREYMAP_H
#include <stdint.h>
#include "punkty.h"
typedef uint8_t Pixel;
typedef struct
{
    size_t width;
    size_t height;
    Pixel max_pixel_val;
    Pixel* pixels;
}Greymap;

Greymap * new_image( unsigned X, unsigned Y, Pixel m_lvl );
void delete_image( Greymap * );
Pixel * new_canvas( Greymap * );
Pixel * exchange_canvas( Greymap *, Pixel * );
void set_greyscale( Greymap *, Pixel m_lvl );
int check_img( Greymap *, int repair );
int put_dot( Greymap *, Punkt * pkt, unsigned char size );
#endif //PGM_GREYMAP_H
