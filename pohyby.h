#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "definice.h"

void levo (int *pole, int sloupec, int radek, int* body);
void pravo (int *pole, int sloupec, int radek, int* body);
void dolu (int *pole, int sloupec, int radek, int* body);
void nahoru (int *pole, int sloupec, int radek, int* body);