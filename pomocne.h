#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include "definice.h"

void vynuluj(int *pole,int len);
void nahodne (int *pole, int sloupec, int radek);
int nula(int *pole, int len);
int moznytah(int *pole, int sloupec, int radek);
int vyhraj(int *pole, int len);
void kreslitext(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, SDL_Rect rect, char* text);