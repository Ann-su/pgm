#include "pgm_format.h"

int save_greymap(char *fname, Greymap *G)
{
    FILE *file = fopen(fname, "wb");
    if (file == NULL)
    {
        return 0;
    }
    fprintf(file, "P5\n");
    fprintf(file, "%u %u\n", G->width, G->height);
    fprintf(file, "%hhu\n", G->max_pixel_val);
    size_t num_pixels = G->width * G->height;
    if (fwrite(G->pixels, sizeof(unsigned char), num_pixels, file) != num_pixels)
    {
        fclose(file);
        return 0;
    }
    fclose(file);
    printf("Saving successful\n");
    return 1;
}

Greymap *load_greymap(char *fname)
{
    FILE *file = fopen(fname, "rb");
    if (file == NULL)
    {
        return NULL;
    }
    char magic_number[3];
    unsigned width, height;
    unsigned char max_pixel_val;
    if (fscanf(file, "%2s\n", magic_number) != 1 || magic_number[0] != 'P' || magic_number[1] != '5')
    {
        fclose(file);
        return NULL;
    }
    if (fscanf(file, "%u %u\n", &width, &height) != 2)
    {
        fclose(file);
        return NULL;
    }
    if (fscanf(file, "%hhu\n", &max_pixel_val) != 1)
    {
        fclose(file);
        return NULL;
    }
    Greymap *G = (Greymap *) malloc(sizeof(Greymap));
    if (G == NULL)
    {
        fclose(file);
        return NULL;
    }

    G->width = width;
    G->height = height;
    G->max_pixel_val = max_pixel_val;
    size_t num_pixels = width * height;
    G->pixels = (unsigned char *) malloc(sizeof(unsigned char) * num_pixels);
    if (G->pixels == NULL)
    {
        fclose(file);
        free(G);
        return NULL;
    }
    if (fread(G->pixels, sizeof(unsigned char), num_pixels, file) != num_pixels)
    {
        fclose(file);
        free(G->pixels);
        free(G);
        return NULL;
    }
    fclose(file);
    return G;
}

void save_matrix(char* file_name, Greymap *greymap)
{
    FILE *file = fopen(file_name, "wb");
    if (file == NULL)
    {
        printf("Failed opening");
    }
    for(int i = 0; i < greymap->width; i++)
    {
        for (int j = 0; j < greymap->height; j++)
        {
            fprintf(file, "%d ", greymap->pixels[i*greymap->width + j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Saving successful\n");
}


