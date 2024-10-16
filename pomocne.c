#include "pomocne.h"

void vynuluj(int *pole, int len)
{
    for (int i = 0; i < len; i++)
    {
        pole[i] = 0;
    }
}

void nahodne(int *pole, int sloupec, int radek)
{
    int nahx = rand() % sloupec;
    int nahy = rand() % radek;
    while (pole[nahx * sloupec + nahy] != 0)
    {
        nahx = rand() % sloupec;
        nahy = rand() % radek;
    }
    int nahc = rand() % 10 + 1;
    if (nahc < 10)
    {
        pole[nahx * sloupec + nahy] = 2;
    }
    else
    {
        pole[nahx * sloupec + nahy] = 4;
    }
}

int nula(int *pole, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (pole[i] == 0)
        {
            return 1;
        }
    }
    return 0;
}

int moznytah(int *pole, int sloupec, int radek)
{
    int a = pole[0];

    //po radcich

    for (int i = 0; i < radek; i++)
    {
        for (int j = 1; j < sloupec; j++)
        {
            a = pole[i * sloupec + j - 1];
            if (a == pole[sloupec * i + j])
            {
                return 1;
            }
        }
    }

    // po sloupcich

    for (int j = 0; j < sloupec; j++)
    {
        int a = 0;
        for (int i = 1; i < radek; i++)
        {
            if (pole[a * sloupec + j] == pole[i * sloupec + j])
            {
                return 1;
            }
            a++;

        }
    }

    return 0;
}

int vyhraj(int *pole, int len)
{
    for (int i = 1; i < len; i++)
    {
        //vitez
        if (pole[i] == 2048)
        {
            return 1;
        }
    }
    return 0;
}

void kreslitext(SDL_Renderer *renderer, TTF_Font *font, SDL_Color color, SDL_Rect rect, char *text)
{
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, message, NULL, &rect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(message);
    
}