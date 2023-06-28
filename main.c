#include <stdio.h>
#include "pgm_format.h"

int main()
{
    Greymap *greymap = new_image(200, 300, 255);
    Punkt pkt;
    pkt.x = 20.0;
    pkt.y = 30.0;
    pkt.poziom = 100;

    save_matrix("matrix_1.txt", greymap);
    save_greymap("test100.pgm", greymap);
    return 0;
}
