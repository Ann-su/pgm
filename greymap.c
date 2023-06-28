#include "greymap.h"

Greymap *new_image(unsigned X, unsigned Y, Pixel m_lvl)
{
    Greymap *new_greymap = (Greymap *) malloc(sizeof(Greymap));
    if (new_greymap == NULL) return NULL;
    new_greymap->width = X;
    new_greymap->height = Y;
    new_greymap->max_pixel_val = m_lvl;
    new_greymap->pixels = (Pixel *) malloc(X * Y * sizeof(Pixel));
    if (new_greymap->pixels == NULL)
    {
        free(new_greymap);
        return NULL;
    }
    return new_greymap;
}

void delete_image(Greymap *greymap)
{
    if (greymap == NULL) return;
    free(greymap->pixels);
    free(greymap);
}

Pixel *new_canvas(Greymap *greymap)
{
    Pixel *old_pixels = greymap->pixels;
    Pixel *new_pixels = (Pixel *) malloc(greymap->max_pixel_val * sizeof(Pixel));
    if (new_pixels == NULL) return NULL;
    greymap->pixels = new_pixels;
    return old_pixels;
}

Pixel *exchange_canvas(Greymap *greymap, Pixel *new_pixels)
{
    Pixel *old_pixels = greymap->pixels;
    greymap->pixels = new_pixels;
    return old_pixels;
}

void set_greyscale(Greymap *greymap, Pixel m_lvl)
{
    for (int i = 0; i < greymap->height * greymap->width; i++)
    {
        greymap->pixels[i] *= greymap->max_pixel_val / m_lvl;
    }
    greymap->max_pixel_val = m_lvl;
}

int check_img(Greymap *greymap, int repair)
{
    for (int i = 0; i < greymap->height * greymap->width; i++)
    {
        if (repair < greymap->max_pixel_val && repair > 0)
            greymap->pixels[i] = repair;
    }
    int max = greymap->pixels[0];
    for (int i = 1; i < greymap->height * greymap->width; i++)
    {
        if (max < greymap->pixels[i])
            max = greymap->pixels[i];
    }
    return max;
}


int put_dot(Greymap *greymap, Punkt *pkt, unsigned char size)
{
    if (pkt->y > greymap->max_pixel_val) return 0;
    if (!size % 2) size += 1;
    int X = pkt->x;
    int Y = pkt->y;
    int changed_pixels = 0;
    int start_point_X = X - size / 2;
    int start_point_Y = Y - size / 2;
    int lvl = pkt->poziom;
    for (int8_t i = start_point_X; i < X + size / 2; i++)
    {
        for (int8_t j = start_point_Y; j < Y + size / 2; j++)
        {
            if (i >= 0 && i <= greymap->width && j >= 0 && j <= greymap->height)
            {
                greymap->pixels[i * greymap->width + j] = lvl;
                changed_pixels++;
            }
        }
    }
    return changed_pixels;
}